NOME = delaytest
LIBS =
ARQUIVO = $(NOME).c
ELF = $(NOME).elf
SAIDA = $(NOME)

all:
	avr-gcc $(ARQUIVO) $(LIBS) -mmcu=atmega328p -DF_CPU=16000000UL -fshort-enums -save-temps -c -o $(ELF)
	#avr-gcc $(ARQUIVO) $(LIBS) -Os -mmcu=atmega328p -DF_CPU=16000000UL -fshort-enums -o $(ELF)
	#avr-objcopy -O ihex -R .eeprom $(ELF) $(SAIDA)

install:
	avrdude -V -p atmega328p -c arduino -P /dev/ttyUSB0 -b 115200 -D -Uflash:w:$(SAIDA):i

clean:
	rm $(ELF)
	rm $(SAIDA)
