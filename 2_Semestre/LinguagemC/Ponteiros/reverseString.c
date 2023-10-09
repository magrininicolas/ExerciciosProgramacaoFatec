#include <stdio.h>
#include <string.h>

void reverseString(char *str);

int main()
{
    char s[101];
    gets(s);

    puts("");
    puts(s);

    reverseString(s);

    puts(s);
}

void reverseString(char *str)
{
    if(*str == '\0') return;

    char *inicio = str;
    char *fim = str + strlen(str) - 1;

    while(inicio < fim)
    {
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}