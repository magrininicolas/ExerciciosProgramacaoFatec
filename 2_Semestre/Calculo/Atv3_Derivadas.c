//////////////// ATIVIDADE 3 ////////////////////
/////////////// CALCULO ADS ////////////////////
// NOME COMPLETO 1: Nicolas Gustavo Magrini Pereira
// NOME COMPLETO 2: Leonardo Morari dos Santos
// NOME COMPLETO 3: Jesua Isaque Calefi da Silva
// NOME COMPLETO 4: Carlos Henrique Nobrega da Silva
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float derivada(int opcao, float k, float x);

int main()
{
    float k, x;
    int opcao;

    x = 2;
    k = 3;

    for (opcao = 1; opcao <= 4; opcao++)
    {
        if (opcao == 1)
        {
            printf("OPCAO %d: Se f(x) = x^%.2f, entao f'(%.2f) = %f\n", opcao, k, x, derivada(opcao, k, x));
        }
        else if (opcao == 2)
        {
            if (derivada(opcao, k, x) == -1234567)
            {
                printf("OPCAO %d: Se f(x) = ln(x), entao f'(%.2f) = NAO EXISTE\n", opcao, x);
            }
            else
            {
                printf("OPCAO %d: Se f(x) = ln(x), entao f'(%.2f) = %f\n", opcao, x, derivada(opcao, k, x));
            }
        }
        else if (opcao == 3)
        {
            if (derivada(opcao, k, x) == -1234567)
            {
                printf("OPCAO %d: Se f(x) = tan(x), entao f'(%.2f) = NAO EXISTE\n", opcao, x);
            }
            else
            {
                printf("OPCAO %d: Se f(x) = tan(x), entao f'(%.2f) = %f\n", opcao, x, derivada(opcao, k, x));
            }
        }
        else
        {
            printf("OPCAO %d: OPCAO INEXISTENTE", opcao);
        }
    }
    return 0;
}

float derivada(int opcao, float k, float x)
{
    switch (opcao)
    {
    case 1:
        return k * pow(x, k - 1);
        break;
    case 2:
        if (x <= 0)
            return -1234567;
        return 1 / x;
        break;
    case 3:
        if (cos(x) < 1e-6)
            return -1234567;
        return pow((1 / cos(x)), 2);
        break;
    }
}