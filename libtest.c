#include "arduino/main/arduino.h"
#include "arduino/dp7s/dp7s.h"

dp7s_t dp7s;

void setup(){
  initDp7s(3, 4, 5, 6, 7, 8, 9, 10, DP7S_CATODO, &dp7s);
}

void loop(){
  uint8_t number = 0;

  while(1){
    lightNumber(number % 16, &dp7s);

    number = number + 1;

    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
    delay_us(65000);
  }
}
