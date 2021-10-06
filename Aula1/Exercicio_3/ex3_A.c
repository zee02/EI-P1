#include <stdio.h>
#include <stdlib.h>

int main() {
    int valor, valor_total, multiplicador;
    multiplicador = 2;
    printf("Apresente um valor inteiro: \t");
    scanf("%d", &valor);
    valor_total = valor * multiplicador;
    printf("O dobro do valor apresentado é: %d", valor_total);
    return 0;
}