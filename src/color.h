#ifndef _COLOR_H_
#define _COLOR_H_

#include <stdint.h>

typedef struct Color {
  uint16_t hue;
  uint8_t value;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} Color;

typedef struct ColorDigit {
  uint8_t intensity;
  uint8_t segments;
} ColorDigit;

// TODO rename red, green, blue > red_digit, green_digit, blue_digit
typedef struct ColorLed {
  Color color;
  ColorDigit red;
  ColorDigit green;
  ColorDigit blue;
} ColorLed;

void color_hue_to_rgb(Color *color);
void color_rgb_to_digit(ColorDigit *digit, uint8_t rgb_value);
void color_hue_to_digits(ColorLed *led);

#endif
