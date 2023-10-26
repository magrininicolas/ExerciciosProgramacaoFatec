#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int doubleValues(int *vet, int tamanho);

int main()
{
    int vet[T];

    fillArr(vet, T);

    printf("Vetor original:\n");
    printVet(vet, T);

    doubleValues(vet, T);

    printf("Vetor dobrado:\n");
    printVet(vet, T);

    return 0;
}

int doubleValues(int *vet, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        *(vet + i) *= 2;
    }
}
