#include <stdlib.h>
#include <stdio.h>
#include "utils.h"


void fillArr(int *vet, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        *(vet + i) = rand() % 100 + 1;
    }
}

void printVet(int *vet, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Elemento {%d}: %d\n", i, *(vet + i));
    }
    printf("\n");
}