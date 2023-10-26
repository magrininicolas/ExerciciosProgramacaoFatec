#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int *findGreatest(int *vet, int tamanho);

int *maior = NULL;

int main()
{
    srand(time(NULL));

    int vet[T];

    fillArr(vet, T);

    printVet(vet, T);

    findGreatest(vet, T);

    printf("Maior valor: %d", *maior);

    return 0;
}

int *findGreatest(int *vet, int tamanho)
{
    maior = vet;
    for (int i = 1; i < tamanho; i++)
    {
        if (*(vet + i) > *maior)
        {
            maior = vet + i;
        }
    }

    return maior;
}