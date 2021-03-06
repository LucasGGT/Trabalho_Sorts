//Quicksort

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int particao(int arr[], int menor, int maior)
{
	int pivo = arr[maior]; 
	int i = (menor - 1); 

	for (int j = menor; j <= maior - 1; j++)
	{ 
		if (arr[j] <= pivo)
		{
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[maior]);
	return (i + 1);
}

void quickSort(int arr[], int menor, int maior)
{
	if (menor < maior)
	{
		int pi = particao(arr, menor, maior);

		quickSort(arr, menor, pi - 1);
		quickSort(arr, pi + 1, maior);
	}
}

void sortear(int arr[], int n) 
{
	for (int cont = 0; cont < n; cont++) {
		arr[cont] = rand() % n;
	}
}
 
int main()
{
	setlocale(LC_ALL, "portuguese");
	srand(time(NULL));
	clock_t tempo;

	int arr[1000] = {0};
	int n = sizeof(arr) / sizeof(arr[0]);
	sortear(arr, n);

	tempo = clock();
	quickSort(arr, 0, n - 1);
	tempo = (clock() - tempo);
	cout << n << ";" << double(tempo) / CLOCKS_PER_SEC;

	system("pause");
	return 0;
}
