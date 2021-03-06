

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void selectionSort(int arr[], int n)
{
	int i, j, min_ind;

	for (i = 0; i < n - 1; i++)
	{
		min_ind = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_ind])
				min_ind = j;

		swap(arr[min_ind], arr[i]);
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
	selectionSort(arr, n);
	tempo = clock() - tempo;
	cout << n << ";" << double(tempo) / CLOCKS_PER_SEC;

	system("pause");
	return 0;
}
