#include "unity.h"
#include "unity_fixture.h"

#include <stdbool.h>

#include "twi.h"

Twi dummy_twi;
uint8_t dummy_twi_addr;
uint8_t dummy_twi_addr_count;
uint8_t dummy_twi_write_data;
uint8_t dummy_twi_write_data_count;
uint8_t dummy_twi_stop_count;

void dummy_twi_addr_fn(uint8_t addr) {
  dummy_twi_addr = addr;
  dummy_twi_addr_count++;
}

void dummy_twi_write_data_fn(uint8_t data) {
  dummy_twi_write_data = data;
  dummy_twi_write_data_count++;
}

void dummy_twi_stop_fn(void) {
  dummy_twi_stop_count++;
}

TEST_GROUP(twi_tests);

TEST_SETUP(twi_tests) {
  dummy_twi_addr_count = 0;
  dummy_twi_write_data_count = 0;
  dummy_twi_stop_count = 0;

  dummy_twi = twi_new(
    &dummy_twi_addr_fn,
    &dummy_twi_write_data_fn,
    &dummy_twi_stop_fn
  );
};

TEST_TEAR_DOWN(twi_tests) {};

TEST(twi_tests, test_twi_new) {
  TEST_ASSERT_EQUAL(true, queue_fifo_is_empty(&dummy_twi.queue));
  TEST_ASSERT_EQUAL(TWI_STATE_IDLE, dummy_twi.state);
}

TEST(twi_tests, test_twi_write_idle) {
  uint8_t address = 111;
  uint8_t data[2] = {12, 34};
  uint8_t count = 2;

  // addr_count, addr, write_data_count, write_data, stop_count
  uint8_t cases[16][5] = {
    {1, address, 0, 0, 0},
    {1, 0, 1, data[0], 0},
    {1, 0, 2, data[1], 0},
    {1, 0, 2, 0, 1},
    {1, 0, 2, 0, 1}
  };

  uint8_t cases_count = 5;

  twi_write(&dummy_twi, address, data, count);

  uint8_t err_msg[50];
  for(uint8_t i = 0; i < cases_count; i++) {
    sprintf(err_msg, "Failed iteration %i", i);
    TEST_ASSERT_EQUAL_MESSAGE(cases[i][0], dummy_twi_addr_count, err_msg);
    TEST_ASSERT_EQUAL_MESSAGE(cases[i][1], dummy_twi_addr, err_msg);
    TEST_ASSERT_EQUAL_MESSAGE(cases[i][2], dummy_twi_write_data_count, err_msg);
    TEST_ASSERT_EQUAL_MESSAGE(cases[i][3], dummy_twi_write_data, err_msg);
    TEST_ASSERT_EQUAL_MESSAGE(cases[i][4], dummy_twi_stop_count, err_msg);

    dummy_twi_addr = 0;
    dummy_twi_write_data = 0;

    if(i < (cases_count - 1)) {
      twi_handle_write_interrupt(&dummy_twi);
    }
  }
}

// queue messages
// if not active
// - write address

// test write interrupt
// with one message
// with multiple messages

TEST_GROUP_RUNNER(twi_tests) {
  RUN_TEST_CASE(twi_tests, test_twi_new);
  RUN_TEST_CASE(twi_tests, test_twi_write_idle);
}
