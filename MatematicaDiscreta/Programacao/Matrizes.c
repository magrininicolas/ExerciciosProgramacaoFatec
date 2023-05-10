// Nicolas Gustavo Magrini Pereira
// Leonardo Morari dos Santos

#include <stdio.h>

int main()
{
  int Na, Ma, Nb, Mb, comparaMb, comparaNb, op;

  printf("Insira o número de linhas M e colunas N da Matriz A: \n");
  scanf("%d", &Ma);
  scanf("%d", &Na);
  int A[Ma][Na];

  printf("Insira o número de linhas M e colunas N da Matriz B: \n");
  scanf("%d", &Mb);
  scanf("%d", &Nb);
  int B[Mb][Nb];

  comparaMb = Ma + Mb;
  comparaNb = Na + Nb;

  if (comparaMb != (Mb * 2) || comparaNb != (Nb * 2) || Mb != Nb || Ma != Na)
  {
    printf("Impossível realizar quaisquer tipo de operação entre as matrizes A e B");
  }
  else
  {
    printf("Insira os elementos da matriz A: \n");
    for (int i = 0; i < Ma; i++)
    {
      for (int j = 0; j < Na; j++)
      {
        int elem;
        printf("Elemento: [%d, %d]: ", i + 1, j + 1);
        scanf("%d", &elem);
        A[i][j] = elem;
      }
    }

    printf("-----------------------------------------------------\n");

    printf("Insira os elementos da matriz B: \n");
    for (int i = 0; i < Ma; i++)
    {
      for (int j = 0; j < Na; j++)
      {
        int elem;
        printf("Elemento: [%d, %d]: ", i + 1, j + 1);
        scanf("%d", &elem);
        B[i][j] = elem;
      }
    }

    int ResultadoAB[Ma][Na];
    int ResultadoBA[Ma][Na];

    printf("Digite: 1 = Soma, 2 = Subtração.\n");
    scanf("%d", &op);
    while (op != 1 && op != 2)
    {
      printf("Digite: 1 = Soma, 2 = Subtração.\n");
      scanf("%d", &op);
    }

    printf("-----------------------------------------------------\n");

    if (op == 1)
    {
      printf("Você escolheu soma\n");
      for (int i = 0; i < Ma; i++)
      {
        for (int j = 0; j < Na; j++)
        {
          ResultadoAB[i][j] = A[i][j] + B[i][j];
        }
      }
    }
    else if (op == 2)
    {
      printf("Você escolheu subtração.\n");
      for (int i = 0; i < Ma; i++)
      {
        for (int j = 0; j < Na; j++)
        {
          ResultadoAB[i][j] = A[i][j] - B[i][j];
          ResultadoBA[i][j] = B[i][j] - A[i][j];
        }
      }
    }

    printf("Printando a matriz do resultado de A para B (no caso de soma, B para A é o mesmo resultado): \n");
    for (int i = 0; i < Ma; i++)
    {
      for (int j = 0; j < Na; j++)
      {
        printf("Elemento [%d, %d]: %d\n", i + 1, j + 1, ResultadoAB[i][j]);
      }
    }

    if (op == 2)
    {
      printf("-----------------------------------------------------\n");
      printf("Printando a matriz do resultado de B para A: \n");
      for (int i = 0; i < Ma; i++)
      {
        for (int j = 0; j < Na; j++)
        {
          printf("Elemento [%d, %d]: %d\n", i + 1, j + 1, ResultadoBA[i][j]);
        }
      }
    }

    printf("-----------------------------------------------------\n");
    printf("Fim do programa\n");

    return 0;
  }
}