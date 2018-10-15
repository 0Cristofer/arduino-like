/* Header com declarações para a utilização de um componente de ultrassom para
   calcular distância.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 15/10/2018
   Modificado: 15/10/2018 */

typedef struct{
 uint8_t trigger;
 uint8_t echo;
} sonar_t;

void initSonar(sonar_t* sonar, uint8_t trigger, uint8_t echo);

uint16_t readSonar(sonar_t* sonar);
