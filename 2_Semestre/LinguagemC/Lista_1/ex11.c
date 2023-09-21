#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int A[5], B[5], num1, num2;
    num1 = rand() % 10000 + 1;
    num2 = rand() % 10000 + 1;

    printf("%d\n", num1);
    printf("%d\n", num2);

    for (int i = 0; i < 5; i++)
    {
        A[i] = num1 % 10;
        num1 /= 10;
    }

    for (int i = 0; i < 5; i++)
    {
        B[i] = num2 % 10;
        num2 /= 10;
    }

    printf("Vetor A: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nVetor B: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", B[i]);
    }

    return 0;
}