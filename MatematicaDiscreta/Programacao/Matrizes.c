// Nicolas Gustavo Magrini Pereira
// Leonardo Morari dos Santos

#include <stdio.h>

void somaMatrizes(int m, int n, int A[][n], int B[][n], int C[][n])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void subtraiMatrizes(int m, int n, int A[][n], int B[][n], int C[][n], int D[][n])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] - B[i][j];
      D[i][j] = B[i][j] - A[i][j];
    }
  }
}

void printaMatriz(int m, int n, int resultado[][n])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", resultado[i][j]);
    }
    printf("\n");
  }
}

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
    printf("Impossível realizar quaisquer tipo de operação entre as matrizes A e B\n\n");
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
      somaMatrizes(Ma, Na, A, B, ResultadoAB);
    }
    else if (op == 2)
    {
      printf("Você escolheu subtração.\n");
      subtraiMatrizes(Ma, Na, A, B, ResultadoAB, ResultadoBA);
    }

    printf("Printando a matriz do resultado de A para B (no caso de soma, B para A é o mesmo resultado): \n");
    printaMatriz(Ma, Na, ResultadoAB);

    if (op == 2)
    {
      printf("-----------------------------------------------------\n");
      printf("Printando a matriz do resultado de B para A: \n");
      printaMatriz(Ma, Na, ResultadoBA);
    }

    printf("-----------------------------------------------------\n");
    printf("Fim do programa\n\n");

    return 0;
  }
}