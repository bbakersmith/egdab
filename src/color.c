#include "color.h"

void color_hue_to_rgb(Color *color) {
  uint16_t hue = color->hue;
  uint16_t saturation = 255;
  uint16_t value = 255;

  uint8_t region = color->hue / 43;

  uint8_t p = 0;
  uint8_t t = (hue - (region * 43)) * 6;
  uint8_t q = (value * (255 - ((saturation * t) >> 8))) >> 8;

  switch(region) {
    case 0:
      color->red = value;
      color->green = t;
      color->blue = p;
      break;
    case 1:
      color->red = q;
      color->green = value;
      color->blue = p;
      break;
    case 2:
      color->red = p;
      color->green = value;
      color->blue = t;
      break;
    case 3:
      color->red = p;
      color->green = q;
      color->blue = value;
      break;
    case 4:
      color->red = t;
      color->green = p;
      color->blue = value;
      break;
    default:
      color->red = value;
      color->green = p;
      color->blue = q;
  }
}

// TODO strategy for incorporating digit intensity
// - as1115 provides 16 intensity levels, which we can use to provide more color depth
// - get as close as possible with digits first, rounding up (8 steps)
// - then use intensity to get as close as possible within the remaining range (16 steps)
// * need to be able to see the LEDs to judge if this actually works
void color_rgb_to_digit(ColorDigit *digit, uint8_t rgb_value) {
  uint8_t segment_size = 31;
  uint8_t num_off_segments = 8 - (rgb_value / segment_size);
  uint8_t segments = 255 >> num_off_segments;
  digit->segments = segments;
}

void color_hue_to_digits(ColorLed *led) {
  color_hue_to_rgb(&led->color);
  color_rgb_to_digit(&led->red, led->color.red);
  color_rgb_to_digit(&led->green, led->color.green);
  color_rgb_to_digit(&led->blue, led->color.blue);
}
