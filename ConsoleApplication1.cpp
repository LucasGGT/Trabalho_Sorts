

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionsort(int arr[], int n)
{
	int i, chave, j;
	for (i = 1; i < n; i++)
	{
		chave = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > chave)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = chave;
	}
}

void sortear(int arr[], int n)
{
	for (int cont = 0; cont < n; cont++) {
		arr[cont] = rand() % 100;
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
	insertionsort(arr, n);
	tempo = clock() - tempo;
	cout << n << ";" << double(tempo) / CLOCKS_PER_SEC;

	system("pause");
	return 0;
}

