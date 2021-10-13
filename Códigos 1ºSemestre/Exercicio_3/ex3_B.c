#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pi 3,1416

int main()
{
    int peri, area, raio;
    printf("Insira o raio do circulo: \t");
    scanf("%d", &raio);
    area = pi * raio ^ 2;
    peri = 2 * pi * raio;

    printf("A Área do circulo é: %f\t", area,"\n");
    printf("O perimetro do circulo é: %f\t", peri,"\n");


    return 0;
}