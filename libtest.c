#include <stdio.h>

#include "arduino/sonar/sonar.h"
#include "arduino/uart/uart.h"

uint8_t trigger = 11;
uint8_t echo = 10;

sonar_t sonar;

void setup(){
  uart_init();

  initSonar(&sonar, trigger, echo);
}

void loop(){
  printf("Distance: %d cm\n", readSonar(&sonar));
}
