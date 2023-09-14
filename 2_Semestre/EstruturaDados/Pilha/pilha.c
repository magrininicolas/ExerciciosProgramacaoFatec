#include <stdio.h>

// Consts
enum
{
  NAO_SELECIONADO = 0,
  PUSH,
  POP,
  SAIR,
  TAMANHO = 5,
  FALSE = 0,
  TRUE
};

typedef int BOOLEAN;

// Variáveis
int pilha[TAMANHO];
int posicao = 0;

// Protótipos
int menu();
BOOLEAN push(int valor);
BOOLEAN pop(int *valor);

int main()
{
  int opcao = NAO_SELECIONADO;
  int numero;
  BOOLEAN deuCerto = FALSE;

  while (opcao != SAIR)
  {
    opcao = menu();

    switch (opcao)
    {
    case PUSH:
      printf("Digite um numero: ");
      scanf("%d", &numero);

      deuCerto = push(numero);
      if (!deuCerto)
      {
        printf("Pilha cheia!\n");
      }
      break;
    case POP:
      deuCerto = pop(&numero);
      if (deuCerto)
      {
        printf("O número %d foi retirado da pilha\n", numero);
      }
      else
      {
        printf("Pilha vazia!\n");
      }
      break;
    case SAIR:
      break;
    default:
      printf("Opcao invalida\n");
    }
  }

  return 0;
}

int menu()
{

  int op;

  printf("%d - Push\n", PUSH);
  printf("%d - Pop\n", POP);
  printf("%d - Sair\n", SAIR);
  printf("Digite sua opcao: ");
  scanf("%d", &op);

  return op;
}

BOOLEAN push(int valor)
{

  if (posicao == TAMANHO)
  {
    return FALSE;
  }

  pilha[posicao] = valor;
  posicao++;

  return TRUE;
}

BOOLEAN pop(int *valor)
{

  if (posicao == 0)
  {
    return FALSE;
  }

  posicao--;
  *valor = pilha[posicao];

  return TRUE;
}
