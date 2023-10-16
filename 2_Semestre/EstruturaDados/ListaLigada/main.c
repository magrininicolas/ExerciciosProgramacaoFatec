#include <stdio.h>

#include "ListaLigada.h"

// constantes
enum
{
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_EXCLUIR,
    OP_IMPRIMIR,
    OP_SAIR
};

// variáveis

// protótipos
int menu();

int main()
{
    inicializar();
    int opcao = OP_NAO_SELECIONADA;
    int numero;

    while (opcao != OP_SAIR)
    {
        opcao = menu();

        switch (opcao)
        {
        case OP_ADICIONAR:
            printf("Digite um numero: ");
            scanf("%d", &numero);

            adicionar(numero);
            break;
        case OP_EXCLUIR:
            printf("Digite um numero: ");
            scanf("%d", &numero);

            excluir(numero);
            break;
        case OP_IMPRIMIR:
            imprimir();
            break;
        case OP_SAIR:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }

    finalizar();

    return 0;
}

int menu()
{
    int op = OP_NAO_SELECIONADA;
    printf("Menu de Opcoes\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Imprimir\n", OP_IMPRIMIR);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);

    return op;
}
