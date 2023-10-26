#include <stdio.h>
#include <stdlib.h>

void copyString(char *destino, const char *origem);

int main()
{
    char s1[101], s2[101];

    fgets(s1, 101, stdin);

    copyString(s2, s1);

    printf("A palavra copiada: %s", s2);

    return 0;
}

void copyString(char *destino, const char *origem)
{
    while (*origem != '\0')
    {
        *destino = *origem;
        destino++;
        origem++;
    }

    *destino = '\0';
}