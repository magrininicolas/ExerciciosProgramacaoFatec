#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utils.h"


int sumVet(int *vet, int tamanho);

int main()
{
    srand(time(NULL));

    int vet[T];

    fillArr(vet, T);

    printf("Soma do vetor: %d", sumVet(vet, T));
}

int sumVet(int *vet, int tamanho)
{
    int sum = 0;
    for (int i = 0; i < tamanho; i++)
    {
        sum += *(vet + i);
    }

    return sum;
}
