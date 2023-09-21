#include <stdio.h>
#include <stdlib.h>

int main()
{

    int notas[15], totalNotas = 0;

    for (int i = 0; i < 15; i++)
    {
        do
        {
            printf("Digite uma nota: ");
            scanf("%d", &notas[i]);
        } while (notas[i] < 0 || notas[i] > 10);
        totalNotas += notas[i];
    }

    printf("Media da turma: %.2f\n", totalNotas / 15.0);
}