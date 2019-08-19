#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <stdint.h>

#include "color.h"

typedef enum {
  CONTROLLER_INPUT_BTN_0,
  CONTROLLER_INPUT_BTN_1,
  CONTROLLER_INPUT_BTN_2,
  CONTROLLER_INPUT_BTN_3,
  CONTROLLER_INPUT_DIP_0,
  CONTROLLER_INPUT_DIP_1,
  CONTROLLER_INPUT_DIP_2,
  CONTROLLER_INPUT_DIP_3,
  CONTROLLER_INPUT_DIP_4,
  CONTROLLER_INPUT_DIP_5,
  CONTROLLER_INPUT_DIP_6,
  CONTROLLER_INPUT_DIP_7,
  CONTROLLER_INPUT_DIP_8,
  CONTROLLER_INPUT_DIP_9,
  CONTROLLER_INPUT_DIP_10,
  CONTROLLER_INPUT_DIP_11
} ControllerDigitalInput;

typedef enum {
  CONTROLLER_INPUT_HUE_MAX,
  CONTROLLER_INPUT_HUE_MIN,
  CONTROLLER_INPUT_VALUE_MAX,
  CONTROLLER_INPUT_VALUE_MIN,
  CONTROLLER_INPUT_AUDIO,
  CONTROLLER_INPUT_TEMPERATURE,
  CONTROLLER_INPUT_OSCILLATOR
} ControllerAnalogInput;

typedef struct ControllerUiInput {
  uint16_t digital_inputs;
  uint8_t analog_inputs[7];
} ControllerUiInput;

typedef struct ControllerDigit {
  uint8_t intensity;
  uint8_t segments;
} ControllerDigit;

// TODO
// - rename red, green, blue > red_digit, green_digit, blue_digit
// - move to controller
// - add hue and value inputs
typedef struct ControllerLed {
  Color color;
  ControllerDigit red;
  ControllerDigit green;
  ControllerDigit blue;
  uint8_t hue_inputs;
  uint8_t value_inputs;
} ControllerLed;

typedef struct ControllerUiOutput {
  ControllerLed led1;
  ControllerLed led2;
} ControllerUiOutput;

uint8_t controller_apply_range(uint8_t min, uint8_t max, uint8_t value);
void controller_rgb_to_digit(ControllerDigit *digit, uint8_t rgb_value);
void controller_hue_to_digits(ControllerLed *led);
void controller_update_led_output(ControllerUiInput *input, ControllerLed *led);

// TODO
// - map sensors to leds

#endif
