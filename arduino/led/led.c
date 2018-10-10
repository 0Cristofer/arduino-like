/* Definições para manipulações com led.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 09/10/2018
   Modificado: 09/10/2018 */

#include <util/delay.h>

#include "led.h"

uint8_t states[20] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW,
                      LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

void lightLed(uint8_t pin_code){
  states[pin_code] = HIGH;

  digitalWrite(pin_code, HIGH);
}

void turnOffLed(uint8_t pin_code){
  states[pin_code] = LOW;

  digitalWrite(pin_code, LOW);
}

void changeStateLed(uint8_t pin_code){
  states[pin_code] = !states[pin_code];

  digitalWrite(pin_code, states[pin_code]);
}

void setStateLed(uint8_t pin_code, uint8_t state){
  states[pin_code] = state;

  digitalWrite(pin_code, state);
}

void blinkTimeLed(uint8_t pin_code, uint8_t time){
  if(states[pin_code])
    digitalWrite(pin_code, LOW);

  digitalWrite(pin_code, HIGH);

  _delay_ms(200); // TODO utilizar delay próprio

  digitalWrite(pin_code, LOW);

  states[pin_code] = LOW;
}
