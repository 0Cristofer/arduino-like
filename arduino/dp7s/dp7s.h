#ifndef DP7S_H
#define DP7S_H

#define DP7S_ANODO 0
#define DP7S_CATODO 1

typedef struct{
  uint8_t a, b, c, d, e, f, g, h;
  uint8_t type;
} dp7s_t;

void init7sDisplay(dp7s_t* dp7s, uint8_t a, uint8_t b, uint8_t c, uint8_t d,
                   uint8_t e, uint8_t f, uint8_t g, uint8_t h, uint8_t type);


void lightNumber(dp7s_t* dp7s, uint8_t number);

#endif /* DP7S_H */
