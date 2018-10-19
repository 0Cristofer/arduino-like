#include "arduino/led/led.h"
#include "arduino/main/arduino.h"
#include "arduino/sonar/sonar.h"
#include "uart/uart.h"

uint8_t pin_led = 8;
uint8_t trigger = 11;
uint8_t echo = 12;

sonar_t sonar;


void setup(){
  uart_init();
  setPinAsLed(pin_led);
  initSonar(trigger, echo, &sonar);
}

void loop(){
  while(1){
    // changeStateLed(pin_led);
    // delayMs(5000);
    // blinkTimeLed(pin_led, 500);
    printf("distancia = %d cm\n", readSonar(&sonar));
  }
}
