#include <stdio.h>

enum
{

    NAO_SELECIONADO,
    ADD,
    REMOVE,
    SEEK,
    EXIT

} menuOptions;

enum
{
    MAX_SIZE = 5,
};

enum
{
    FALSE,
    TRUE
} bool;

int queue[MAX_SIZE];
int queueEnd = 0;
int queueStart = 0;

typedef int BOOLEAN;

int menu();
BOOLEAN addItem(int value);
BOOLEAN removeItem(int *value);
BOOLEAN isEmpty();
BOOLEAN isFull();
int queueStartPos();
int queueEndPos();
int seekItem();

int main()
{
    int op = NAO_SELECIONADO;
    int number = 0;

    while (op != EXIT)
    {
        op = menu();

        switch (op)
        {
        case ADD:
            printf("Digite um numero: ");
            scanf("%d", &number);

            if (!addItem(number))
            {
                printf("Fila cheia\n");
            }
            break;

        case REMOVE:
            if (!removeItem(&number))
            {
                printf("Fila vazia\n");
            }
            else
            {
                printf("O número %d foi retirado da fila\n", number);
            }
            break;

        case SEEK:
            if (isEmpty())
            {
                printf("Fila vazia\n");
            }
            else
            {
                printf("Prox da fila: %d\n", seekItem());
            }
            break;

        case EXIT:
            break;

        default:
            printf("Opção inválida");
        }
    }

    return 0;
}

int menu()
{
    int op;

    printf("%d - ADD\n", ADD);
    printf("%d - REMOVE\n", REMOVE);
    printf("%d - LIST\n", SEEK);
    printf("%d - EXIT\n", EXIT);
    printf("Digite uma opção: ");
    scanf("%d", &op);

    return op;
}

BOOLEAN addItem(int value)
{
    if (isFull())
    {
        return FALSE;
    }

    queue[queueEndPos()] = value;
    queueEnd++;

    return TRUE;
}

BOOLEAN removeItem(int *value)
{
    if (isEmpty())
    {
        return FALSE;
    }

    *value = queue[queueStartPos()];
    queueStart++;

    return TRUE;
}

BOOLEAN isEmpty()
{
    return queueStart == queueEnd;
}

BOOLEAN isFull()
{
    return (queueEnd - queueStart) == MAX_SIZE;
}

int queueStartPos()
{
    return queueStart % MAX_SIZE;
}

int queueEndPos()
{
    return queueEnd % MAX_SIZE;
}

int seekItem()
{
    return queue[queueStartPos()];
}
