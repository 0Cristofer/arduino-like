/* Declarações para a utilização de um componente de ultrassom para
   calcular distância.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 15/10/2018
   Modificado: 15/10/2018 */

// Definição da estrutura de um sonar
typedef struct{
 uint8_t trigger;
 uint8_t echo;
} sonar_t;

// Inicializa a estrutura do sonar, configurando o trigger e echo
void initSonar(uint8_t trigger, uint8_t echo, sonar_t* sonar);

// Lê os dados do sonar, calcula a distância do objeto em frente e a retorna
uint16_t readSonar(sonar_t* sonar);
