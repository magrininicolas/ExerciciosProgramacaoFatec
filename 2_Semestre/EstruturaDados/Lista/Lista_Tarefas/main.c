#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

enum
{
    OP_NAO_SELECIONADA,
    OP_ADICIONAR_TAREFA,
    OP_LOCALIZAR_TAREFA,
    OP_EXCLUIR_TAREFA,
    OP_SAIR
};

typedef struct
{
    int prioridade;
    char tarefa[101];
} LISTA;

LISTA *lista = NULL;
size_t tamanho = 5;
int posicao = 0;

BOOLEAN adicionarTarefa(int prioridade, char tarefa[]);
BOOLEAN buscarPorTarefa(char tarefa[]);
BOOLEAN localizarTarefa(char tarefa[], int *prioridade);
BOOLEAN excluirTarefa(char tarefa[]);
BOOLEAN estaCheia();
BOOLEAN estaVazia();
int quantidadeElementos();
int menu();
void ordenar();
void listar();
void inicializar();
void finalizar();
void expandir();

int main()
{
    inicializar();
    int op = OP_NAO_SELECIONADA;
    int prioridade = -1;
    char tarefa[101];

    while (op != OP_SAIR)
    {
        op = menu();
        switch (op)
        {
        case OP_ADICIONAR_TAREFA:

            printf("Digite a prioridade da tarefa: ");
            scanf("%d", &prioridade);

            __fpurge(stdin); // Linux
            // fflush(stdin) // Windows

            printf("Digite uma tarefa: ");
            fgets(tarefa, 101, stdin);

            if (!adicionarTarefa(prioridade, tarefa))
            {
                expandir();
            }

            adicionarTarefa(prioridade, tarefa);
            ordenar();
            listar();
            break;

        case OP_LOCALIZAR_TAREFA:
            printf("Digite a tarefa: ");
            __fpurge(stdin);
            fgets(tarefa, 101, stdin);
            if (localizarTarefa(tarefa, &prioridade))
            {
                printf("Tarefa localizada: Prioridade: %d - Tarefa: %s", prioridade, tarefa);
            }
            else
            {
                printf("Tarefa nao encontrada\n");
            }
            break;

        case OP_EXCLUIR_TAREFA:
            printf("Digite a tarefa: ");
            __fpurge(stdin);
            fgets(tarefa, 101, stdin);
            if (excluirTarefa(tarefa))
            {
                printf("Tarefa excluida com sucesso\n");
            }
            else
            {
                printf("Tarefa nao encontrada\n");
            }
            ordenar();
            listar();
            break;

        case OP_SAIR:
            break;

        default:
            printf("Opcao invalida\n");
        }
    }

    finalizar();
}

int menu()
{
    int op = OP_NAO_SELECIONADA;

    printf("\nMenu de Opcoes\n");
    printf("%d - Adicionar Tarefa\n", OP_ADICIONAR_TAREFA);
    printf("%d - Localizar Tarefa\n", OP_LOCALIZAR_TAREFA);
    printf("%d - Excluir Tarefa\n", OP_EXCLUIR_TAREFA);
    printf("%d - Sair\n", OP_SAIR);

    printf("Digite uma opcao: ");
    scanf("%d", &op);
    puts("");

    return op;
}

BOOLEAN estaVazia()
{
    return posicao == 0;
}

BOOLEAN estaCheia()
{
    return posicao == tamanho;
}

int quantidadeElementos()
{
    return posicao;
}

void inicializar()
{
    lista = malloc(sizeof(LISTA) * tamanho);

    if (!lista)
    {
        printf("Erro de alocacao de memoria\n");
        exit(-1);
    }
}

void finalizar()
{
    free(lista);
}

BOOLEAN adicionarTarefa(int prioridade, char tarefa[])
{
    if (estaCheia() || prioridade > 100 || prioridade <= 0 || buscarPorTarefa(tarefa))
    {
        return FALSE;
    }

    lista[posicao].prioridade = prioridade;
    strcpy(lista[posicao].tarefa, tarefa);
    posicao++;

    return TRUE;
}

BOOLEAN buscarPorTarefa(char tarefa[])
{
    for (int i = 0; i < posicao; i++)
    {
        if (strcmp(lista[i].tarefa, tarefa) == 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void ordenar()
{
    int auxPriori;
    char auxTare[101];
    for (int i = 0; i < (posicao - 1); i++)
    {
        for (int j = i + 1; j < posicao; j++)
        {
            if (lista[i].prioridade < lista[j].prioridade)
            {
                auxPriori = lista[i].prioridade;
                lista[i].prioridade = lista[j].prioridade;
                lista[j].prioridade = auxPriori;

                strcpy(auxTare, lista[i].tarefa);
                strcpy(lista[i].tarefa, lista[j].tarefa);
                strcpy(lista[j].tarefa, auxTare);
            }
        }
    }
}

void listar()
{
    for (int i = 0; i < posicao; i++)
    {
        printf("Prioridade: %d - Tarefa: %s", lista[i].prioridade, lista[i].tarefa);
    }
}

BOOLEAN localizarTarefa(char tarefa[], int *prioridade)
{
    if (estaVazia())
    {
        return FALSE;
    }

    for (int i = 0; i < posicao; i++)
    {
        if (strcmp(lista[i].tarefa, tarefa) == 0)
        {
            *prioridade = lista[i].prioridade;
            return TRUE;
        }
    }

    return FALSE;
}

BOOLEAN excluirTarefa(char tarefa[])
{
    if (estaVazia())
    {
        return FALSE;
    }

    int i = 0;

    if (localizarTarefa(tarefa, &i))
    {
        for (; i < (posicao - 1); i++)
        {
            lista[i].prioridade = lista[i + 1].prioridade;
            strcpy(lista[i].tarefa, lista[i + 1].tarefa);
        }
        posicao--;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void expandir()
{
    size_t novoTamanho = tamanho * 1.5;
    LISTA *p;

    p = malloc(novoTamanho * sizeof(int));

    if (!p)
    {
        printf("Erro de alocacao de memoria\n");
        exit(-1);
    }

    for (int i = 0; i < posicao; i++)
    {
        p[i].prioridade = lista[i].prioridade;
        strcpy(p[i].tarefa, lista[i].tarefa);
    }

    free(lista);
    lista = p;
    tamanho = novoTamanho;
}