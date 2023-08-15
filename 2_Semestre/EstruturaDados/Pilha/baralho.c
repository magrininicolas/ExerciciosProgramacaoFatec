#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { FALSE, TRUE, MAX = 52 };

enum Menu { NAO_SELECIONADO = 0, EMBARALHAR, SORTEAR, SAIR };

enum Naipes { PAUS, OUROS, COPAS, ESPADAS };

typedef int BOOL;

typedef struct {
  int naipe;
  int valor;
} CARTA;

typedef struct {
  CARTA cartas[MAX];
  int topo;
} BARALHO;

CARTA carta;
BARALHO baralho;
int sorteado = 0;

int menu();
void embaralhar();
int geraCartaRand();
BOOL sortear(CARTA *carta);
const char *getNaipe(int naipe);

int main() {

  srand(time(NULL));

  int opcao = NAO_SELECIONADO;

  while (opcao != SAIR) {
    opcao = menu();

    switch (opcao) {
    case EMBARALHAR:
      embaralhar();
      break;

    case SORTEAR:
      if (sortear(&carta)) {
        carta.valor = (carta.valor % 13) + 1;

        const char *naipe = getNaipe(carta.naipe);

        if (carta.valor == 1) {
          printf("\nCarta sorteada: A de %s\n", naipe);
        } else if (carta.valor == 11) {
          printf("\nCarta sorteada: J de %s\n", naipe);
        } else if (carta.valor == 12) {
          printf("\nCarta sorteada: Q de %s\n", naipe);
        } else if (carta.valor == 13) {
          printf("\nCarta sorteada: K de %s\n", naipe);
        } else {
          printf("\nCarta sorteada: %d de %s\n", carta.valor, naipe);
        }
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

int menu() {
  int opcao;
  printf("1 - Embaralhar\n");
  printf("2 - Sortear\n");
  printf("3 - Sair\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);
  return opcao;
}

void embaralhar() {
  baralho.topo = 0;

  while (baralho.topo < (MAX - sorteado)) {
    int valor = geraCartaRand();

    for (int i = 0; i < baralho.topo; i++) {
      if (baralho.cartas[i].valor == valor) {
        valor = geraCartaRand();
        i = -1;
      }
    }

    baralho.cartas[baralho.topo].valor = valor;

    if (baralho.cartas[baralho.topo].valor <= 13) {
      baralho.cartas[baralho.topo].naipe = PAUS;
    } else if (baralho.cartas[baralho.topo].valor <= 26) {
      baralho.cartas[baralho.topo].naipe = OUROS;
    } else if (baralho.cartas[baralho.topo].valor <= 39) {
      baralho.cartas[baralho.topo].naipe = COPAS;
    } else {
      baralho.cartas[baralho.topo].naipe = ESPADAS;
    }

    baralho.topo++;
  }
  printf("\nTopo: %d\n", baralho.topo);
}

int sortear(CARTA *carta) {
  if (baralho.topo == 0) {
    printf("\nBaralho vazio\n");
    return FALSE;
  }

  sorteado++;
  baralho.topo--;
  *carta = baralho.cartas[baralho.topo];
  return TRUE;
}

int geraCartaRand() { return 1 + rand() % 52; }

const char *getNaipe(int naipe) {
  switch (naipe) {
  case PAUS:
    return "Paus";
  case COPAS:
    return "Copas";
  case OUROS:
    return "Ouros";
  case ESPADAS:
    return "Espadas";
  default:
    return "Desconhecido";
  }
}

