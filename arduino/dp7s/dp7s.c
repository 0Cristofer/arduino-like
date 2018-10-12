#include <avr/io.h>
#include <util/delay.h>

#include "../main/arduino.h"
#include "dp7s.h"

void init7sDisplay(dp7s_t* dp7s, uint8_t a, uint8_t b, uint8_t c, uint8_t d,
                   uint8_t e, uint8_t f, uint8_t g, uint8_t h, uint8_t type){
  setPinMode(a, OUTPUT);
  setPinMode(b, OUTPUT);
  setPinMode(c, OUTPUT);
  setPinMode(d, OUTPUT);
  setPinMode(e, OUTPUT);
  setPinMode(f, OUTPUT);
  setPinMode(g, OUTPUT);
  setPinMode(h, OUTPUT);

  dp7s->a = a; dp7s->b = b; dp7s->c = c; dp7s->d = d;
  dp7s->e = e; dp7s->f = f; dp7s->g = g; dp7s->h = h;
  dp7s->type = type;

  digitalWrite(dp7s->h, !dp7s->type); // Desliga o ponto
}

void lightAll(dp7s_t* dp7s){
  digitalWrite(dp7s->a, dp7s->type);
  digitalWrite(dp7s->b, dp7s->type);
  digitalWrite(dp7s->c, dp7s->type);
  digitalWrite(dp7s->d, dp7s->type);
  digitalWrite(dp7s->e, dp7s->type);
  digitalWrite(dp7s->f, dp7s->type);
  digitalWrite(dp7s->g, dp7s->type);
}

void lightNumber(dp7s_t* dp7s, uint8_t number){
  switch(number){
    case 0:
      lightAll(dp7s);
      digitalWrite(dp7s->g, !dp7s->type);
      break;
    case 1:
      lightAll(dp7s);
      digitalWrite(dp7s->a, !dp7s->type);
      digitalWrite(dp7s->d, !dp7s->type);
      digitalWrite(dp7s->e, !dp7s->type);
      digitalWrite(dp7s->f, !dp7s->type);
      digitalWrite(dp7s->g, !dp7s->type);
      digitalWrite(dp7s->h, !dp7s->type);
      break;
    case 2:
      lightAll(dp7s);
      digitalWrite(dp7s->c, !dp7s->type);
      digitalWrite(dp7s->f, !dp7s->type);
      break;
    case 3:
      lightAll(dp7s);
      digitalWrite(dp7s->e, !dp7s->type);
      digitalWrite(dp7s->f, !dp7s->type);
      break;
    case 4:
      lightAll(dp7s);
      digitalWrite(dp7s->a, !dp7s->type);
      digitalWrite(dp7s->d, !dp7s->type);
      digitalWrite(dp7s->e, !dp7s->type);
      break;
    case 5:
      lightAll(dp7s);
      digitalWrite(dp7s->b, !dp7s->type);
      digitalWrite(dp7s->e, !dp7s->type);
      break;
    case 6:
      lightAll(dp7s);
      digitalWrite(dp7s->b, !dp7s->type);
      break;
    case 7:
      lightAll(dp7s);
      digitalWrite(dp7s->d, !dp7s->type);
      digitalWrite(dp7s->e, !dp7s->type);
      digitalWrite(dp7s->f, !dp7s->type);
      digitalWrite(dp7s->g, !dp7s->type);
      break;
    case 8:
      lightAll(dp7s);
      break;
    case 9:
      lightAll(dp7s);
      digitalWrite(dp7s->e, !dp7s->type);
      break;
    case 10:
      lightAll(dp7s);
      digitalWrite(dp7s->d, !dp7s->type);
      break;
    case 11:
      lightAll(dp7s);
      digitalWrite(dp7s->a, !dp7s->type);
      digitalWrite(dp7s->b, !dp7s->type);
      break;
    case 12:
      lightAll(dp7s);
      digitalWrite(dp7s->b, !dp7s->type);
      digitalWrite(dp7s->c, !dp7s->type);
      digitalWrite(dp7s->g, !dp7s->type);
      break;
    case 13:
      lightAll(dp7s);
      digitalWrite(dp7s->a, !dp7s->type);
      digitalWrite(dp7s->f, !dp7s->type);
      break;
    case 14:
      lightAll(dp7s);
      digitalWrite(dp7s->b, !dp7s->type);
      digitalWrite(dp7s->c, !dp7s->type);
      break;
    case 15:
      lightAll(dp7s);
      digitalWrite(dp7s->b, !dp7s->type);
      digitalWrite(dp7s->c, !dp7s->type);
      digitalWrite(dp7s->d, !dp7s->type);
      break;
  }
}
