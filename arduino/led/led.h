/* Declarações para manipulações com leds. Deve ser utilizado com arduino.h
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 09/10/2018
   Modificado: 09/10/2018 */

#ifndef LED_H
#define LED_H

#include "../main/arduino.h"

#define setPinAsLed(pin_code) (setPinMode(pin_code, OUTPUT)) // Configura um pino como led
void lightLed(uint8_t pin_code); // Altera seu estado para ligado
void turnOffLed(uint8_t pin_code); // Altera seu estado para desligado
void changeStateLed(uint8_t pin_code); // Inverte o estado atual
void setStateLed(uint8_t pin_code, uint8_t state); // Configura o estado do led
void blinkTimeLed(uint8_t pin_code, uint8_t time); // Liga o led por um tempo (em ms) e o desliga

#endif /* LED_H */
