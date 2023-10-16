#ifndef LISTALIGADA_LISTALIGADA_H
#define LISTALIGADA_LISTALIGADA_H

#include <stdlib.h>
#include <stdio.h>

// Constantes
struct no
{
    int dado;
    struct no *proximo;
};

// Variáveis
extern struct no *inicio;
extern struct no *aux;
extern struct no *anterior;
extern struct no *novo;

// Protótipos
void adicionar(int valor);
void adicionarNoInicio();
void adicionarNoFim();
void adicionarNoMeio();
void excluir(int valor);
void excluirNoInicio();
void excluirNoFim();
void excluirNoMeio();
void imprimir();
struct no *procuraDado(int valor);
struct no *novo_no(int dado);
void inicializar();
void finalizar();
void finalizarNo(struct no *quem);

#endif // LISTALIGADA_LISTALIGADA_H
