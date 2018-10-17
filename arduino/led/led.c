/* Definições para manipulações com led.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 09/10/2018
   Modificado: 17/10/2018 */

#include "led.h"

void blinkTimeLed(uint8_t pin_code, uint16_t time){
  digitalWrite(pin_code, HIGH);

  delay_ms(time);

  digitalWrite(pin_code, LOW);
}
