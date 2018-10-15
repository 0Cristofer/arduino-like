/* Arquivo contendo a função main para a compilação e funções básicas para
   manipulação de pinos do Arduino.
   Autor: Cristofer Oswald e Narcizo Gabriel
   Criado: 05/10/2018
   Modificado: 09/10/2018 */

#include <avr/pgmspace.h>

#include "arduino.h"

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

// Dados referetes a um pin
typedef struct pin_t{
  volatile uint8_t* ddr;
  volatile uint8_t* port;
  volatile uint8_t* pin;
  uint8_t px;
} pin_t;


// Inicializa a lista de pinos.
const pin_t pin_list[20] PROGMEM = {
                                   {&DDRD, &PORTD, &PIND, PD0},
                                   {&DDRD, &PORTD, &PIND, PD1},
                                   {&DDRD, &PORTD, &PIND, PD2},
                                   {&DDRD, &PORTD, &PIND, PD3},
                                   {&DDRD, &PORTD, &PIND, PD4},
                                   {&DDRD, &PORTD, &PIND, PD5},
                                   {&DDRD, &PORTD, &PIND, PD6},
                                   {&DDRD, &PORTD, &PIND, PD7},
                                   {&DDRB, &PORTB, &PINB, PB0},
                                   {&DDRB, &PORTB, &PINB, PB1},
                                   {&DDRB, &PORTB, &PINB, PB2},
                                   {&DDRB, &PORTB, &PINB, PB3},
                                   {&DDRB, &PORTB, &PINB, PB4},
                                   {&DDRB, &PORTB, &PINB, PB5},
                                   {&DDRC, &PORTC, &PINC, PC0},
                                   {&DDRC, &PORTC, &PINC, PC1},
                                   {&DDRC, &PORTC, &PINC, PC2},
                                   {&DDRC, &PORTC, &PINC, PC3},
                                   {&DDRC, &PORTC, &PINC, PC4},
                                   {&DDRC, &PORTC, &PINC, PC5}
                                  };

void setPinMode(uint8_t pin_code, uint8_t mode){
  if(mode){
    set_as_input(*(uint8_t*)pgm_read_ptr(&pin_list[pin_code].ddr), pgm_read_byte(&pin_list[pin_code].px));
  }
  else{
    set_as_output(*(uint8_t*)pgm_read_ptr(&pin_list[pin_code].ddr),  pgm_read_byte(&pin_list[pin_code].px));
  }
}

uint8_t digitalRead(uint8_t pin_code){
  return read_bit(*(uint8_t*)pgm_read_ptr(&pin_list[pin_code].pin),  pgm_read_byte(&pin_list[pin_code].px));
}

void digitalWrite(uint8_t pin_code, uint8_t value){
  if(value)
    set_high(*(uint8_t*)pgm_read_ptr(&pin_list[pin_code].port),  pgm_read_byte(&pin_list[pin_code].px));
  else
    set_low(*(uint8_t*)pgm_read_ptr(&pin_list[pin_code].port),  pgm_read_byte(&pin_list[pin_code].px));
}

void switchDigitalOutput(uint8_t pin_code){
  switch_bit(*(uint8_t*)pgm_read_ptr(&pin_list[pin_code].port), pgm_read_byte(&pin_list[pin_code].px));
}

void setPullUp(uint8_t pin_code){
  setPinMode(pin_code, INPUT);
  digitalWrite(pin_code, HIGH);
}

// Função main do programa
int main(){
  setup();

  while(1){
    loop();
  }

  return 0;
}
