#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int num, i, x, num_soma, nums, soma, numero;
    char letra;
    soma = 0;
    i = 1;
    num_soma = 1;

    printf("(W) Ciclo While\n");
    printf("(D) Ciclo do...While\n");
    printf("(F) Ciclo For\n");
    printf("(S) Sair\n");
    printf("\t\tOpção -> ");
    scanf(" %c", &letra);
    letra = toupper(letra);

    do
    {

        switch (letra)
        {
        case 'W':
            printf("ola");
            break;
        case 'D':
            printf("hey");
            break;
        case 'F':
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
            break;
        case 'S':
            printf("Hell nah");
            break;
            return 0;
        }
    } while (letra != 's' && letra != 'S');
}
