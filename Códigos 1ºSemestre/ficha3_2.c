#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int num, i, cicle_counter_while,cicle_counter_dowhile,cicle_counter_for, num_soma, nums, soma, numero;
    char letra;
    cicle_counter_while = 0;
    cicle_counter_for = 0;
    cicle_counter_dowhile = 0;
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
                cicle_counter_while++;
            } while (i <= 3);

            break;
        case 'D':
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
                cicle_counter_dowhile++;
            } while (i <= 3);
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
                cicle_counter_for++;
            } while (i <= 3);
            break;
        default:
            printf("Estas foram as estatisticas do programa: \n");
            printf("Ciclos While: %d\n", cicle_counter_while);
            printf("Ciclos do...While: %d\n", cicle_counter_dowhile);
            printf("Ciclos for: %d\n", cicle_counter_for);
            return 0;
        }
    } while (letra != 's' && letra != 'S');
}
