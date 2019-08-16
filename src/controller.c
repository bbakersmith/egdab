#include "controller.h"

uint8_t controller_apply_range(uint8_t min, uint8_t max, uint8_t value) {
  if(min < max) {
    uint16_t length = max - min;
    uint8_t sub_length = ((value * length) >> 8);
    return sub_length + min;
  } else if(max < min) {
    uint16_t length = min - max;
    uint8_t sub_length = ((value * length) >> 8);
    return min - sub_length;
  } else {
    return min;
  }
}

// TODO this should really be to update a single LED (or group)
// this would require that an LED struct exists with the hue and value input mapping flags
void controller_update_ui_output(
  ControllerUiInput *input,
  ControllerUiOutput *output
) {
  uint8_t led1_hue = 255;
  uint8_t led2_hue = 255;

  uint8_t led1_value = 255;
  uint8_t led2_value = 255;

  uint8_t hue_min = input->analog_inputs[CONTROLLER_INPUT_HUE_MIN];
  uint8_t hue_max = input->analog_inputs[CONTROLLER_INPUT_HUE_MAX];

  uint8_t value_min = input->analog_inputs[CONTROLLER_INPUT_VALUE_MIN];
  uint8_t value_max = input->analog_inputs[CONTROLLER_INPUT_VALUE_MAX];

  printf("\nLED1 inputs: %i\n", output->led1_hue_inputs);
  printf("LED2 inputs: %i\n", output->led2_hue_inputs);

  for(uint8_t i = 0; i < 7; i++) {
    uint8_t analog_input = input->analog_inputs[i];

    if(output->led1_hue_inputs & (1 << i))
      led1_hue = (led1_hue * analog_input) >> 8;

    if(output->led2_hue_inputs & (1 << i))
      led2_hue = (led2_hue * analog_input) >> 8;

    if(output->led1_value_inputs & (1 << i))
      led1_value = (led1_value * analog_input) >> 8;

    if(output->led2_value_inputs & (1 << i))
      led2_value = (led2_value * analog_input) >> 8;
  }

  (output->led1).color.hue = controller_apply_range(hue_min, hue_max, led1_hue);
  (output->led1).color.value = controller_apply_range(value_min, value_max, led1_value);

  (output->led2).color.hue = controller_apply_range(hue_min, hue_max, led2_hue);
  (output->led2).color.value = controller_apply_range(value_min, value_max, led2_value);

  color_hue_to_digits(&output->led1);
  color_hue_to_digits(&output->led2);
}
