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
    
    if(num1+num2 > num3 && num1 + num3 > num2 && num2 + num3 > num1) {
        printf("Os 3 lados formam um triangulo\n");

        if(num1 == num2 && num1 == num3) 
            printf("O triangulo é equilatero\n");
        else 
            if(num1 == num2 || num1 == num3 || num2 == num3)
            printf("O triangulo é isosceles\n");
        else 
            printf("O triangulo é escaleno\n");
        

    }
    else {
        printf("Os 3 lados não formam um triangulo\t");
    }
}