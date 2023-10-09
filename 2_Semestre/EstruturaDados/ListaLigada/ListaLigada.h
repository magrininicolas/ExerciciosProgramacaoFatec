#ifndef LISTALIGADA_LISTALIGADA_H
#define LISTALIGADA_LISTALIGADA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} no;

extern no *inicio;
extern no *novo;
extern no *aux;
extern no *anterior;

void adicionar(int valor);
void adicionarNoInicio();
void adicionarNoFim();
void adicionarNoMeio();
no *novoNo(int dado);
void excluir(int valor);
void imprimir();
void inicializar();
void finalizar();
void finalizarNo(no *quem);

#endif