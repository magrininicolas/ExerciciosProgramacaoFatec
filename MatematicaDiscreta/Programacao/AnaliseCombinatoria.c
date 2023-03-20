#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int operacao, n, k, i, fatorialN = 1, fatorialK = 1, fatorialNK = 1;;
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
      fatorialN = 1;
      for (i = n; i >= 1; i--)
      {
        fatorialN *= i;
      }
      printf("P(%d) = %d\n", n, fatorialN);
      break;

    case 2:
      printf("Digite o valor de n: ");
      scanf("%d", &n);
      printf("Digite o valor de k: ");
      scanf("%d", &k);
      if (k > n)
      {
        printf("O valor de N deve ser maior que de K.");
      }
      else
      {
        fatorialN = 1, fatorialNK = 1;
        for (i = n; i >= 1; i--)
        {
          fatorialN *= i;
        }
        for (i = (n - k); i >= 1; i--)
        {
          fatorialNK *= i;
        }
        resultado = fatorialN / (double)fatorialNK;
        printf("A(%d, %d) = %.2f\n", n, k, resultado);
      }
      break;

    case 3:
      printf("Digite o valor de n: ");
      scanf("%d", &n);
      printf("Digite o valor de k: ");
      scanf("%d", &k);
      if (k > n)
      {
        printf("O valor de N deve ser maior que de K.");
      }
      else
      {
        fatorialN = 1, fatorialK = 1, fatorialNK = 1;
        for (i = n; i >= 1; i--)
        {
          fatorialN *= i;
        }
        for (i = k; i >= 1; i--)
        {
          fatorialK *= i;
        }
        for (i = (n - k); i >= 1; i--)
        {
          fatorialNK *= i;
        }
        resultado = fatorialN / (double)(fatorialK * fatorialNK);
        printf("C(%d, %d) = %.2f\n", n, k, resultado);
      }
      break;

    case 4:
      printf("Voce saiu do programa. Obrigado por utilizar.\n");
      break;

    default:
      printf("Digite um valor no intervalo de [1,4]\n");
    }
  }
}