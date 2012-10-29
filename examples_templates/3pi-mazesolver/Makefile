DEVICE ?= atmega328
MCU ?= atmega328
AVRDUDE_DEVICE ?= m328

CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) $(DEVICE_SPECIFIC_CFLAGS) -Os
CC=avr-gcc
OBJ2HEX=avr-objcopy 
LDFLAGS=-Wl,-gc-sections -lpololu_$(DEVICE) -Wl,-relax

PORT ?= /dev/tty.usbserial-A400BXCX
AVRDUDE=avrdude
TARGET=main
OBJECT_FILES=main.o bargraph.o maze-solve.o follow-segment.o turn.o

all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	$(AVRDUDE) -p $(AVRDUDE_DEVICE) -c avrisp -P $(PORT) -b 38400 -U flash:w:$(TARGET).hex
