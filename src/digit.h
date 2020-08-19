#ifndef _DIGIT_H_
#define _DIGIT_H_

#include <stdint.h>

typedef enum {
  DIGIT_SEGMENT_G,
  DIGIT_SEGMENT_B,
  DIGIT_SEGMENT_C,
  DIGIT_SEGMENT_D,
  DIGIT_SEGMENT_E,
  DIGIT_SEGMENT_F,
  DIGIT_SEGMENT_A,
  DIGIT_SEGMENT_DP
} DigitSegments;

const uint8_t DIGIT_0 =
  (1 << DIGIT_SEGMENT_A)
  | (1 << DIGIT_SEGMENT_B)
  | (1 << DIGIT_SEGMENT_C)
  | (1 << DIGIT_SEGMENT_D)
  | (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_F);

const uint8_t DIGIT_1 =
  (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_F);

const uint8_t DIGIT_2 =
  (1 << DIGIT_SEGMENT_A)
  | (1 << DIGIT_SEGMENT_C)
  | (1 << DIGIT_SEGMENT_D)
  | (1 << DIGIT_SEGMENT_F)
  | (1 << DIGIT_SEGMENT_G);

const uint8_t DIGIT_3 =
  (1 << DIGIT_SEGMENT_A)
  | (1 << DIGIT_SEGMENT_D)
  | (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_F)
  | (1 << DIGIT_SEGMENT_G);

const uint8_t DIGIT_4 =
  (1 << DIGIT_SEGMENT_B)
  | (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_F)
  | (1 << DIGIT_SEGMENT_G);

const uint8_t DIGIT_5 =
  (1 << DIGIT_SEGMENT_A)
  | (1 << DIGIT_SEGMENT_B)
  | (1 << DIGIT_SEGMENT_D)
  | (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_G);

const uint8_t DIGIT_6 =
  (1 << DIGIT_SEGMENT_A)
  | (1 << DIGIT_SEGMENT_B)
  | (1 << DIGIT_SEGMENT_C)
  | (1 << DIGIT_SEGMENT_D)
  | (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_G);

const uint8_t DIGIT_7 =
  (1 << DIGIT_SEGMENT_A)
  | (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_F);

const uint8_t DIGIT_8 =
  (1 << DIGIT_SEGMENT_A)
  | (1 << DIGIT_SEGMENT_B)
  | (1 << DIGIT_SEGMENT_C)
  | (1 << DIGIT_SEGMENT_D)
  | (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_F)
  | (1 << DIGIT_SEGMENT_G);

const uint8_t DIGIT_9 =
  (1 << DIGIT_SEGMENT_A)
  | (1 << DIGIT_SEGMENT_B)
  | (1 << DIGIT_SEGMENT_D)
  | (1 << DIGIT_SEGMENT_E)
  | (1 << DIGIT_SEGMENT_F)
  | (1 << DIGIT_SEGMENT_G);

uint8_t digit_code(uint8_t d) {
  switch(d) {
    case 0:
      return DIGIT_0;
    case 1:
      return DIGIT_1;
    case 2:
      return DIGIT_2;
    case 3:
      return DIGIT_3;
    case 4:
      return DIGIT_4;
    case 5:
      return DIGIT_5;
    case 6:
      return DIGIT_6;
    case 7:
      return DIGIT_7;
    case 8:
      return DIGIT_8;
    case 9:
      return DIGIT_9;
    default:
      return 0;
  }
}

#endif
