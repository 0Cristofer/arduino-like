/* Header com definições do sonar.
  Autor: Crisofer Oswald e Narcizo Gabriel
  Criado: 15/10/2018
  Modificado: 15/10/2018 */

#include <util/delay.h>

#include "../main/arduino.h"
#include "sonar.h"
#include "../uart/uart.h"

#define read_bit(port, pin) (port&(1<<pin))

void initSonar(sonar_t* sonar, uint8_t trigger, uint8_t echo){
  sonar->trigger = trigger;
  sonar->echo = echo;

  setPinMode(trigger, OUTPUT);
  setPinMode(echo, INPUT);
}

uint16_t readSonar(sonar_t* sonar){
  volatile uint8_t* e_pin;
  uint8_t e_px;

  uint16_t time = 0;

  if(sonar->echo < 8){
    e_pin = &PIND;
    e_px = sonar->echo;
  }
  else if (sonar->echo < 14){
    e_pin = &PINB;
    e_px = sonar->echo - 8;
  }
  else{
    e_pin = &PINC;
    e_px = sonar->echo - 14;
  }

  digitalWrite(sonar->trigger, HIGH);
  _delay_us(20);
  digitalWrite(sonar->trigger, LOW);

  while(!read_bit(*e_pin, e_px));

  while(read_bit(*e_pin, e_px)){
    _delay_us(1);
    time = time + 1;
  }

  _delay_ms(60);

  return ((uint16_t)time/29);
}
