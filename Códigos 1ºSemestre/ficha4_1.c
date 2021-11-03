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
    printf("       OPCOES\n(T)riangulo\n(R)etangulo\n(Q)uadrado\n(C)irculo\n(F)im \nSelecione opcao: _");
    printf("\n\nSelecione opção: ");
    scanf(" %c", &opcao);
    opcao=toupper(opcao);
    return opcao;
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
