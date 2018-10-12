/* Definições para manipulações com led.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 09/10/2018
   Modificado: 10/10/2018 */

#include <util/delay.h>

#include "led.h"

void blinkTimeLed(uint8_t pin_code, uint8_t time){
  digitalWrite(pin_code, HIGH);

  _delay_ms(200); // TODO utilizar delay próprio

  digitalWrite(pin_code, LOW);

}
