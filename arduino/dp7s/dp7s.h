/* Declarações para utilização de displays de 7 segmentos.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 10/10/2018
   Modificado: 10/17/2018 */

#ifndef DP7S_H
#define DP7S_H

#define DP7S_ANODO 0
#define DP7S_CATODO 1

// Definição da estrutura de um display de 7 segmentos
typedef struct{
  uint8_t a, b, c, d, e, f, g, h;
  uint8_t type;
} dp7s_t;

// Inicializa um display com os pinos dados e o seu tipo (cátodo ou ânodo)
void initDp7s(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e,
              uint8_t f, uint8_t g, uint8_t h, uint8_t type, dp7s_t* dp7s);

// Mostra um número no display
void lightNumber(uint8_t number, dp7s_t* dp7s);

#endif /* DP7S_H */
