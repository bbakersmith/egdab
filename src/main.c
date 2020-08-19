/*
 * egdab.c
 *
 * Created: 7/22/2019 8:23:05 PM
 * Author : ben
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

#define F_CPU 3333333UL
#include <util/delay.h>

#include "controller.h"
#include "digit.h"
#include "twi.h"

#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5

#define MCTRLA_ENABLE 0
#define MCTRLA_WIEN 6
#define MCTRLA_RIEN 7

#define MSTATUS_WIF 6

#define AS1115_ADDR 0
#define CAP1296_ADDR 0x50

Twi twi;

void twi_addr_fn(uint8_t addr) {
  TWI0.MADDR = addr;
}

void twi_write_data_fn(uint8_t data) {
  /* while(!(TWI0.MSTATUS & (1 << 6))) {} */
  TWI0.MDATA = data;
}

void twi_stop_fn(void) {
	/* while(!(TWI0.MSTATUS & (1 << 6))) {} */
	TWI0.MCTRLB |= 3;
}

void egdab_twi_write(uint8_t address, uint8_t data[], uint8_t len) {
// TODO
// - load the data in buffer
// - write the address to MADDR
// - wait til write interrupt
// - write data to MDATA
// - wait til write interrupt
// - write data to MDATA
// - when buffer empty, write STOP cmd to MCTRLB

	TWI0.MADDR = address;
	for(uint8_t i = 0; i < len; i++) {
		// Wait until CLKHOLD cleared
		while(!(TWI0.MSTATUS & (1 << 6))) {}
		TWI0.MDATA = data[i];
	}
	while(!(TWI0.MSTATUS & (1 << 6))) {}
	TWI0.MCTRLB |= 3; // STOP command
}

uint8_t egdab_knob_position(uint8_t knob) {
	ADC0.MUXPOS = knob;
	ADC0.COMMAND = 1;
	while(ADC0.COMMAND) {}
	return (uint8_t) ADC0.RES;
}

void as1115_write(uint8_t reg, uint8_t data) {
  PORTB.OUTTGL = (1 << PIN2);
  uint8_t buffer[2];
  buffer[0] = reg;
  buffer[1] = data;
  egdab_twi_write(AS1115_ADDR, buffer, 2);
  /* twi_write(&twi, AS1115_ADDR, buffer, 2); */
}

void write_color1(uint8_t hue) {
  Color color;
  color.hue = hue;
  color_hue_to_rgb(&color);

  uint8_t red = controller_apply_range(0, 15, color.red);
  uint8_t green = controller_apply_range(0, 15, color.green);
  uint8_t blue = controller_apply_range(0, 15, color.blue);

  as1115_write(0x10, (red << 4));
  as1115_write(0x11, (blue << 4) | green);

  if(red == 0) {
    as1115_write(0x02, 0x00);
  } else {
    as1115_write(0x02, 0xFF);
  }

  if(green == 0) {
    as1115_write(0x03, 0x00);
  } else {
    as1115_write(0x03, 0xFF);
  }

  if(blue == 0) {
    as1115_write(0x04, 0x00);
  } else {
    as1115_write(0x04, 0xFF);
  }
}

void write_color2(uint8_t hue) {
  Color color;
  color.hue = hue;
  color_hue_to_rgb(&color);

  uint8_t red = controller_apply_range(0, 15, color.red);
  uint8_t green = controller_apply_range(0, 15, color.green);
  uint8_t blue = controller_apply_range(0, 15, color.blue);

  as1115_write(0x12, (green << 4) | red);
  as1115_write(0x13, (blue << 4));

  if(red == 0) {
    as1115_write(0x05, 0x00);
  } else {
    as1115_write(0x05, 0xFF);
  }

  if(green == 0) {
    as1115_write(0x06, 0x00);
  } else {
    as1115_write(0x06, 0xFF);
  }

  if(blue == 0) {
    as1115_write(0x07, 0x00);
  } else {
    as1115_write(0x07, 0xFF);
  }
}

int main(void) {
  // TODO FIXME still running with default 1/6 prescaler (see F_CPU above)
  // System clock configuration, disable prescaler, 1606 defaults to 20Mhz
  CLKCTRL.MCLKCTRLB = 0;

	// TWI setup
	TWI0.MBAUD = 50;
	TWI0.MSTATUS = 1;
	TWI0.MCTRLA = (1 << MCTRLA_RIEN) | (1 << MCTRLA_WIEN) | (1 << MCTRLA_ENABLE);

  twi = twi_new(
    &twi_addr_fn,
    &twi_write_data_fn,
    &twi_stop_fn
  );

	// Input pin setup
	PORTA.DIRCLR |= (1 << PIN4) | (1 << PIN5);
	PORTA.PIN4CTRL = 4; // disable input buffer
	PORTA.PIN5CTRL = 4; // disable input buffer

	// ADC setup
	ADC0.CTRLA = (1 << 2) | 1; // enable 8bit adc
	ADC0.MUXPOS = 4; // select pin 4

	// Output pin setup
	PORTB.DIRSET |= (1 << PIN2) | (1 << PIN3);
	PORTB.OUTCLR |= (1 << PIN2) | (1 << PIN3);

  sei();

	// shutdown mode, normal with defaults
  as1115_write(0x0C, 0x01);

  // global intensity
  as1115_write(0x10, 0x00);
  as1115_write(0x11, 0x00);
  as1115_write(0x12, 0x00);
  as1115_write(0x13, 0x00);
  as1115_write(0x0A, 0x0F);

	// decode mode
  as1115_write(0x09, 0x00);

	// scan limit
  as1115_write(0x0B, 0xFF);

  for(uint8_t i = 1; i < 9; i++) {
    as1115_write(i, 0x00);
    /* as1115_write(i, 0xFF); */
  }

  // top red x02
  // top green x03
  // top blue x04
  //
  // side red x05
  // side green x06
  // side blue x07

  /* as1115_write(0x07, 0xFF); */

  /* write_color1(255); */

  as1115_write(0x01, DIGIT_0);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_1);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_2);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_3);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_4);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_5);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_6);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_7);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_8);
  _delay_ms(100);
  as1115_write(0x01, DIGIT_9);
  _delay_ms(100);
  as1115_write(0x01, 0);

	while(true) {
    for(uint16_t i = 0; i < 256; i++) {
      write_color1(i);
      write_color2((uint8_t) i / 2);
      _delay_ms(50);
    }
  }

	return 0;
}

ISR(TWI0_TWIM_vect) {
  // TODO handle read interrupt?
  twi_handle_write_interrupt(&twi);
  PORTB.OUTTGL = (1 << PIN3);
}
