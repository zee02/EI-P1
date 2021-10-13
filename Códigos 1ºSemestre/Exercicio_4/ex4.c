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
    printf("Soma: \t \t %d%s%d%s%5.1f",val1, " + ", val2, " = " ,soma);
    printf("\n");
    sub = (float)val1 - val2;
    printf("Subtração: \t \t  %d%s%d%s%5.1f" ,val1, " - ", val2, " = " ,sub);
    printf("\n");
    mult = (float)val1 * val2;
    printf("Multiplicação: \t \t  %d%s%d%s%5.1f", val1, " * ", val2, " = " ,mult);
    printf("\n");
    div = (float)val1 / val2;
    printf("Divisão: \t \t %d%s%d%s%5.1f", val1, " / ", val2, " = " ,div);
    printf("\n");
    resto = val1 % val2;
    printf("Resto divisao inteira: \t \t %d%s%d%s%5.1f",val1, " % ", val2, " = " ,resto);
    printf("\n");
    return 0;
}