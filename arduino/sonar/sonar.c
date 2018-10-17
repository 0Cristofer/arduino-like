/* Definições do sonar.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 15/10/2018
   Modificado: 17/10/2018 */

#include "../main/arduino.h"
#include "sonar.h"

#define read_bit(port, pin) (port&(1<<pin))

void initSonar(sonar_t* sonar, uint8_t trigger, uint8_t echo){
  sonar->trigger = trigger;
  sonar->echo = echo;

  setPinMode(trigger, OUTPUT);
  setPinMode(echo, INPUT);
}

uint16_t readSonar(sonar_t* sonar){
  uint16_t time = 0;

  digitalWrite(sonar->trigger, HIGH);
  delay_us(20);
  digitalWrite(sonar->trigger, LOW);

  if(sonar->echo < 8){
    while(!read_bit(PIND, sonar->echo));

    while(read_bit(PIND, sonar->echo)){
     delay_us(1);
     time = time + 1;
    }
  }
  else if (sonar->echo < 14){
    while(!read_bit(PINB, sonar->echo - 8));

    while(read_bit(PINB, sonar->echo - 8)){
      delay_us(1);
      time = time + 1;
    }
  }
  else{
    while(!read_bit(PINC, sonar->echo - 14));

    while(read_bit(PINC, sonar->echo - 14)){
      delay_us(1);
      time = time + 1;
    }
  }

  delay_ms(60);

  return ((uint16_t)time/29);
}
