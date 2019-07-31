/*
 * egdab.c
 *
 * Created: 7/22/2019 8:23:05 PM
 * Author : ben
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

// #define F_CPU 20000000
#include <util/delay.h>

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

int main(void) {
	// TWI setup
	TWI0.MCTRLA = (1 << MCTRLA_RIEN) | (1 << MCTRLA_WIEN) | (1 << MCTRLA_ENABLE);
	TWI0.MBAUD = 0x4B;
	TWI0.MSTATUS = 1;
	
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
	
	_delay_ms(500);
	
	uint8_t debug_data[1] = {
		123
	};
//	egdab_twi_write(CAP1296_ADDR, debug_data, 1);
		
//	_delay_ms(500);
		
	uint8_t data[2];
	
	// shutdown mode, normal with defaults
	data[0] = 0x0C;
	data[1] = 0x01;
	egdab_twi_write(AS1115_ADDR, data, 2);

	// global intensity
	_delay_ms(2);
	data[0] = 0x0A;
	data[1] = 0x0F;
	egdab_twi_write(AS1115_ADDR, data, 2);
	
	// decode mode
	_delay_ms(2);
	data[0] = 0x09;
	data[1] = 0x00;
	egdab_twi_write(AS1115_ADDR, data, 2);
	
	// set led intensity and value
	_delay_ms(2);
	data[0] = 0x10;
	data[1] = 0xFF;
	egdab_twi_write(AS1115_ADDR, data, 2);
	
	_delay_ms(2);
	data[0] = 0x01;
	data[1] = 0xFF;
	egdab_twi_write(AS1115_ADDR, data, 2);	

	_delay_ms(2);
	data[0] = 0x02;
	data[1] = 0xFF;
	egdab_twi_write(AS1115_ADDR, data, 2);
	
	// set 7-seg chars intensity
	_delay_ms(2);
	data[0] = 0x11;
	data[1] = 0xFF;
	egdab_twi_write(AS1115_ADDR, data, 2);
		
	_delay_ms(2);
	data[0] = 0x12;
	data[1] = 0xFF;
	egdab_twi_write(AS1115_ADDR, data, 2);
	
	// set 7-seg chars value
	_delay_ms(2);
	data[0] = 0x04;
	data[1] = 0xFF;
	egdab_twi_write(AS1115_ADDR, data, 2);
	
	_delay_ms(2);
	data[0] = 0x05;
	data[1] = 0xFF;
	egdab_twi_write(AS1115_ADDR, data, 2);
	
	_delay_ms(5000);
	
	// display test
	_delay_ms(2);
	data[0] = 0x0F;
	data[1] = 0x01;
	egdab_twi_write(AS1115_ADDR, data, 2);
	
	while(true) {
		// Do test
		data[0] = 0x0F;
		data[1] = 0x01;
//		egdab_twi_write(AS1115_ADDR, data, 2);

		// PORTB.OUTCLR = (1 << PIN2);
		PORTB.OUTTGL = (1 << PIN3);
		_delay_ms(1000);
		// PORTB.OUTSET = (1 << PIN2);
		PORTB.OUTTGL = (1 << PIN3);
		_delay_ms(1000);
		
		if(egdab_knob_position(4) < 127) {
			PORTB.OUTCLR = (1 << PIN2);
		} else {
			PORTB.OUTSET = (1 << PIN2);
		}

//		if(egdab_knob_position(5) < 127) {
//			PORTB.OUTCLR = (1 << PIN3);
//		} else {
//			PORTB.OUTSET = (1 << PIN3);
//		}
	}

	return 0;
}