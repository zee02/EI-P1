#include <stdio.h>
#include <stdlib.h>
int main() {
  char operador;
  int num1, num2;
  printf("Insere um operador (+, -, *, /): ");
  scanf("%c", &operador);
  printf("Insere o 1º número: ");
  scanf("%d", &num1);
  printf("Insere o 2º número: ");
  scanf("%d", &num2);

  switch (operador) {
    case '+':
      printf("%d + %d = %.d", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%d - %d = %d", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%d * %d = %d", num1, num2, num1 * num2);
      break;
    case 'x':
      printf("%d * %d = %d", num1, num2, num1 * num2);
      break;
      
    case '/':
      if(num1 != 0 && num2 != 0) {
        printf("%d / %d = %d", num1, num2, num1 / num2);
      }
      else 
      printf("Erro - divisão por zero\t");
      break;
    case '%':
      if(num1 != 0 && num2 != 0) {
        printf("%d / %d = %d", num1, num2, num1 % num2);
      }
      else 
      printf("Erro - divisão por zero\t");
      break;

    default:
      printf("Operador incorreto");
  }

  return 0;
}