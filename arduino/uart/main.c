#include <avr/io.h>
#include "uart.h"

int main(void) {
    int valor;

    uart_init();

    while (1) {
        scanf("%d", &valor);
        printf("Valor digitado: %d\n", valor);
    }

    return 0;
}