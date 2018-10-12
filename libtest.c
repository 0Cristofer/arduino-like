#include <stdio.h>
#include <util/delay.h>

#include "arduino/main/arduino.h"
#include "arduino/button/button.h"
#include "arduino/dp7s/dp7s.h"

dp7s_t dp7s;
button_t button;
uint8_t num = 0;

void setup(){
  initButton(4, PRESS_BUTTON, &button);
  init7sDisplay(&dp7s, 6, 7, 8, 9, 10, 11, 12, 13, DP7S_CATODO);
}

void loop(){
  lightNumber(&dp7s, 1);

  /*button.readState(&button);
  if(button.state){
    num = (num + 1) % 16;
  }*/
  while(1);
  _delay_ms(100);
}
