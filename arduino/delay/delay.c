/* Header com definições do delay.
   Autor: Crisofer Oswald e Narcizo Gabriel
   Criado: 17/10/2018
   Modificado: 17/10/2018 */

#include <avr/io.h>
#include "delay.h"

void delay_ms(uint16_t delay){
    //delay = delay * 1000;
    /*while(delay){
        asm volatile(
            "ldi  r18, 5;"
        "LB: dec  r18;"
            "brne LB;"
            "nop;"
        );

        delay = delay - 1;
    }*/
    while(delay){
        asm volatile(
            "ldi  r22, 21;"
            "ldi  r23, 199;"
        "L1:"
            "dec  r23;"
            "brne L1;"
            "dec  r22;"
            "brne L1;"
        );

        delay = delay - 1;
    }
}

void delay_us(uint16_t delay){
    while(delay){
        asm volatile(
            "ldi  r18, 5;"
        "LB: dec  r18;"
            "brne LB;"
        );

        delay = delay - 1;
    }
}