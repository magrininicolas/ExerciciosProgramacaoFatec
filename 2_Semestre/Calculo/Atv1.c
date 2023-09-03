#include <stdio.h>
#include <math.h>

float converte(int opcao, float angulo);

int main()
{
    float angulo;
    int opcao;

    angulo = M_PI / 6;

    for (opcao = 1; opcao <= 3; opcao++)
    {
        if (opcao == 1)
        {
            printf("OPCAO %d: O angulo %.4f em graus = %.4f radianos\n", opcao, angulo, converte(opcao, angulo));
        }
        else if (opcao == 2)
        {
            printf("OPCAO %d: O angulo %.4f em radianos = %.4f graus\n", opcao, angulo, converte(opcao, angulo));
        }
        else
        {
            printf("OPCAO %d: OPCAO INEXISTENTE", opcao);
        }
    }
    return 0;
}

float converte(int opcao, float angulo)
{
    if (opcao == 1)
    {
        return angulo * M_PI / 180;
    }
    else if (opcao == 2)
    {
        return angulo * 180 / M_PI;
    }

    return -1.0;
}
