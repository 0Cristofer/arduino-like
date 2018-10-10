/* Declarações para uso de botões no Arduino.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 09/10/2018
   Modificado: 09/10/2018 */

#ifndef BUTTON_H
#define BUTTON_H

#include "../main/arduino.h"

#define DEBOUNCE_RATE 30

#define PRESS_BUTTON 0
#define STATE_BUTTON 1

// Definição de um botão
typedef struct button_t{
  uint8_t pin_code;
  uint8_t button_type;
  uint8_t state;
  uint8_t press_state;
  uint8_t last_press_state;
  void (*readState) (struct button_t*);
} button_t;

// Inicializa um botão com as configurações dadas e reinicia os dados dele
void initButton(uint8_t pin_code, uint8_t button_type, button_t* button);

#endif /* BUTTON_H */
