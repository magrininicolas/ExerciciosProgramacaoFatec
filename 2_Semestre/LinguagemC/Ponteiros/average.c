#include <stdio.h>

double average(int *arr, int size);
void fillArr(int *arr, int size);

int main()
{
    int n = 5;
    int A[n];
    int i;

    fillArr(A, n);
    printf("Media do array: %.4lf\n", average(A, n));

    return 0;
}

double average(int *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return (double)sum / size;
}

void fillArr(int *arr, int size)
{
    printf("Digite valores para o array: \n");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
