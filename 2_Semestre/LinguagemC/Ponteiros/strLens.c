#include <stdio.h>

int strLens(char *s);

int main()
{
    char s[101];
    gets(s);
    int numCarac = strLens(s);
    printf("Numero caracteres: %d", numCarac);

    return 0;
}

int strLens(char *s)
{
    int cont = 0;
    if(*s == '\0') return 0;

    while(*s != '\0')
    {
        cont++;
        s++;
    }

    return cont;
}