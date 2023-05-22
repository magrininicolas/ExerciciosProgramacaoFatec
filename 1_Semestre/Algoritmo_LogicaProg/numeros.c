#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int numero, soma = 0;

  printf("Digite um numero: ");
  scanf("%d", &numero);

  for (int i = (numero - 1); i >= 0; i--)
  {
    printf("%d\n", i);
    soma += i;
  }
  printf("Soma = %d", soma);
}