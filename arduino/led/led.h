/* Declarações para manipulações com leds.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 09/10/2018
   Modificado: 17/10/2018 */

#ifndef LED_H
#define LED_H

#include "../main/arduino.h"

// Configura um pino como led
#define setPinAsLed(pin_code) (setPinMode(pin_code, OUTPUT))

// Altera seu estado para ligado
#define lightLed(pin_code) (digitalWrite(pin_code, HIGH))

// Altera seu estado para desligado
#define turnOffLed(pin_code) (digitalWrite(pin_code, LOW))

// Inverte o estado atual
#define changeStateLed(pin_code) (switchDigitalOutput(pin_code))

// Configura o estado do led
#define setStateLed(pin_code, state) (digitalWrite(pin_code, state))

// Liga o led por um tempo (em ms) e o desliga
void blinkTimeLed(uint8_t pin_code, uint16_t time);

#endif /* LED_H */
