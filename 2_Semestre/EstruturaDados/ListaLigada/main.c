#include "ListaLigada.h"

enum
{
    OP_NAO_SELECIONADA,
    OP_ADICIONAR,
    OP_EXCLUIR,
    OP_IMPRIMIR,
    OP_SAIR
} op_menu;

int menu();

int main()
{
    inicializar();
    int op = OP_NAO_SELECIONADA;
    int num;
    while (op != OP_SAIR)
    {
        op = menu();

        switch (op)
        {
        case OP_ADICIONAR:
            printf("Digite um numero: ");
            scanf("%d", &num);
            adicionar(num);
            break;
        case OP_EXCLUIR:
            printf("A ser implementado");
            break;
        case OP_IMPRIMIR:
            imprimir();
            break;
        case OP_SAIR:
            break;
        default:
            printf("Opcao invalida");
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