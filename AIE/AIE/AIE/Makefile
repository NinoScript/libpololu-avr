DEVICE = atmega328p
MCU = atmega328p
AVRDUDE_DEVICE = m328p

AVRTOOLS=/usr/local/CrossPack-AVR/bin

CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) $(DEVICE_SPECIFIC_CFLAGS) -Os
CPP=$(AVRTOOLS)/avr-g++
CC=$(AVRTOOLS)/avr-gcc
OBJ2HEX=$(AVRTOOLS)/avr-objcopy 
LDFLAGS=-Wl,-gc-sections -lpololu_$(DEVICE) -Wl,-relax

PORT ?= /dev/tty.usbserial-A400BXCX
AVRDUDE=$(AVRTOOLS)/avrdude
TARGET=main
OBJECT_FILES=main.o bargraph.o maze-solve.o follow-segment.o turn.o

all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

%.o: %.cpp
	$(CPP) $(CFLAGS) -c -o $@ $< 

%.obj: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	$(AVRDUDE) -V -p $(AVRDUDE_DEVICE) -c avrisp -P $(PORT) -b 115200 -U flash:w:$(TARGET).hex
