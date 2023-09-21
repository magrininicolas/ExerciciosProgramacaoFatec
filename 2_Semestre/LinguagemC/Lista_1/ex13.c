#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[7][7];

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(i == j) A[i][j] = 1;
            else A[i][j] = 0;
        }
    }

    printf("Matriz identidade 7x7: \n");
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}