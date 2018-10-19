#include "arduino/led/led.h"
#include "arduino/button/button.h"

uint8_t pin_led = 8;
uint8_t pin_button = 9;

button_t button;

void setup(){
  setPinAsLed(pin_led);
  initButton(pin_button, PRESS_BUTTON, &button);
}

void loop(){
  while(1){
    button.readState(&button);
    setStateLed(pin_led, button.state);
  }
}
