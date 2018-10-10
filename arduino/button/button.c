/* Definições para uso de botões no Arduino.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 09/10/2018
   Modificado: 09/10/2018 */

#include <util/delay.h>

#include "button.h"
#include "../main/arduino.h"

// Lê o estado de um botão de estados. Deve ser executado dentro do loop principal
void readButtonState(button_t* button){
  uint8_t pressed;

  pressed = !digitalRead(button->pin_code);

  if(pressed){
    if(button->last_press_state == button->press_state){
      button->press_state = !button->press_state;

      button->state = !button->state;
    }

    _delay_ms(DEBOUNCE_RATE);
  }
  else{
    button->last_press_state = button->press_state;
    _delay_ms(DEBOUNCE_RATE);
  }
}

// Lê o estado do botão precionável. Deve ser executado dentro do loop principal
void readButtonPress(button_t* button){
  _delay_ms(DEBOUNCE_RATE);

  button->state = !digitalRead(button->pin_code);

  _delay_ms(DEBOUNCE_RATE);
}

void initButton(uint8_t pin_code, uint8_t button_type, button_t* button){
  button->pin_code = pin_code;
  button->button_type = button_type;
  button->state = 0;
  button->press_state = 0;
  button->last_press_state = 0;

  if(button_type == STATE_BUTTON){
    button->readState = &readButtonState;
  }
  else{
    button->readState = &readButtonPress;
  }

  setPinMode(pin_code, INPUT);
  setPullUp(pin_code);
}
