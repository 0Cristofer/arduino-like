#include <stdio.h>
#include <util/delay.h>

#include "arduino/main/arduino.h"
#include "arduino/led/led.h"
#include "arduino/button/button.h"

int button_pin = 8;
int led_pin = 9;

button_t button;

void setup(){
  setPinAsLed(led_pin);
  initButton(button_pin, STATE_BUTTON, &button);
}

void loop(){
  while(1){
    button.readState(&button);

    setStateLed(led_pin, button.state);
  }
}
