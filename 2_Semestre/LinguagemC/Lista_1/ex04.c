#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10];

    for (int i = 0; i < 10; i++)
    {
        do
        {
            printf("Digite um numero: ");
            scanf("%d", &A[i]);
        } while (A[i] % 2 != 0);
    }

    printf("Valores invertidos: \n");
    for (int i = 9; i >= 0; i--)
    {
        printf("%d ", A[i]);
    }

    return 0;
}