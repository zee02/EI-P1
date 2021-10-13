#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1,num2,num3;
    printf("Apresente o primeiro número inteiro: \t");
    scanf("%d", &num1);

    printf("Apresente o segundo número inteiro: \t");
    scanf("%d", &num2);

    printf("Apresente o terceiro número inteiro: \t");
    scanf("%d", &num3);

    if(num1 == num2 || num1 == num3 || num2 == num3) {
        printf("Foram introduzidos números iguais\t");
    }
    else {
        printf("Foram introduzidos números diferentes\t");
    }
    }
