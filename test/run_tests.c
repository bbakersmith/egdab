#include "unity_fixture.h"

static void run_all_tests(void) {
  RUN_TEST_GROUP(color_tests);
  RUN_TEST_GROUP(controller_tests);
  RUN_TEST_GROUP(oscillator_tests);
  RUN_TEST_GROUP(queue_tests);
  RUN_TEST_GROUP(twi_tests);
}

int main(int argc, const char * argv[]) {
  return UnityMain(argc, argv, run_all_tests);
}
