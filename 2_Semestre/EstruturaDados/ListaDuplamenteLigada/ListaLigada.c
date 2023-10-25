#include "ListaLigada.h"

struct no *inicio = NULL;
struct no *aux = NULL;
struct no *anterior = NULL;
struct no *novo = NULL;

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

void finalizarNo(struct no *quem)
{
    if (quem->proximo != NULL)
    {
        finalizarNo(quem->proximo);
    }
    printf("Excluindo %d\n", quem->dado);
    free(quem);
}

struct no *novo_no(int dado)
{
    struct no *p = malloc(sizeof(struct no));
    if (!p)
    {
        printf("Erro de alocacao de memoria\n");
        exit(-1);
    }
    p->anterior = NULL;
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

void imprimirInvertido()
{
    if (inicio != NULL)
    {
        aux = inicio;
        while (aux->proximo != 0)
        {
            aux = aux->proximo;
        }
        while (aux->anterior != 0)
        {
            printf("%d -> ", aux->dado);
            aux = aux->anterior;
        }
        printf("%d\n", aux->dado);
    }
    else
    {
        printf("Lista vazia!\n");
    }
}

void adicionar(int valor)
{
    novo = novo_no(valor);
    if (inicio == NULL)
    {
        inicio = novo;
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

            while (aux->dado <= novo->dado && aux->proximo != NULL)
            {
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
void adicionarNoInicio()
{
    novo->proximo = inicio;
    inicio->anterior = novo;
    inicio = novo;
}

void adicionarNoFim()
{
    aux->proximo = novo;
    novo->anterior = aux;
}

void adicionarNoMeio()
{

    aux->anterior->proximo = novo;
    novo->anterior = aux->anterior;
    novo->proximo = aux;
    aux->anterior = novo;
}

void excluir(int valor)
{
    if (inicio->proximo == NULL)
    {
        inicio = NULL;
        free(inicio);
    }
    else
    {
        if (inicio->dado == valor)
        {
            excluirNoInicio();
        }
        else
        {
            aux = inicio;

            while (aux->dado != valor && aux->proximo != NULL)
            {
                aux = aux->proximo;
            }
            if (aux->proximo == NULL)
            {
                excluirNoFim();
            }
            else
            {
                excluirNoMeio();
            }
        }
    }
}

void excluirNoInicio()
{
    aux = inicio;
    inicio = inicio->proximo;
    inicio->anterior = NULL;

    free(aux);
}

void excluirNoMeio()
{
    aux->anterior->proximo = aux->proximo;
    aux->proximo->anterior = aux->anterior;

    free(aux);
}

void excluirNoFim()
{
    aux->anterior->proximo = NULL;

    free(aux);
}
