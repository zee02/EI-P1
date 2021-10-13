#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf("Apresente um número inteiro: \t");
    scanf("%d", &num);

    if(num == 0) {
        printf("O número é nulo\n");
    }
    else{
    if(num >= 0) {
        printf("O número é positivo\n");
    }
    else {
        printf("O número é negativo\n");
    }
    if(num % 2 == 0) {
        printf("O número é par\n");
    }
    else{
        printf("O número é ímpar\n");
    }
    
}
}