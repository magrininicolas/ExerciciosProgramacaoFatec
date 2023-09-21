#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int A[5][5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i > j)
            {
                A[i][j] = 0;
            }
            else
            {
                A[i][j] = rand() % 100 + 1;
            }
        }
    }

    printf("Matriz triangular superior gerada: \n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }

}