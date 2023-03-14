#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int operacao, n, k, i;
  double resultado;

  while (operacao != 4)
  {
    printf("\nMENU\n1. P(n) - Permutacao Simples\n2. A(n, k) - Arranjo Simples\n3. C(n, k) - Combinacao Simples\n4. Sair\n");
    scanf("%d", &operacao);
    switch (operacao)
    {
    case 1:
      printf("\nDigite o valor de n: ");
      scanf("%d", &n);
      int permutacao = 1;
      for (i = n; i >= 1; i--)
      {
        permutacao *= i;
      }
      printf("P(%d) = %d\n", n, permutacao);
      break;

    case 2:
      printf("Digite o valor de n: ");
      scanf("%d", &n);
      printf("Digite o valor de k: ");
      scanf("%d", &k);
      int fatorialNA = 1, fatorialDivisor = 1;
      for (i = n; i >= 1; i--)
      {
        fatorialNA *= i;
      }
      for (i = (n - k); i >= 1; i--)
      {
        fatorialDivisor *= i;
      }
      resultado = fatorialNA / (double)fatorialDivisor;
      printf("A(%d, %d) = %.2f\n", n, k, resultado);
      break;

    case 3:
      printf("Digite o valor de n: ");
      scanf("%d", &n);
      printf("Digite o valor de k: ");
      scanf("%d", &k);
      int fatorialNC = 1, fatorialK = 1, fatorialNK = 1;
      for (i = n; i >= 1; i--)
      {
        fatorialNC *= i;
      }
      for (i = k; i >= 1; i--)
      {
        fatorialK *= i;
      }
      for (i = (n - k); i >= 1; i--)
      {
        fatorialNK *= i;
      }
      resultado = fatorialNC / (double)(fatorialK * fatorialNK);
      printf("C(%d, %d) = %.2f\n", n, k, resultado);
      break;

    default:
      printf("Digite um valor no intervalo de [1,4]\n");
    }
  }
}