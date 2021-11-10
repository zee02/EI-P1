#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int binomioDiscriminante(int a, int b, int c);
int numDeZerosReais(int a, int b, int c, float *sol1, float *sol2);
int main()
{
    int a, b, c, numZerosReais, binomio;
    float x1, x2;
    printf("Indique valor de A: ");
    scanf("%d", &a);
    printf("Indique valor de B: ");
    scanf("%d", &b);
    printf("Indique valor de C: ");
    scanf("%d", &c);
    numZerosReais = numDeZerosReais(a, b, c, &x1,&x2);

    if (numZerosReais == 0)
    {
        printf("Não tem soluções reais");
    }
    else
    {
        if (numZerosReais == 1)
        {
            printf("Tem solução real: %.2f", x1);
        }
        else
        {
            binomio = binomioDiscriminante(a, b, c);
            printf("Tem duas soluções reais");
        }
    }
    return 0;
}

int binomioDiscriminante(int a, int b, int c)
{
    int resultado;
    resultado = b * b - 4 * a * c;
    return resultado;
}

int numDeZerosReais(int a, int b, int c, float *sol1, float *sol2)
{
    int binomio, resultado;
    binomio = binomioDiscriminante(a, b, c);

    if (binomio < 0)
    {
        resultado = 0;
    }
    else
    {
        if (binomio == 0)
        {
            *sol1 = binomio = -b / (float)(2 * a);
            resultado = 1;
        }
        else
        {
            *sol1 = -b + sqrt(binomio) / 2 * a;
            *sol2 = -b - sqrt(binomio) / 2 * a;
            resultado = 2;
        }
    }
    return resultado;
}
