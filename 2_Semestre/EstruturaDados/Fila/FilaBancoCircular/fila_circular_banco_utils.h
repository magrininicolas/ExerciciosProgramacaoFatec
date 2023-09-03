#ifndef FILA_BANCO_UTILS_H
#define UTILS_H

#include "utils.h"

#define MAX_SIZE 10

typedef struct
{
    int valor;
    BOOL sorteada;
} SENHA;

extern SENHA senha[MAX_SIZE];
extern int queueStart;
extern int queueEnd;

int menu();
void geraSenhas();
int sorteiaSenha();
BOOL addSenha(int num);
BOOL isEmpty();
BOOL isFull();
BOOL sorteado(int pos);
BOOL removeSenha(int *num);

#endif