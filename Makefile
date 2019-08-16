.PHONY: clean, flash, test

CC = atmel-avr-gcc
MMCU = attiny1606
CFLAGS = -std=c11 -g -Os -mmcu=$(MMCU) -B atpack/gcc/dev/$(MMCU)/ -I atpack/include/ -Wall -Wpedantic -Wdouble-promotion -Wshadow -Wlogical-op -fno-strict-aliasing -fno-strict-overflow -fno-strict-aliasing -fno-strict-overflow

TEST_SRC = \
	Unity/src/unity.c \
	Unity/extras/fixture/src/unity_fixture.c \
	src/color.c \
	src/controller.c \
	src/queue.c \
	src/twi.c \
	test/test_color.c \
	test/test_controller.c \
	test/test_queue.c \
	test/test_twi.c \
	test/run_tests.c

build/main.hex: build/main.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

build/main.elf:
	$(CC) $(CFLAGS) -o $@ src/main.c

build/run_tests.o: clean
	gcc -std=c11 -g -Os -Isrc -IUnity/src -IUnity/extras/fixture/src $(TEST_SRC) -o $@

test: build/run_tests.o
	$< -v

clean:
	rm build/* 2>/dev/null || true

flash: build/main.hex
	sudo avrdude -vvv -c atmelice_updi -p $(MMCU) -U flash:w:$<
