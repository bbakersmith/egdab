#include "controller.h"

// TODO remove
#include <stdio.h>

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

// TODO strategy for incorporating digit intensity
// - as1115 provides 16 intensity levels, which we can use to provide more color depth
// - get as close as possible with digits first, rounding up (8 steps)
// - then use intensity to get as close as possible within the remaining range (16 steps)
// * need to be able to see the LEDs to judge if this actually works
void controller_rgb_to_digit(ControllerDigit *digit, uint8_t rgb_value) {
  uint8_t segment_size = 31;
  uint8_t num_off_segments = 8 - (rgb_value / segment_size);
  uint8_t segments = 255 >> num_off_segments;
  digit->segments = segments;
}

void controller_hue_to_digits(ControllerLed *led) {
  color_hue_to_rgb(&led->color);
  controller_rgb_to_digit(&led->red, (led->color).red);
  controller_rgb_to_digit(&led->green, (led->color).green);
  controller_rgb_to_digit(&led->blue, (led->color).blue);
}

// TODO this should really be to update a single LED (or group)
// this would require that an LED struct exists with the hue and value input mapping flags
void controller_update_led_output(
  ControllerUiInput *input,
  ControllerLed *led
) {
  uint8_t hue = 255;
  uint8_t value = 255;

  uint8_t hue_min = input->analog_inputs[CONTROLLER_INPUT_HUE_MIN];
  uint8_t hue_max = input->analog_inputs[CONTROLLER_INPUT_HUE_MAX];

  uint8_t value_min = input->analog_inputs[CONTROLLER_INPUT_VALUE_MIN];
  uint8_t value_max = input->analog_inputs[CONTROLLER_INPUT_VALUE_MAX];

  for(uint8_t i = 0; i < 7; i++) {
    uint8_t analog_input = input->analog_inputs[i];

    if(led->hue_inputs & (1 << i))
      hue = (hue * analog_input) >> 8;

    if(led->value_inputs & (1 << i))
      value = (value * analog_input) >> 8;
  }

  (led->color).hue = controller_apply_range(hue_min, hue_max, hue);
  (led->color).value = controller_apply_range(value_min, value_max, value);

  controller_hue_to_digits(led);
}


// TODO
// - maintain state of sensors
// - maintain state of ui
// - use state of sensors and ui to update leds and digits
// - provide trigger inputs for temporary override of sensors (?)
