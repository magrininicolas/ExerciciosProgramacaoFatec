#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    char A[5][10], respostaAluno, respostaCorreta;
    char gabarito[10];
    int acertos;

    printf("Gabarito: ");
    for (int i = 0; i < 10; i++)
    {
        gabarito[i] = rand() % 4 + 97;
        printf("%c ", gabarito[i]);
    }

    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            A[i][j] = rand() % 4 + 97;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        acertos = 0;
        for (int j = 0; j < 10; j++)
        {
            if (A[i][j] == gabarito[j])
            {
                acertos++;
            }
        }
        printf("Acertos do aluno %d: %d\n", i + 1, acertos);
    }
}