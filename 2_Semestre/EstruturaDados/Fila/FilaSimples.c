#include <stdio.h>

enum {

  NAO_SELECIONADO,
  ADD,
  REMOVE,
  EXIT

} menuOptions;

enum {
  MAX_SIZE = 5,
};

enum { FALSE, TRUE } bool;

int queue[MAX_SIZE];
int queueEnd = 0;
int queueStart = 0;

typedef int BOOLEAN;

int menu();
BOOLEAN addItem(int value);
BOOLEAN removeItem(int *value);
int seekItem();

int main() {
  int op = NAO_SELECIONADO;
  int number = 0;
  BOOLEAN ok = -1;

  while (op != EXIT) {
    op = menu();

    switch (op) {
    case ADD:
      printf("Digite um numero: ");
      scanf("%d", &number);

      ok = addItem(number);
      if (!ok) {
        printf("Não foi possível adicionar na fila\n");
      }
      break;

    case REMOVE:
      ok = removeItem(&number);
      if (!ok) {
        printf("Não foi possível remover\n");
      } else {
        printf("O número %d foi retirado da fila\n", number);
      }
      break;

    case EXIT:
      break;

    default:
      printf("Opção inválida");
    }
    if (queueStart != queueEnd) {
      printf("Proximo da fila: %d\n", seekItem());
    }
  }

  return 0;
}

int menu() {
  int op;

  printf("%d - ADD\n", ADD);
  printf("%d - REMOVE\n", REMOVE);
  printf("%d - EXIT\n", EXIT);
  printf("Digite uma opção: ");
  scanf("%d", &op);

  return op;
}

BOOLEAN addItem(int value) {
  if (queueEnd == MAX_SIZE) {
    return FALSE;
  }

  queue[queueEnd] = value;
  queueEnd++;

  return TRUE;
}

BOOLEAN removeItem(int *value) {
  if (queueStart == queueEnd) {
    return FALSE;
  }

  *value = queue[queueStart];
  queueStart++;

  return TRUE;
}

int seekItem() { return queue[queueStart]; }
