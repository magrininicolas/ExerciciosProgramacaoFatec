// Leonardo Morari dos Santos
// Nicolas Gustavo Magrini Pereira

#include <stdio.h>  
#include <math.h>  

int main(void) {
  float pi_soma = 0, erro;
  int n;

  printf("Insira o valor desejado para N: ");
  scanf("%d", &n);

  for(int i = 0; i <= n; i++){
    pi_soma += 8.0/((4 * i + 1) * (4 * i + 3));
  }
  
  erro = fabs(M_PI - pi_soma);

  printf("O valor aproximado de pi foi: %.6f\n", pi_soma);
  printf("O erro absoluto em relação ao valor correto foi: %.6f\n", erro);
  
}