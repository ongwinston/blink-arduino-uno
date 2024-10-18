include filelist.mk

OBJECTS := $(SRC_FILES:.c=.o)

default: led.hex

led.hex: led.bin
	avr-objcopy -O ihex -R .eeprom $< $@

led.bin: $(OBJECTS)
	avr-gcc -mmcu=atmega328p -o $@ $^

%.o: %.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o $@ $<

flash: led.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$<

clean:
	rm -f *.o *.bin *.hex

.PHONY: default flash clean
