#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num, i, x,num_soma,nums,soma, numero;
    soma = 0;
    i = 1;
    num_soma = 1;
    printf("Insira um número inteiro positivo: \t");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Não pode inserir um número negativo \t");
        return 0;
    }
    else
        for (numero = 0; numero <= num; numero++)
        {
            soma += numero;
        }

    do
    {
        printf("A soma dos números inseridos é: %d\n", soma);
        i++;
    } while (i <= 3);
    return 0;
}
