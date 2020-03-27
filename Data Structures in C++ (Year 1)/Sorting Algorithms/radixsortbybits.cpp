// sorting by groups of 8 bits
void countingSortByBits(int* v, int n, int nthSetOfEightBytes) {
	int freq[256];
	for (int i = 0; i < 256; i++)
		freq[i] = 0;

	for (int i = 0; i < n; i++)
		freq[v[i] >> (8 * nthSetOfEightBytes) & 255]++;
	for (int j = 1; j < 256; j++)
		freq[j] += freq[j - 1];

	int* aux = new int[n];
	for (int i = n - 1; i >= 0; i--) {
		aux[freq[v[i] >> (8 * nthSetOfEightBytes) & 255] - 1] = v[i];
		freq[v[i] >> (8 * nthSetOfEightBytes) & 255]--;
	}

	for (int i = 0; i < n; i++)
		v[i] = aux[i];

	delete[] aux;
}

// sorting from the least significant 8 bits to the most significant 8 bits
void radixSortByBits(int* v, int n) {
	for (int k = 0; k < sizeof(int); k++)
		countingSortByBits(v, n, k);
}
