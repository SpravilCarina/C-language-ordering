#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Deplasare(int v[], int N, int i)
{
    int mare = i;
    int stanga = 2 * i + 1;
    int dreapta = 2 * i + 2;

    while (stanga < N)
    {
      
        if (dreapta < N && v[dreapta] > v[stanga])
            mare = dreapta;
        else
            mare = stanga;

       
        if (v[i] < v[mare])
        {
            swap(&v[i], &v[mare]);
            i = mare;
            stanga = 2 * i + 1;
            dreapta = 2 * i + 2;
        }
        else
        {
            break;
        }
    }
}

void heapSort(int v[], int N)
{

    for (int i = N / 2 - 1; i >= 0; i--)
        Deplasare(v, N, i);
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&v[0], &v[i]);
        Deplasare(v, i, 0);
    }
}

void Afiseaza(int v[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int v[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(v) / sizeof(v[0]);
    heapSort(v, N);
    printf("Sirul sortat cu Heapsort este \n");
    Afiseaza(v, N);
}
