#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int A[4][2], B[4][2];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            A[i][j] = rand() % 100 + 1;
            B[i][j] = rand() % 100 + 1;
        }
    }

    printf("Matriz C: \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%3d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }

    return 0;
}