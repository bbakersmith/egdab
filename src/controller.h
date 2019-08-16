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

typedef struct ControllerUiOutput {
  ColorLed led1;
  uint8_t led1_hue_inputs;
  uint8_t led1_value_inputs;
  ColorLed led2;
  uint8_t led2_hue_inputs;
  uint8_t led2_value_inputs;
} ControllerUiOutput;

uint8_t controller_apply_range(uint8_t min, uint8_t max, uint8_t value);
void controller_update_ui_output(
  ControllerUiInput *input,
  ControllerUiOutput *output
);

#endif
