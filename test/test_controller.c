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

  Case cases[12] = {
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
    {255, 0, 0, 255},
    {0, 15, 15, 0}
  };

  char msg[50];
  for(uint8_t i = 0; i < 12; i++) {
    Case c = cases[i];
    sprintf(msg, "Failed iteration %i", i);
    TEST_ASSERT_EQUAL_MESSAGE(
      c.expected,
      controller_apply_range(c.min, c.max, c.value),
      msg
    );
  }
}

TEST(controller_tests, test_controller_rgb_to_digit) {
  typedef struct Case {
    uint8_t rgb_value;
    uint8_t intensity;
    uint8_t segments;
  } Case;

  Case cases[10] = {
    {255, 255, 255},
    {192, 255, 63},
    {128, 255, 15},
    {64, 255, 3},
    {0, 255, 0}
  };

  char msg[50];
  for(uint8_t i = 0; i < 5; i++) {
    ControllerDigit result;
    controller_rgb_to_digit(&result, cases[i].rgb_value);
    sprintf(msg, "Failed iteration %i", i);
    /* TEST_ASSERT_EQUAL_MESSAGE(cases[i].intensity, result.intensity, msg); */
    TEST_ASSERT_EQUAL_MESSAGE(cases[i].segments, result.segments, msg);
  }
}

TEST(controller_tests, test_controller_rgb_to_digits) {
  ControllerLed dummy_led = {{160}};

  controller_hue_to_digits(&dummy_led);

  TEST_ASSERT_EQUAL(0, dummy_led.red.segments);
  TEST_ASSERT_EQUAL(3, dummy_led.green.segments);
  TEST_ASSERT_EQUAL(255, dummy_led.blue.segments);
}

// TODO need way more of these tests
TEST(controller_tests, test_controller_update_ui_output) {
  ControllerUiInput dummy_input;
  ControllerLed dummy_led;

  dummy_input.analog_inputs[CONTROLLER_INPUT_HUE_MIN] = 0;
  dummy_input.analog_inputs[CONTROLLER_INPUT_HUE_MAX] = 255;
  dummy_input.analog_inputs[CONTROLLER_INPUT_TEMPERATURE] = 32;
  dummy_led.hue_inputs = (1 << CONTROLLER_INPUT_TEMPERATURE);

  controller_update_led_output(&dummy_input, &dummy_led);

  TEST_ASSERT_EQUAL(255, dummy_led.red.segments);
  TEST_ASSERT_EQUAL(31, dummy_led.green.segments);
  TEST_ASSERT_EQUAL(0, dummy_led.blue.segments);
}

TEST_GROUP_RUNNER(controller_tests) {
  RUN_TEST_CASE(controller_tests, test_controller_apply_range);
  RUN_TEST_CASE(controller_tests, test_controller_rgb_to_digit);
  RUN_TEST_CASE(controller_tests, test_controller_rgb_to_digits);
  RUN_TEST_CASE(controller_tests, test_controller_update_ui_output);
}
