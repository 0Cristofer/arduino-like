/* Header básico para utilização da biblioteca Arduino. Contém definições dos
   pinos de entrada e saída básica e delays de ms e us.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 05/10/2018
   Modificado: 17/10/2018 */

#ifndef PINS_H
#define PINS_H

#include <avr/io.h>

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

// Lê o valor de um pino e o retorna
uint8_t digitalRead(uint8_t pin_code);

// Escreve um valor digital no pino
void digitalWrite(uint8_t pin_code, uint8_t value);

// Inverte o sinal digital de saída do pino
void switchDigitalOutput(uint8_t pin_code);

// Configura o resistor pull-up do pino
void setPullUp(uint8_t pin_code);

// Realiza um delay na execução de aproximadamente 1 milissegundo
void delay_ms(uint16_t delay);

// Realiza um delay na execução de aproximadamente 1 microssegundo
void delay_us(uint16_t delay);

#endif /* PINS_H */
