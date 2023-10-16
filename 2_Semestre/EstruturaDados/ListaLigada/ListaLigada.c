#include "ListaLigada.h"

struct no *inicio = NULL;
struct no *aux = NULL;
struct no *anterior = NULL;
struct no *novo = NULL;
struct no *procurando = NULL;
struct no *encontrado = NULL;

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

void excluir(int valor)
{
    encontrado = procuraDado(valor);
    if (encontrado)
    {
        if (inicio->proximo == NULL)
        {
            inicio = NULL;
            free(encontrado);
        }
        else
        {
            if (inicio == encontrado)
            {
                excluirNoInicio();
            }
            else
            {
                aux = inicio;
                anterior = NULL;

                while (aux != encontrado)
                {
                    anterior = aux;
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
        encontrado = NULL;
    }
    else
    {
        printf("Valor nao encontrado\n\n");
    }
}

void excluirNoInicio()
{
    inicio = inicio->proximo;
}

void excluirNoMeio()
{
    anterior->proximo = aux->proximo;
}

void excluirNoFim()
{
    anterior->proximo = NULL;
}

struct no *procuraDado(int valor)
{
    aux = inicio;

    while (aux != NULL)
    {
        if (aux->dado == valor)
        {
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;
}