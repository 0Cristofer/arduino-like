NOME = libtest
LIBS = arduino/led/led.c arduino/button/button.c arduino/sonar/sonar.c uart/uart.c
ARQUIVO = $(NOME).c
ELF = $(NOME).elf
SAIDA = $(NOME)

all:
	avr-gcc $(ARQUIVO) $(LIBS) arduino/main/arduino.c -include arduino/main/arduino.h -Os -mmcu=atmega328p -DF_CPU=16000000UL -fshort-enums -o $(ELF)
	avr-objcopy -O ihex -R .eeprom $(ELF) $(SAIDA)

install:
	avrdude -V -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -D -Uflash:w:$(SAIDA):i

clean:
	rm $(ELF)
	rm $(SAIDA)
