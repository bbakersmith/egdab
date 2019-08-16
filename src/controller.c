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
