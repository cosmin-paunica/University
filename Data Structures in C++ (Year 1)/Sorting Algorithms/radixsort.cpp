#include <cmath>

void countingSortByDigit(int* v, int n, int i) {
	int* freq = new int[10];
	int exp = pow(10, i - 1);
	for (int j = 0; j < 10; j++)
		freq[j] = 0;
	for (int i = 0; i < n; i++)
		freq[(v[i] / exp) % 10]++;

	for (int j = 1; j < 10; j++)
		freq[j] += freq[j - 1];

	int* aux = new int[n];
	for (int i = n - 1; i >= 0; i--) {		// parcurgerea se face invers pentru ca sortarea sa fie stabila
		aux[freq[(v[i] / exp) % 10] - 1] = v[i];
		freq[(v[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++)
		v[i] = aux[i];

	delete[] freq;
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