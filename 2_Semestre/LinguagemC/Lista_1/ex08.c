#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maior, posMaior, menor, posMenor, num;

    printf("Digite um valor: ");
    scanf("%d", &num);
    maior = num;
    posMaior = 0;
    menor = num;
    posMenor = 0;

    for (int i = 1; i <= 4; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &num);
        if (num > maior)
        {
            maior = num;
            posMaior = i;
        }
        if (num < menor)
        {
            menor = num;
            posMenor = i;
        }
    }

    printf("Posicao maior: %d", posMaior);
    printf("\nPosicao menor: %d", posMenor);

    return 0;
}