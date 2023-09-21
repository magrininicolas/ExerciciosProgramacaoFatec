#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maior = 0, menor = 0, soma = 0, num;

    printf("Digite um valor: ");
    scanf("%d", &num);
    maior = num;
    menor = num;
    soma += num;

    for(int i = 0; i < 5; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &num);
        maior = num > maior ? num : maior;
        menor = num < menor ? num : menor;
        soma += num;
    }


    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Media: %.2f", soma / 5.0);

    return 0;
}