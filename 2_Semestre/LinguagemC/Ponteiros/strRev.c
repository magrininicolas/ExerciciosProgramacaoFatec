#include <stdio.h>

int main()
{
    char s[101];
    char *ptr_s = s;
    gets(s);

    if(*ptr_s == '\0') return 0;

    printf("\n\n");
    while (*ptr_s != '\0')
    {
        putchar(*ptr_s++);
    }

    printf("\n\n");
    ptr_s--;

    while(ptr_s >= s)
    {
        putchar(*ptr_s--);
    }
    printf("\n\n");

    return 0;
}