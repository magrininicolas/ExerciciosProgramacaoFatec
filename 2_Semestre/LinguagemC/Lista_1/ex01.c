#include <stdio.h>
#include <stdlib.h>

int main()
{
    double porcentagem;
    int somaImpares = 0, somaPares = 0, total = 0;
    int qtdImpares = 0, qtdPares = 0, qtdTotal = 0;
    int A[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (A[i] % 2 == 0)
        {
            somaPares += A[i];
            qtdPares++;
        }
        else
        {
            somaImpares += A[i];
            qtdImpares++;
        }
        total += A[i];
        qtdTotal++;
    }

    porcentagem = qtdImpares / (double)qtdTotal * 100;

    printf("Soma dos impares: %d\n", somaImpares);
    printf("Soma dos pares: %d\n", somaPares);
    printf("Soma total: %d\n", total);
    printf("Porcentagem de impares: %.2f%%", porcentagem);

    return 0;
}