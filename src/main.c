#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

int main() {
  PORTB_DIRSET |= (1 << PIN2);

  uint32_t counter = 0;

  while(true) {
    if(counter == 0) {
      PORTB_OUTTGL = (1 << PIN2);
    }

    if(counter < UINT32_MAX) {
      counter++;
    } else {
      counter = 0;
    }
  }

  return 0;
}
