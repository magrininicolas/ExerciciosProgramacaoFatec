#include <stdio.h>
#include <stdlib.h>

void main()
{
  int valor_Digitado, p, q;

  printf("Menu:\n 1.~p\n 2.p^q (p e q)\n 3.pvq: (p ou q)\n 4.p_vq:(ou p ou q)\n 5.p->q:(se p, entao q)\n 6.p<->q:(p se, e somente se, q)\n ");
  printf("Digite o valor referente ao que vc quer do menu acima: ");
  scanf("%d", &valor_Digitado);
  printf("Digite um valor para p: (0-Falso/1-Verdadeiro): ");
  scanf("%d", &p);
  printf("Digite um valor para q: (0-Falso/1-Verdadeiro): ");
  scanf("%d", &q);

  switch (valor_Digitado)
  {
  case 1:
    printf("Opcao Escolhida 1: (Negativa de P)\n");
    p == 0 ? printf("Negativa: Verdadeiro") : printf("Falso");
    break;

  case 2:
    printf("Opcao Escolhida 2: (P e Q)\n");
    p != q || (p == 0 && q == 0) ? printf("Valor_Logico: 0-Falso") : printf("Valor_Logico: 1-Verdadeiro");
    break;

  case 3:
    printf("Opcao Escolhida 3: (P ou Q)\n");
    (p == 0 && q == 0) ? printf("Valor_Logico: 0-Falso") : printf("Valor_Logico: 1-Verdadeiro");
    break;

  case 4:
    printf("Opcao Escolhida 4: (ou P ou Q)\n");
    p != q ? printf("Valor_Logico: 1-Verdadeiro") : printf("Valor_Logico: 0-Falso");
    break;

  case 5:
    printf("Opcao Escolhida 5: (se P, entao Q)\n");
    (p == 1 && q == 0) ? printf("Valor_Logico: 0-Falso") : printf("Valor_Logico: 1-Verdadeiro");
    break;

  case 6:
    printf("Opcao Escolhida 6: (P se, e somente se, Q)\n");
    p == q ? printf("Valor_Logico: 1-Verdadeiro") : printf("Valor_Logico: 0-Falso");
    break;
  }
  return 0;
}