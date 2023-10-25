#include <stdio.h>
#include "ArvoreBinaria.h"

// Constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_SAIR
};

// Protótipos
int menu();

int main() {
    int opcao = OP_NAO_SELECIONADA;
    int numero;

    inicializar();

    while(opcao != OP_SAIR)
    {
        opcao = menu();

        switch (opcao) {
            case OP_ADICIONAR:
                printf("Digite um numero: ");
                scanf("%d", &numero);

                adicionar(inicio, novoNo(numero));
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    finalizar(inicio);

    return 0;
}

int menu()
{
    int op = OP_NAO_SELECIONADA;
    printf("Menu de Opcoes\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);

    return op;
}