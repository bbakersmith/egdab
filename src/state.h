#include <stdint.h>


typedef struct StateLed {
  uint8_t hue;
  uint8_t value;
} StateLed;

typedef struct StateUiOutput {
  uint8_t digits;
  StateLed leds[2];
} StateUiOutput;
