
#include "arduino/main/arduino.h"
#include "arduino/delay/delay.h"

uint8_t led = 10;

void setup(){
  setPinMode(led, OUTPUT);
}

void loop(){
  digitalWrite(led, 1);
  delay_ms(10000);
  digitalWrite(led, 0);
  delay_ms(10000);
}
