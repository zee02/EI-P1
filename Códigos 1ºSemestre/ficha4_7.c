#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float preco_litro(int tipo);
float num_litros(float montante, float preco);
void percurso(int *distancia, float *montante);

int main()
{
    int dist, tip;
    float mont, precoo, preco_consumido;

    percurso(&dist, &mont);

    printf("Indique o tipo de combustível: ");
    scanf("%d", &tip);
    precoo = preco_litro(tip);

    preco_consumido = num_litros(mont,precoo);

    //Fiquei no final C
    printf("Preço por Litro: %.2f\n", precoo);

    printf("Valores lidos: %d e %.1f\n", dist, mont);

    return 0;
}

void percurso(int *distancia, float *montante)
{
    printf("Distância Percorrida em km: ");
    scanf("%d", &*distancia);
    printf("Montante Gasto em euros: ");
    scanf("%f", &*montante);
}

float preco_litro(int tipo)
{
    float preco = -1;
    switch (tipo)
    {
    case 1:
        preco = 1.55;
        break;
    case 2:
        preco = 1.65;
        break;
    case 3:
        preco = 1.80;
        break;
    default:
        return preco;
    }
    return preco;
}

float num_litros(float montante, float preco) {

    float numero_litros;
    numero_litros = montante / preco;

    return numero_litros;
}
