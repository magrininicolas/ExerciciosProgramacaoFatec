// ATIVIDADE 4 //
// CALCULO ADS //
// NOME COMPLETO 1: Nicolas Gustavo Magrini Pereira
// NOME COMPLETO 2: Leonardo Morari dos Santos
// NOME COMPLETO 3: Carlos Henrique Nóbrega da Silva
// NOME COMPLETO 4: Jesua Isaque Calefi da Silva
///////////////////

///////////////////////////////////////////////////////////////////
///       FUNCAO A SER IMPLEMENTADA PELO GRUPO                  ///
///       FUNCAO RECEBE OPCAO (inteiro), k, a, b (float)         ///
///       FUNCAO IRA RETORNAR A INTEGRAL DEFINIDA de f(x) EM RELACAO A X DE a ATE b das seguintes funcoes avaliada em x: ///
///               f(x) = x^k - SE OPCAO 1                      ///
///               f(x) = 1/x - SE OPCAO 2                      ///
///               -1234567   - SE OUTRA OPCAO OU SE X INVALIDO NO DOMINIO   ///
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

float integral_definida(int opcao, float k, float a, float b);

int main()
{
    float k, a, b;
    int opcao;

    a = 0; // Entradas para teste
    b = 4; // Entradas para teste
    k = 2; // Entradas para teste

    for (opcao = 1; opcao <= 3; opcao++)
    {
        if (opcao == 1)
        {
            if (integral_definida(opcao, k, a, b) == -1234567)
            {
                printf("OPCAO %d:integral (a = %.2f) ate (b = %.2f) x^%.2f dx  = DIVERGE\n", opcao, a, b, k);
            }
            else
            {
                printf("OPCAO %d: integral (a = %.2f) ate (b = %.2f) x^%.2f dx  = %f\n", opcao, a, b, k, integral_definida(opcao, k, a, b));
            }
        }
        else if (opcao == 2)
        {
            if (integral_definida(opcao, k, a, b) == -1234567)
            {
                printf("OPCAO %d:integral (a = %.2f) ate (b = %.2f) 1/x dx  = DIVERGE \n", opcao, a, b);
            }
            else
            {
                printf("OPCAO %d: integral (a = %.2f) ate (b = %.2f) 1/x dx  = %f \n", opcao, a, b, integral_definida(opcao, k, a, b));
            }
        }
        else
        {
            printf("OPCAO %d: OPCAO INEXISTENTE \n", opcao);
        }
    }
    return 0;
}

float integral_definida(int opcao, float k, float a, float b)
{
    if (opcao == 1)
    {
        if (k == -1 || a > b)
        {
            return -1234567;
        }

        float integral = pow(b, k + 1) / (k + 1) - pow(a, k + 1) / (k + 1);
        return integral;
    }
    else if (opcao == 2)
    {
        if (a > b || a <= 0 || b <= 0)
        {
            return -1234567;
        }

        float integral = log(b) - log(a);
        return integral;
    }

    return -1234567;
}