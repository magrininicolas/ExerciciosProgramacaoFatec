#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
  NAO_SELECIONADO = 0,
  EMBARALHAR,
  SORTEAR,
  SAIR,
  MAX = 52,
  FALSE = 0,
  TRUE,
  PAUS = 1,
  OUROS,
  COPAS,
  ESPADAS
};

typedef int BOOL;

typedef struct {
  int naipe;
  int valor;
} CARTA;

typedef struct {
  CARTA cartas[MAX];
  int topo;
} BARALHO;

BARALHO baralho;
int sorteado = 0;

int menu();
void embaralhar();
int geraCartaRand();
BOOL sortear(CARTA *carta);

int main() {
  int opcao = NAO_SELECIONADO;
  CARTA carta;

  while (opcao != SAIR) {
    opcao = menu();

    switch (opcao) {
      case EMBARALHAR:
        embaralhar();
        break;

      case SORTEAR:
        if (sortear(&carta)) {
          carta.valor = carta.valor % 13 + 1;

          if (carta.valor == 1) {
            printf("Carta sorteada: A de %s\n",
              carta.naipe == PAUS ? "Paus" : carta.naipe == OUROS ? "Ouros" : carta.naipe == COPAS ? "Copas" : "Espadas");
          } else if (carta.valor == 11) {
            printf("Carta sorteada: J de %s\n",
              carta.naipe == PAUS ? "Paus" : carta.naipe == OUROS ? "Ouros" : carta.naipe == COPAS ? "Copas" : "Espadas");
          } else if (carta.valor == 12) {
            printf("Carta sorteada: Q de %s\n",
              carta.naipe == PAUS ? "Paus" : carta.naipe == OUROS ? "Ouros" : carta.naipe == COPAS ? "Copas" : "Espadas");
          } else if (carta.valor == 13) {
            printf("Carta sorteada: K de %s\n",
              carta.naipe == PAUS ? "Paus" : carta.naipe == OUROS ? "Ouros" : carta.naipe == COPAS ? "Copas" : "Espadas");
          } else {
            printf("Carta sorteada: %d de %s\n", carta.valor,
              carta.naipe == PAUS ? "Paus" : carta.naipe == OUROS ? "Ouros" : carta.naipe == COPAS ? "Copas" : "Espadas");
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
  srand(time(NULL));
  int valores[MAX] = {0};

  baralho.topo = 0;

  while (baralho.topo < (MAX - sorteado)) {
    int valor = geraCartaRand();

    while (valores[valor - 1]) {
      valor = geraCartaRand();
    }

    valores[valor - 1] = TRUE;
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
  printf("Topo: %d\n", baralho.topo);
}

int sortear(CARTA *carta) {
  if (baralho.topo == 0) {
    printf("Baralho vazio\n");
    return FALSE;
  }

  baralho.topo--;
  sorteado++;
  *carta = baralho.cartas[baralho.topo];
  return TRUE;
}

int geraCartaRand() {
  return 1 + rand() % MAX;
}
