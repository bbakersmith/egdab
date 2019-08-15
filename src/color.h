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

void color_hue_to_rgb(Color *color);
ColorDigit color_rgb_to_digit(uint8_t rgb_value);
