/* Header básico para utilização da biblioteca Arduino. Contém definições dos
   pinos e entrada e saída básica.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 05/10/2018
   Modificado: 10/10/2018 */

#ifndef PINS_H
#define PINS_H

#include <avr/io.h>

// Frequência da CPU do atmega328p
#define F_CPU 16000000UL

// Macros para manipulação dos registradores
#define set_as_input(port, pin) (port &= ~(1<<pin))
#define set_as_output(port, pin) (port |= (1<<pin))
#define set_high(port, pin) (port |= (1<<pin))
#define set_low(port, pin) (port &= ~(1<<pin))
#define read_bit(port, pin) (port&(1<<pin))
#define switch_bit(port, pin) (port ^= (1<<pin))

#define PIN_QUANTITY 20 // Quantidade de pinos de entrada no total

// Tipos possíveis para os pinos
#define OUTPUT 0
#define INPUT 1

// Valores de energia possíveis apra os pinos
#define LOW 0
#define HIGH 1

// Função utilizada para inicializações. Deve ser implementada
void setup();

// Função executada enquanto o Arduino estiver em funcionamento. Deve ser implementada
void loop();

// Enum de pinos analógicos
enum{
  A0 = 14, A1, A2, A3, A4, A5
};

// Configura o modo do pino
void setPinMode(uint8_t pin_code, uint8_t mode);

// Lê o valor de um pino e retorna por referência
uint8_t digitalRead(uint8_t pin_code);

// Escreve um valor digital no pino
void digitalWrite(uint8_t pin_code, uint8_t value);

// Inberte o sinal de Output do pino pin_code
void switchDigitalOutput(uint8_t pin_code);

// Configura o resistor pull-up do pino
void setPullUp(uint8_t pin_code);

#endif /* PINS_H */
