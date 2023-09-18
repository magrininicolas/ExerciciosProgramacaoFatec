// Carlos Henrique Nóbrega da Silva
// Jesua Isaque Calefi da Silva
// Leonardo Morari dos Santos
// Nicolas Gustavo Magrini Pereira

#include <stdio.h>
#include <math.h>

double trigonometrica(int opcao, float rad);

int main()
{
    float x, y;
    int opcao, k;

    x = M_PI / 6; // Valor de entrada do angulo em radianos

    for (opcao = 1; opcao <= 4; opcao++)
    {
        if (opcao == 1)
        {
            printf("OPCAO %d: sin(%.4f [rad]) = %.4f\n", opcao, x, trigonometrica(opcao, x));
        }
        else if (opcao == 2)
        {
            printf("OPCAO %d: cos(%.4f [rad]) = %.4f\n", opcao, x, trigonometrica(opcao, x));
        }
        else if (opcao == 3)
        {
            y = trigonometrica(opcao, x);
            if (y == -123456789)
            {
                printf("OPCAO %d: tan(%.4f [rad]) NAO EXISTE\n", opcao, M_PI * (0.5 + k));
            }
            else
            {
                printf("OPCAO %d: tan(%.4f [rad]) = %.4f\n", opcao, x, y);
            }
        }
        else
        {
            printf("OPCAO %d: OPCAO INEXISTENTE", opcao);
        }
    }
    return 0;
}

double trigonometrica(int opcao, float rad)
{
    if (opcao >= 4)
        return -1;
    if (opcao == 1)
        return sin(rad);
    if (opcao == 2)
        return cos(rad);
    if (opcao == 3 && cos(rad) <= 0.00001)
        return -123456789;
    else
    {
        return tan(rad);
    }
}
