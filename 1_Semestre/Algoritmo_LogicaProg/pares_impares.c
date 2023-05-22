#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int numero, somaPares = 0, somaImpares = 0;

  for (int i = 1; i <= n; i++)
  {
    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0)
    {
      printf("%d - Par", numero);
      somaPares++;
    }
    if (numero % 2 != 0)
    {
      printf("%d - Impar", numero);
      somaImpares++;
    }
  }
  printf("Qtd par = %d", somaPares);
  printf("Qtd impar = %d", somaImpares);
}