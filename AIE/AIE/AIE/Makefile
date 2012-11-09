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

# SIMULAVR=$(AVRTOOLS)/simulavr
SIMULAVR=/opt/local/bin/simulavr # v1.0 de Macports

all: $(TARGET).hex $(TARGET).elf

clean:
	rm -f *.hex *.elf *.o

%.hex: %.elf
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

%.o: %.cpp
	$(CPP) $(CFLAGS) -c -o $@ $< 

%.elf: $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

debug: $(TARGET).elf
	$(SIMULAVR) -d atmega328 -f $(TARGET).elf -W 0x20,- -R 0x22,- -T exit # -F 20000000

program: $(TARGET).hex
	$(AVRDUDE) -V -p $(AVRDUDE_DEVICE) -c avrisp -P $(PORT) -b 115200 -U flash:w:$(TARGET).hex
