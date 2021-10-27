#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int num, soma = 0, conta = 0, media;
    do {
        printf("Insira um valor: ");
        scanf("%d", &num);
        soma += num;
        conta++;
        }
        while(num!=0);
        conta--;

        media = (float)soma / conta;

        printf("A soma dos números inseridos é: %d", soma);
        printf("\nA média dos números inseridos é: %d", media);

        return 0;
    }
