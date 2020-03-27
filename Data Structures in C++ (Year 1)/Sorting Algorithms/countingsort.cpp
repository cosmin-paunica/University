void countingSort(int* v, int n) {
	int min = v[0], max = v[0];
	for (int i = 1; i < n; i++)
		if (v[i] < min)
			min = v[i];
		else if (v[i] > max)
			max = v[i];

	int range = max - min;
	int* freq = new int[range + 1];
	for (int j = 0; j <= range; j++)
		freq[j] = 0;
	for (int i = 0; i < n; i++)
		freq[v[i] - min]++;

	for (int j = 1; j <= range; j++)
		freq[j] += freq[j - 1];

	int* aux = new int[n];
	for (int i = 0; i < n; i++) {
		aux[freq[v[i] - min] - 1] = v[i];
		freq[v[i] - min]--;
	}
	for (int i = 0; i < n; i++)
		v[i] = aux[i];

	delete[] freq;
	delete[] aux;
}
