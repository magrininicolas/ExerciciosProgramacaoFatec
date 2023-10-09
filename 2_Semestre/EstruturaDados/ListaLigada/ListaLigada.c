#include "ListaLigada.h"

no *inicio = NULL;
no *novo = NULL;
no *aux = NULL;
no *anterior = NULL;

void inicializar()
{
    inicio = NULL;
}

void finalizar()
{
    if (inicio != NULL)
    {
        finalizarNo(inicio);
        inicio = NULL;
    }
}

void finalizarNo(no *quem)
{
    if (quem->proximo != NULL)
    {
        finalizarNo(quem->proximo);
    }
    free(quem);
}

no *novoNo(int dado)
{
    no *p = malloc(sizeof(no));
    if (!p)
    {
        printf("Erro para alocar");
        exit(-1);
    }

    p->dado = dado;
    p->proximo = NULL;

    return p;
}

void imprimir()
{
    if (inicio != NULL)
    {
        aux = inicio;
        while (aux->proximo != 0)
        {
            printf("%d -> ", aux->dado);
            aux = aux->proximo;
        }
        printf("%d\n", aux->dado);
    }
    else
    {
        printf("Lista vazia!\n");
    }
}

void adicionarNoInicio()
{
    novo->proximo = inicio;
    inicio = novo;
}

void adicionarNoFim()
{
    aux->proximo = novo;
}

void adicionarNoMeio()
{
    novo->proximo = aux;
    anterior->proximo = novo;
}

void adicionar(int valor)
{
    novo = novoNo(valor);
    if (inicio == NULL)
    {
        adicionarNoInicio();
    }
    else
    {
        if (novo->dado <= inicio->dado)
        {
            adicionarNoInicio();
        }
        else
        {
            aux = inicio;
            anterior = inicio;
            while (aux->dado <= novo->dado && aux->proximo != NULL)
            {
                anterior = aux;
                aux = aux->proximo;
            }
            if (novo->dado > aux->dado)
            {
                adicionarNoFim();
            }
            else
            {
                adicionarNoMeio();
            }
        }
    }
}