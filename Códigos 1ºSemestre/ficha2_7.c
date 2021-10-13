#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    int total;
    printf("Insere um número entre 1 - 10: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:

        int i = 1;
        while (i <= 1)
        {

            total = total + i;
            i = i + 1;
        }
        break;
    case 2:
        int i = 1;
        while (i <= 2)
        {

            total = total + i;
            i = i + 1;
        }
        break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    case 10:
        break;

    default:
        printf("Operador incorreto");
    }

    printf("A soma é: %d", total);

    return 0;
}
