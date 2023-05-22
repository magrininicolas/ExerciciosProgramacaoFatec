#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int numero, fatorial = 1;

  printf("Digite um numero: ");
  scanf("%d", &numero);

  for (int i = numero; i > 1; i--)
  {
    fatorial *= i;
  }
  printf("Fatorial: %d", fatorial);
}