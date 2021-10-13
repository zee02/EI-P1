#include <stdio.h>
#include <stdlib.h>

int main() { 
    int valor, desconto1, desconto2, desconto3;

    printf("Insira o valor gasto nas compras: \t");
    scanf("%d", &valor);
    desconto1 = valor - valor * 0.04;
    desconto2 = valor - valor * 0.06;
    desconto3 = valor - valor * 0.08;

    if (valor <= 500){
        printf("Não tem direito a desconto! Irá pagar : %d\t", valor);
    }
    else
        if(valor > 500 && valor <= 1250) {
            printf("Tem um desconto de 4! Irá pagar : %d€\t", desconto1);
        }
            else
                if(valor > 1250 && valor <= 2000) {
                printf("Tem um desconto de 6! Irá pagar : %d€\t", desconto2);
                }
                    else
                        if(valor > 2000) {
                        printf("Tem um desconto de 6! Irá pagar : %d€\t", desconto3);
                        
                        }
}