#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10

enum
{
    NAO_SELECIONADA = 0,
    RETIRAR_SENHA,
    ATENDER_CLIENTE,
    SAIR
} menu_op;

enum{
    FALSE = 0,
    TRUE
};

typedef int BOOL;

typedef struct
{
    int valor;
    BOOL sorteada;
} SENHA;

int menu();
void geraSenhas();
int sorteiaSenha();
BOOL addSenha(int num);
BOOL isEmpty();
BOOL isFull();
BOOL sorteado(int pos);
BOOL removeSenha(int *num);

SENHA senha[MAX_SIZE];
int queueStart = 0;
int queueEnd = 0;

int main()
{
    int op = NAO_SELECIONADA;
    geraSenhas();

    while (op != SAIR)
    {
        op = menu();
        switch (op)
        {
        case RETIRAR_SENHA:
            int num = sorteiaSenha();
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

BOOL addSenha(int num)
{
    if (isFull())
    {
        return FALSE;
    }

    senha[queueEnd].valor = num;
    senha[queueEnd].sorteada = TRUE;
    queueEnd++;
    return TRUE;
}

BOOL removeSenha(int *num)
{
    if (isEmpty())
    {
        return FALSE;
    }

    *num = senha[queueStart].valor;
    queueStart++;
    return TRUE;
}

void geraSenhas()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        senha[i].valor = 0;
        senha[i].sorteada = FALSE;
    }
}

int sorteiaSenha()
{
    srand(time(NULL));

    int num = 0;

    do
    {
        num = rand() % 1000;
    } while (sorteado(num));

    return num;
}

BOOL sorteado(int num)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (senha[i].valor == num)
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL isEmpty()
{
    return queueStart == queueEnd;
}

BOOL isFull()
{
    return queueEnd == MAX_SIZE;
}