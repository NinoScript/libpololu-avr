DEVICE         = atmega328p
MCU            = atmega328p
AVRDUDE_DEVICE = m328p

PORT ?= /dev/tty.usbserial-A400BXCX

TARGET=MACOSX

ifeq ($(TARGET), AVR)

AVRTOOLS = /usr/local/CrossPack-AVR/bin
AVRBIN   = $(AVRTOOLS)/bin
CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) $(DEVICE_SPECIFIC_CFLAGS) -Os
CC=$(AVRBIN)/avr-gcc
OBJ2HEX=$(AVRBIN)/avr-objcopy
LDFLAGS=-Wl,-gc-sections -lpololu_$(DEVICE) -Wl,-relax

AVRDUDE=$(AVRBIN)/avrdude
HEXFILE=mainavr
OBJECT_FILES=main.o bargraph.o maze-solve.o follow-segment.o turn.o

else

CFLAGS=-g -Wall $(DEVICE_SPECIFIC_CFLAGS) -Os
CC=gcc
OBJ2HEX=echo
LDFLAGS=-Wl,-gc-sections -Wl,-relax

AVRDUDE=echo
HEXFILE=main
OBJECT_FILES=main.o maze-solve.o
endif

all: $(HEXFILE).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(HEXFILE).hex
	$(AVRDUDE) -p $(AVRDUDE_DEVICE) -c avrisp -P $(PORT) -b 38400 -U flash:w:$(TARGET).hex
