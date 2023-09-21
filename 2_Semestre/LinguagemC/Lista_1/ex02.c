#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10], B[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            B[i] = A[i] * 5;
        }
        else
        {
            B[i] = A[i] + 5;
        }
    }

    printf("Vetor A: \n");
    for (int i = 9; i >= 0; i--)
    {
        printf("%d ", A[i]);
    }

    printf("\nVetor B: \n");
    for (int i = 9; i >= 0; i--)
    {
        printf("%d ", B[i]);
    }

    return 0;
}