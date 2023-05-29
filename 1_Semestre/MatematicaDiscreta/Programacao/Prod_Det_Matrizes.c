// Nicolas Gustavo Magrini Pereira
// Leonardo Morari dos Santos

#include <stdio.h>

int calculaDeterminante(int n, int matriz[n][n]){
  if(n == 1){
    return matriz[0][0];
  } else if (n == 2) {
    return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
  } else {
    int det = 0;
    for(int i = 0; i < n; i++) {
      if(matriz[0][i] != 0) {
        int aux[n - 1][n - 1];
        int auxJ = 0;
        int auxK = 0;
        for(int j = 1; j < n; j++) {
          auxJ = 0;
          for(int k = 0; k < n; k++){
            if(k != i){
              aux[auxJ][auxK] = matriz[j][k];
              auxK++;
            }
          }
          auxJ++;
        }
        int cofator = (i % 2 == 0) ? matriz[0][i] : -matriz[0][i];
        det += cofator * calculaDeterminante(n - 1, aux);
      }
    }
    return det;
  }
}


int main(void) {

  int m, p, n, aux;

  printf("Insira um valor para M: ");
  scanf("%d", &m);
  printf("Insira um valor para P: ");
  scanf("%d", &p);
  printf("Insira um valor para N: ");
  scanf("%d", &n);

  int A[m][p], B[p][n], R[m][n];

  printf("Insira os valores da matriz A: ");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      printf("\nInsira o valor do elemento [%d][%d]: ", i + 1, j + 1);
      scanf("%d", &A[i][j]);
    }
  }

  printf("---------------------------------------------------------------------------------------\n");

  printf("Insira os valores da matriz B: ");
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < n; j++) {
      printf("\nInsira o valor do elemento [%d][%d]: ", i + 1, j + 1);
      scanf("%d", &B[i][j]);
    }
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      aux = 0;
      R[i][j] = 0;
      for(int k = 0; k < p; k++){
        aux += A[i][k] * B[k][j];
      }
      R[i][j] = aux;
    }
  }
  
  printf("---------------------------------------------------------------------------------------\n");

  printf("Imprimindo o resultado da multiplicacao entre as matrizes A e B: \n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", R[i][j]);
    }
    printf("\n");
  }

  printf("---------------------------------------------------------------------------------------\n");

  if(m == n) {
    printf("Calculando o determinante da matriz R: \n");
    printf("Determinante: %d", calculaDeterminante(n, R));
  } else {
    printf("Não é possível realizar o cálculo do determinante pois a matriz R não é quadrada.");
  }
}