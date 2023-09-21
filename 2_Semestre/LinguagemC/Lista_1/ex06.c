#include <stdio.h>
#include <stdlib.h>

int main()
{
    double A[10], somaPositivos = 0;
    int qtdNegativos = 0;

    for(int i = 0; i < 10; i++)
    {
        printf("Digite um numero: ");
        scanf("%lf", &A[i]);
    }

    for(int i = 0; i < 10; i++)
    {
        if(A[i] > 0)
        {
            somaPositivos += A[i];
        }
        else
        {
            qtdNegativos++;
        }
    }

    printf("Soma positivos: %.2f\n", somaPositivos);
    printf("Quantidade de negativos: %d\n", qtdNegativos);

    return 0;
}