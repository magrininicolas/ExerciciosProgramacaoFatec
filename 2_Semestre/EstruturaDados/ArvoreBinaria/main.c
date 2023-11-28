#include <stdio.h>
#include "ArvoreBinaria.h"

// Constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_LOCALIZAR,
    OP_EXCLUIR,
    OP_SAIR
};

struct no *resultado;

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
            case OP_LOCALIZAR:
                printf("Digite um numero: ");
                scanf("%d", &numero);

                 resultado = busca(inicio, numero);
                if(resultado == NULL)
                {
                    printf("Nao achei\n");
                }
                else
                {
                    printf("Encontrei %d na arvore!\n", resultado->dado);
                }
                break;
            case OP_EXCLUIR:
                printf("Digite um numero para ser excluido: ");
                scanf("%d", &numero);

                resultado = busca(inicio, numero);
                if(resultado == NULL)
                {
                    printf("Nao achei\n");
                }
                else
                {
                    printf("%d foi excluido com sucesso\n", resultado->dado);
                    excluir(resultado);
                }
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
    printf("%d - Localizar\n", OP_LOCALIZAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);

    return op;
}

