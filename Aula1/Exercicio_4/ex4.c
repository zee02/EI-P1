#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int val1, val2;
    float soma, sub, mult, div, resto;
    printf("Insira o primeiro número inteiro: \t");
    scanf("%d", &val1);

    printf("Insira o segundo número inteiro: \t");
    scanf("%d", &val2);

    printf("\n");
    printf("\n");
    soma = val1 + val2; 
    printf("Soma: %s%s%d%s%d%s%5.1f","\t", "\t",val1, " + ", val2, " = " ,soma);
    printf("\n");
    sub = (float)val1 - val2;
    printf("Subtração: %s%s%d%s%d%s%5.1f", "\t", "\t",val1, " - ", val2, " = " ,sub);
    printf("\n");
    mult = (float)val1 * val2;
    printf("Multiplicação: %s%s%d%s%d%s%5.1f", "\t", "\t", val1, " * ", val2, " = " ,mult);
    printf("\n");
    div = (float)val1 / val2;
    printf("Divisão: %s%s%d%s%d%s%5.1f", "\t", "\t", val1, " / ", val2, " = " ,div);
    printf("\n");
    resto = val1 % val2;
    printf("Resto divisao inteira: %s%s%d%s%d%s%5.1f", "\t", "\t",val1, " % ", val2, " = " ,resto);
    printf("\n");

    return 0;
}