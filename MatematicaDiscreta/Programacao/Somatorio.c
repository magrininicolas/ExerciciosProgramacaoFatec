// Leonardo Morari dos Santos
// Nicolas Gustavo Magrini Pereira

#include <stdio.h>  
#include <math.h>  

float calculaAproxPI(int n) {
  float pi_soma = 0;
  for(int i = 0; i <= n; i++){
    pi_soma += 8.0/((4 * i + 1) * (4 * i + 3));
  }
  return pi_soma;
}

float calculaErroAbs(float pi) {
  return fabs(M_PI - pi);
}

int main(void) {
  float pi_soma = 0, erro;
  int n;

  printf("Insira o valor desejado para N: ");
  scanf("%d", &n);

  pi_soma = calculaAproxPI(n);

  erro = calculaErroAbs(pi_soma);

  printf("O valor aproximado de pi foi: %.6f\n", pi_soma);
  printf("O erro absoluto em relação ao valor correto foi: %.6f\n", erro);
  
}