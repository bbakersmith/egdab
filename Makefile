.PHONY: clean, flash

CC=atmel-avr-gcc
MMCU=attiny1606
CFLAGS=-std=c11 -g -Os -mmcu=$(MMCU) -B atpack/gcc/dev/$(MMCU)/ -I atpack/include/ -Wall -Wpedantic -Wdouble-promotion -Wshadow -Wlogical-op -fno-strict-aliasing -fno-strict-overflow -fno-strict-aliasing -fno-strict-overflow

build/main.hex: build/main.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

build/main.elf:
	$(CC) $(CFLAGS) -o $@ src/main.c

clean:
	rm build/* 2>/dev/null || true

flash: build/main.hex
	sudo avrdude -vvv -c atmelice_updi -p $(MMCU) -U flash:w:$<
