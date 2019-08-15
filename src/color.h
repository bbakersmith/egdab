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

typedef struct ColorLed {
  Color color;
  ColorDigit red;
  ColorDigit green;
  ColorDigit blue;
} ColorLed;

void color_hue_to_rgb(Color *color);
void color_rgb_to_digit(ColorDigit *digit, uint8_t rgb_value);
void color_hue_to_digits(ColorLed *led);
