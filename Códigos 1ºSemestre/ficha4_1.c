#include <stdio.h>
#include <stdlib.h>
int main()
{
    int lado1, lado2, raio,area;
    char op;
    

    lado1 = leNumero();

    do
    {
        printf("Indique o comprimento do lado 2: ");
        scanf("%d", &lado2);

    } while (lado2 <= 0);

    area = lado1 + lado2;

    printf("Area = $d", area);
    return 0;
}

int leNumero()
{
    int num;
    do
    {
        printf("Indique comprimento do lado 1: ");
        scanf("%d", &num);

    } while (num <= 0);
    return num;
}

float areaCirculo(){
    float area;
    area = pi*r*r;
    return area;

}

int areaRetangulo() {
    
}
