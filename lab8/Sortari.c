#include <stdio.h>
#include <stdlib.h>
void generare(int v[], int n)
{
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++)
		v[i] = rand() % 100;
}
void afisare(int v[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}
void Shellsort(int h[], int t, int a[], int n)
{
	int i, j, k, x, aux;
	for (i = 0; i < t; i++)
	{
		x = h[i];
		for (j = h[i]; j < n; j = j + h[i])
		{
			aux = a[j];
			k = j - h[i];
			while (k >= 0 && aux < a[k])
			{
				a[k + h[i]] = a[k];
				k = k - h[i];
			}
			a[k + h[i]] = aux;
		}
	}
}
void Deplasare(int v[], int N, int i)
{
	int mare = i;
	int stanga = 2 * i + 1;
	int dreapta = 2 * i + 2;
	int aux;

	while (stanga < N)
	{

		if (dreapta < N && v[dreapta] > v[stanga])
			mare = dreapta;
		else
			mare = stanga;


		if (v[i] < v[mare])
		{
			aux = v[i];
			v[i] = v[mare];
			v[mare] = aux;
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
	int aux;
	for (int i = N / 2 - 1; i >= 0; i--)
		Deplasare(v, N, i);
	for (int i = N - 1; i >= 0; i--)
	{
		aux = v[0];
		v[0] = v[i];
		v[i] = aux;
		Deplasare(v, i, 0);
	}
}
void quick_sort(int a[], int s, int d)
{
	int i, j, aux, x;
	i = s;
	j = d;
	x = a[(s + d) / 2]; // Pivotul este ales la mijlocul sub-vectorului
	do
	{
		while (a[i] < x) i++; // G?se?te primul element mai mare sau egal cu pivotul în stânga
		while (a[j] > x) j--; // G?se?te primul element mai mic sau egal cu pivotul în dreapta
		if (i <= j) // Dac? înc? nu s-au întâlnit
		{
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i = i + 1;
			j = j - 1;
		}
	} while (i < j);
	if (s < j) quick_sort(a, s, j); // Apel recursiv pentru sub-vectorul din stânga
	if (d > i) quick_sort(a, i, d); // Apel recursiv pentru sub-vectorul din dreapta
}
int main()
{
	const t = 3;
	int a[100], h[3] = { 3,2,1 }, n;

	printf("Shellsort \n");
	printf("n = ");
	scanf("%d", &n);
	generare(a, n);
	afisare(a, n);
	Shellsort(h, t, a, n);
	afisare(a, n);
	printf("\n");

	printf("Heapsort\n");
	printf("n = ");
	scanf("%d", &n);
	generare(a, n);
	afisare(a, n);
	heapSort(a, n);
	afisare(a, n);
	printf("\n");


	printf("Quicksort\n");
	printf("n = ");
	scanf("%d", &n);
	generare(a, n);
	afisare(a, n);
	quick_sort(a, 0, n - 1);
	afisare(a, n);
	printf("\n");
	system("pause");
	return 0;
}