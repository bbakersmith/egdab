#include "controller.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(controller_tests);

TEST_SETUP(controller_tests) {}

TEST_TEAR_DOWN(controller_tests) {}

TEST(controller_tests, test_controller_apply_range) {
  typedef struct Case {
    uint8_t min;
    uint8_t max;
    uint8_t value;
    uint8_t expected;
  } Case;

  Case cases[11] = {
    {0, 255, 0, 0},
    {0, 255, 255, 254},
    {0, 255, 35, 34},
    {0, 255, 200, 199},
    {100, 200, 128, 150},
    {100, 180, 64, 120},
    {180, 100, 64, 160},
    {200, 100, 128, 150},
    {255, 0, 128, 128},
    {255, 0, 64, 192},
    {255, 0, 0, 255}
  };

  char msg[50];
  for(uint8_t i = 0; i < 11; i++) {
    Case c = cases[i];
    sprintf(msg, "Failed iteration %i", i);
    TEST_ASSERT_EQUAL_MESSAGE(
      c.expected,
      controller_apply_range(c.min, c.max, c.value),
      msg
    );
  }
}

TEST_GROUP_RUNNER(controller_tests) {
  RUN_TEST_CASE(controller_tests, test_controller_apply_range);
}
