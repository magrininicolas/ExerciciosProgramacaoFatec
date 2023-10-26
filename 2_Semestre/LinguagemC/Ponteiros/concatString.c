#include <stdlib.h>
#include <stdio.h>

void concatString(char *s1, const char *s2);

char s3[202];

int main()
{
    char s1[101], s2[101];

    gets(s1);

    __fpurge(stdin);

    gets(s2);

    concatString(s1, s2);

    printf("A string completa: %s", s3);

    return 0;
}

void concatString(char *s1, const char *s2)
{
    char *p_s3 = s3;

    while (*s1 != '\0')
    {
        *p_s3 = *s1;
        p_s3++;
        s1++;
    }

    *p_s3 = ' ';
    p_s3++;

    while (*s2 != '\0')
    {
        *p_s3 = *s2;
        p_s3++;
        s2++;
    }

    *p_s3 = '\0';
}