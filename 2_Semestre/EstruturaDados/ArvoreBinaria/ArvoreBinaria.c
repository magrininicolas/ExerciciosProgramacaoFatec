#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

// Variáveis
struct no *inicio;

// Protótipos
void adicionar(struct no *aonde, struct no *quem)
{
    if (inicio == NULL)
    {
        printf("Adicionando %d no inicio\n", quem->dado);
        inicio = quem;
    }
    else
    {
        if (quem->dado > aonde->dado)
        {
            // direita
            if (aonde->direita == NULL)
            {
                printf("Adicionando %d a direita de %d\n", quem->dado, aonde->dado);
                aonde->direita = quem;
            }
            else
            {
                printf("Indo para a direita de %d\n", aonde->dado);
                adicionar(aonde->direita, quem);
            }
        }
        else
        {
            // esquerda
            if (aonde->esquerda == NULL)
            {
                printf("Adicionando %d a esquerda de %d\n", quem->dado, aonde->dado);
                aonde->esquerda = quem;
            }
            else
            {
                printf("Indo para a esquerda de %d\n", aonde->dado);
                adicionar(aonde->esquerda, quem);
            }
        }
    }
}

struct no *novoNo(int dado)
{
    struct no *p = NULL;

    p = malloc(sizeof(struct no));
    if (!p)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(-1);
    }
    p->esquerda = NULL;
    p->dado = dado;
    p->direita = NULL;

    return p;
}

void inicializar()
{
    inicio = NULL;
}

void finalizar(struct no *aonde)
{
    if (aonde->esquerda != NULL)
    {
        printf("Indo para a esquerda de %d\n", aonde->dado);
        finalizar(aonde->esquerda);
    }
    if (aonde->direita != NULL)
    {
        printf("Indo para a direita de %d\n", aonde->dado);
        finalizar(aonde->direita);
    }
    printf("Excluindo %d\n", aonde->dado);
    free(aonde);
}

struct no *busca(struct no *arvore, int dado)
{
    if (arvore == NULL || arvore->dado == dado)
    {
        return arvore;
    }

    if (arvore->dado > dado)
    {
        busca(arvore->esquerda, dado);
    }
    else
    {
        busca(arvore->direita, dado);
    }
}