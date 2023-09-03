#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fila_circular_banco_utils.h"

SENHA senha[MAX_SIZE];
int queueStart = 0;
int queueEnd = 0;

BOOL addSenha(int num)
{
    if (isFull())
    {
        return FALSE;
    }

    senha[queueEnd % MAX_SIZE].valor = num;
    senha[queueEnd % MAX_SIZE].sorteada = TRUE;
    queueEnd++;
    return TRUE;
}

BOOL removeSenha(int *num)
{
    if (isEmpty())
    {
        return FALSE;
    }

    *num = senha[queueStart % MAX_SIZE].valor;
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
    return (queueEnd - queueStart) == MAX_SIZE;
}