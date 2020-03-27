#include <cmath>

void countingSortByDigit(int* v, int n, int nthDigit) {
	int* freq = new int[10];
	int exp = pow(10, nthDigit - 1);
	for (int i = 0; i < 10; i++)
		freq[i] = 0;
	for (int i = 0; i < n; i++)
		freq[(v[i] / exp) % 10]++;

	for (int j = 1; j < 10; j++)
		freq[j] += freq[j - 1];

	int* aux = new int[n];
	for (int i = n - 1; i >= 0; i--) {
		aux[freq[(v[i] / exp) % 10] - 1] = v[i];
		freq[(v[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++)
		v[i] = aux[i];

	delete[] freq;
	delete[] aux;
}

void radixSort(int* v, int n) {
	int max = v[0];
	for (int i = 1; i < n; i++)
		if (v[i] > max)
			max = v[i];
	int maxNoOfDigits = 0;
	while (max > 0) {
		maxNoOfDigits++;
		max /= 10;
	}

	for (int i = 1; i <= maxNoOfDigits; i++)
		countingSortByDigit(v, n, i);
}