#include <stdio.h>
#include <stdlib.h>
// Vamos assumir que o preço por quilo do produto XPTO é 20 euros
#define PRECO 20
int main()
{
    int dinheiro;
    float gramas;
    printf("Indique quanto dinheiro tem (em euros): ");
    scanf("%d", &dinheiro);
    gramas = (float)dinheiro / PRECO * 1000;
    printf("\n\nCom %d euros pode comprar %.0f gramas de XPTO a %d euros por quilo", dinheiro, gramas, PRECO);
    return 0;

}
