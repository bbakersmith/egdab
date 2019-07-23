#ifndef _TWI_H_
#define _TWI_H_

#include <stdint.h>

#include "queue.h"

#define TWI_MAX_DATA_COUNT 4
#define TWI_MAX_COUNT 50

typedef enum {
  TWI_MESSAGE_STATE_ADDRESS,
  TWI_MESSAGE_STATE_WRITE,
  TWI_MESSAGE_STATE_STOP
} TwiMessageState;

typedef volatile struct TwiMessage {
  uint8_t addr;
  uint8_t write_count;
  uint8_t write_buff[TWI_MAX_DATA_COUNT];
  TwiMessageState state;
} TwiMessage;

typedef enum {
  TWI_STATE_IDLE,
  TWI_STATE_ACTIVE,
} TwiState;

typedef void (*TwiAddrFn)(uint8_t);
typedef void (*TwiWriteFn)(uint8_t);
typedef void (*TwiStopFn)(void);

typedef struct Twi {
  QueueFifo queue;
  TwiMessage messages[50];
  uint8_t state;
  TwiAddrFn addr_fn;
  TwiWriteFn write_fn;
  TwiStopFn stop_fn;
} Twi;

Twi twi_new(TwiAddrFn addr_fn, TwiWriteFn write_fn, TwiStopFn stop_fn);
void twi_write(Twi *twi, uint8_t addr, uint8_t data[], uint8_t count);
void twi_handle_write_interrupt(Twi *twi);

#endif
