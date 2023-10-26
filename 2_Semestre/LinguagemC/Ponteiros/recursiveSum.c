#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int recursiveSum(int v[], int n);

int main()
{
    srand(time(NULL));

    int vet[T];

    fillArr(vet, T);
    printVet(vet, T);

    int sum = recursiveSum(vet, T);

    printf("Soma do vetor recursivo: %d", sum);

    return 0;
}

int recursiveSum(int v[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return *v + recursiveSum(v + 1, n - 1);
    }
}