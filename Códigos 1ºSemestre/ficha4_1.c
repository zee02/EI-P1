#include <stdio.h>
#include <stdlib.h>
#define PI 3, 14, 16
int leNumero();
int areaRetangulo(int, int);
int leDadosRetangulo(int *x);
void leDadosRetangulo2(int *x, int *y);
int main()
{
    int lado1, lado2, raio, area;
    char op;

    do
    {
        op = menu();
    } while (op != 'F');
    return 0;
}

char menu()
{
    char opcao;
    printf("Triangulo (No): ***Circulo (No): **OPCOES(T)riangulo(R)etangulo(Q)uadrado(C)irculo(F)im Selecione opcao: _");
}
int leNumero()
{
    int num;
    do
    {
        printf("Indique comprimento do lado 1: ");
        scanf("%d", &num);

    } while (num <= 0);
    return num;
}

float areaCirculo(int *pi, *r, *r)
{
    float area;
    area = pi * r * r;
    return area;
}

int areaRetangulo()
{
}
