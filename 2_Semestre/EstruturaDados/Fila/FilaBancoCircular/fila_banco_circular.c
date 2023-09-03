#include <stdio.h>
#include "fila_circular_banco_utils.h"

enum
{
    NAO_SELECIONADA = 0,
    RETIRAR_SENHA,
    ATENDER_CLIENTE,
    SAIR
} menu_op;


int main()
{
    int op = NAO_SELECIONADA;
    geraSenhas();

    while (op != SAIR)
    {
        op = menu();
        int num;
        switch (op)
        {
        case RETIRAR_SENHA:
            num = sorteiaSenha();
            if (addSenha(num))
            {
                printf("Sua senha: %d\n", num);
            }
            else
            {
                printf("Fila cheia\n");
            }
            break;
        case ATENDER_CLIENTE:
            if (removeSenha(&num))
            {
                printf("Cliente com senha %d para o atendimento\n", num);
            }
            else
            {
                printf("Fila vazia\n");
            }
            break;
        case SAIR:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}

int menu()
{
    int op;
    printf("%d - Retirar Senha\n", RETIRAR_SENHA);
    printf("%d - Atender Cliente\n", ATENDER_CLIENTE);
    printf("%d - Sair\n", SAIR);
    printf("Digite uma opcao: ");
    scanf("%d", &op);
    return op;
}