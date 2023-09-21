#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "utils.h"

// Constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_QUANTIDADE_ELEMENTOS,
    OP_BUSCAR_POR_INDICE,
    OP_BUSCAR_POR_VALOR,
    OP_EXCLUIR,
    OP_ORDENAR,
    OP_LISTAR,
    OP_SAIR,
};

// Variáveis
size_t tamanho = 5;
int *lista = NULL;
int posicao = 0;

// Protótipos
BOOLEAN adicionar(int valor);
int quantidadeElementos();
BOOLEAN buscarPorIndice(int indice, int *valor);
BOOLEAN buscarPorValor(int valor, int *indice);
BOOLEAN excluir(int valor);
void ordenar(char tipo);
void listar();
void inicializar();
void finalizar();
void expandir();

int menu();
BOOLEAN estaCheia();
BOOLEAN estaVazia();

int main() {
    inicializar();
    int opcao = OP_NAO_SELECIONADA;
    int indice = 0;
    int valor = 0;
    char cd;

    while(opcao != OP_SAIR)
    {
        opcao = menu();

        switch (opcao) {
            case OP_ADICIONAR:
                printf("Digite um valor para adicionar: ");
                scanf("%d", &valor);

                if(adicionar(valor))
                {
                    listar();
                }
                else
                {
                    expandir();
                    adicionar(valor);
                    listar();
                }
                break;
            case OP_QUANTIDADE_ELEMENTOS:
                printf("Quantidade: %d\n", quantidadeElementos());
                break;
            case OP_BUSCAR_POR_INDICE:
                printf("Digite o indice: ");
                scanf("%d", &indice);

                if(buscarPorIndice(indice, &valor))
                {
                    printf("Encontrado %d no indice %d\n", valor, indice);
                }
                else
                {
                    printf("Indice invalido!\n");
                }
                break;
            case OP_BUSCAR_POR_VALOR:
                printf("Digite o valor: ");
                scanf("%d", &valor);

                if(buscarPorValor(valor, &indice))
                {
                    printf("Encontrado %d no indice %d\n", valor, indice);
                }
                else
                {
                    printf("Nao encontrado!\n");
                }
                break;
            case OP_EXCLUIR:
                printf("Digite o valor: ");
                scanf("%d", &valor);

                if(excluir(valor))
                {
                    printf("Excluido %d da lista\n", valor);
                    listar();
                }
                else
                {
                    printf("Nao encontrado!\n");
                }
                break;
            case OP_ORDENAR:
                printf("(C)rescente ou (D)ecrescente? ");
                scanf(" %c", &cd);

                cd = toupper(cd);

                if(cd == 'C' || cd == 'D')
                {
                    ordenar(cd);
                    listar();
                }
                else
                {
                    printf("Opcao invalida!\n");
                }
                break;
            case OP_LISTAR:
                listar();
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    finalizar();

    return 0;
}

int menu()
{
    int op = OP_NAO_SELECIONADA;
    printf("Menu de Opcoes\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Quantidade de elementos\n", OP_QUANTIDADE_ELEMENTOS);
    printf("%d - Buscar por indice\n", OP_BUSCAR_POR_INDICE);
    printf("%d - Buscar por valor\n", OP_BUSCAR_POR_VALOR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Ordenar\n", OP_ORDENAR);
    printf("%d - Listar\n", OP_LISTAR);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite a sua opcao: ");
    scanf("%d", &op);

    return op;
}

BOOLEAN estaCheia()
{
    return posicao == tamanho;
}

BOOLEAN adicionar(int valor)
{
    if(estaCheia())
    {
        return FALSE;
    }
    lista[posicao] = valor;
    posicao++;

    return TRUE;
}

BOOLEAN estaVazia()
{
    return posicao == 0;
}

void listar()
{
    if(estaVazia())
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for(int i = 1; i < posicao+1; i++)
        {
            printf("%2d ", lista[i-1]);
            if(!(i%10))
            {
                printf("\n");
            }
        }
        printf("\n");
    }
}

int quantidadeElementos()
{
    return posicao;
}

BOOLEAN buscarPorIndice(int indice, int *valor)
{
    if(estaVazia() || indice < 0 || indice > (posicao - 1))
    {
        return FALSE;
    }
    *valor = lista[indice];

    return TRUE;
}

BOOLEAN buscarPorValor(int valor, int *indice)
{
    if(estaVazia())
    {
        return FALSE;
    }
    for(int i = 0; i < posicao; i++)
    {
        if(lista[i] == valor)
        {
            *indice = i;

            return TRUE;
        }
    }

    return FALSE;
}

BOOLEAN excluir(int valor)
{
    int indice = 0;

    if(buscarPorValor(valor, &indice))
    {
        for(;indice < (posicao-1); indice++)
        {
            lista[indice] = lista[indice+1];
        }
        posicao--;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void ordenar(char tipo)
{
    int aux;
    if(tipo == 'C') {
        for (int i = 0; i < (posicao - 1); i++) {
            for (int j = i + 1; j < posicao; j++) {
                if (lista[i] > lista[j]) {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < (posicao - 1); i++) {
            for (int j = i + 1; j < posicao; j++) {
                if (lista[i] < lista[j]) {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
}

void inicializar()
{
    lista = malloc(tamanho * sizeof(int));

    if(!lista)
    {
        printf("Erro de alocacao de memoria\n");
        exit(-1);
    }
}

void finalizar()
{
    free(lista);
}

void expandir()
{
    printf("Expandindo a geringonca!!!\n");
    size_t novoTamanho = tamanho * 1.5;
    int *p;

    p = malloc(novoTamanho * sizeof(int));
    if(!p)
    {
        printf("Erro de alocacao de memoria\n");
        exit(-1);
    }

    for(int i = 0; i < posicao; i++)
    {
        p[i] = lista[i];
    }

    free(lista);
    lista = p;
    tamanho = novoTamanho;
}
