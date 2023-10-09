#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int numA = 5, numB = 10;

    printf("A: %d\n", numA);
    printf("B: %d\n", numB);

    swap(&numA, &numB);

    printf("A: %d\n", numA);
    printf("B: %d\n", numB);

    return 0;

}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}