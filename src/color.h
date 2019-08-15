#include <stdint.h>

typedef struct Color {
  uint16_t hue;
  uint8_t value;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} Color;

Color color_hue_to_rgb(Color color);
