#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int A[9][9], vetor[81];
    int k = 0, aux;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            do
            {
                A[i][j] = rand() % 1000 + 1;
            } while (A[i][j] % 2 == 0);
            vetor[k] = A[i][j];
            k++;
        }
    }

    printf("Vetor normal: ");
    for (int i = 0; i < 81; i++)
    {
        if (i % 9 == 0)
        {
            printf("\n");
        }
        printf("%3d ", vetor[i]);
    }

    for (int i = 0; i < 80; i++)
    {
        for (int j = i + 1; j < 81; j++)
        {
            if (vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    printf("Vetor crescente: \n");
    for (int i = 0; i < 81; i++)
    {
        if (i % 9 == 0)
        {
            printf("\n");
        }
        printf("%3d ", vetor[i]);
    }

    return 0;
}