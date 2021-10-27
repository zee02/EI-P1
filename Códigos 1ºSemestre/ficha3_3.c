#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int num, soma = 0, conta = 0, media, pos_counter = 0, neg_counter = 0;
    float pos_counter_percent, neg_counter_percent;
    do
    {
        printf("Insira um valor: ");
        scanf("%d", &num);
        soma += num;
        conta++;
        printf("teste: %d",conta++);
        if (num > 0)
        {
            pos_counter++;
            pos_counter_percent = (conta*pos_counter)*100;
        }
        if (num < 0) {
        neg_counter++;
        neg_counter_percent = (neg_counter*conta)*100;
        }
    } while (num != 0);
    conta--;

    media = (float)soma / conta;

    printf("A soma dos números inseridos é: %d", soma);
    printf("\n");
    printf("\nA média dos números inseridos é: %d", media);
    printf("\n");
    printf("\nFoi inserida esta quantidade de números positivos: %d", pos_counter);
    printf("\n");
    printf("\nEsta foi a percentagem de números positivos: %f", pos_counter_percent);
    printf("\n");
    printf("\nFoi inserida esta quantidade de números negativos: %d", neg_counter);
    printf("\n");
    printf("\nEsta foi a percentagem de números negativos: %f", neg_counter_percent);
    return 0;
}
