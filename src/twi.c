#include <stdio.h>

#include "twi.h"

Twi twi_new(TwiAddrFn addr_fn, TwiWriteFn write_fn, TwiStopFn stop_fn) {
  Twi twi = {
    .queue = queue_fifo_new(TWI_MAX_COUNT),
    .addr_fn = addr_fn,
    .write_fn = write_fn,
    .stop_fn = stop_fn,
    .state = TWI_STATE_IDLE
  };
  return twi;
}

void twi_write(Twi *twi, uint8_t addr, uint8_t data[TWI_MAX_DATA_COUNT], uint8_t count) {
  TwiMessage msg;
  msg.addr = addr;
  msg.write_count = count;

  for(uint8_t i = 0; i < count; i++) {
    msg.write_buff[count - i - 1] = data[i];
  }

  uint8_t index = queue_fifo_push(&twi->queue);
  twi->messages[index] = msg;

  if(twi->state == TWI_STATE_IDLE) {
    twi_handle_write_interrupt(twi);
  }
}

void twi_handle_write_interrupt(Twi *twi) {
  if(queue_fifo_is_empty(&twi->queue)) return;

  uint8_t index = queue_fifo_peek(&twi->queue);
  TwiMessage *msg = &twi->messages[index];

  switch(msg->state) {
    case TWI_MESSAGE_STATE_ADDRESS:
      twi->addr_fn(msg->addr);
      msg->state++;
      break;
    case TWI_MESSAGE_STATE_WRITE:
      if(msg->write_count) {
        msg->write_count--;
        twi->write_fn(msg->write_buff[msg->write_count]);
        break;
      } else {
        msg->state++;
      }
    default:
      twi->stop_fn();
      queue_fifo_pop(&twi->queue);
      break;
  }
}
