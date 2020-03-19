void heapPush(int* v, int& n, int x) {
	int i = n;
	v[n++] = x;
	while (i > 0 && v[(i - 1) / 2] > v[i]) {
		int aux = v[(i - 1) / 2];
		v[(i - 1) / 2] = v[i];
		v[i] = aux;
		i = (i - 1) / 2;
	}
}

int heapPop(int* v, int& n) {
	int x = v[0];
	int i = 0;
	v[0] = v[n - 1];
	n--;
	while (2 * i + 1 < n) {
		if (2 * i + 2 < n && v[2 * i + 2] < v[2 * i + 1]) {
			int aux = v[i];
			v[i] = v[2 * i + 2];
			v[2 * i + 2] = aux;
			i = 2 * i + 2;
		}
		else {
			int aux = v[i];
			v[i] = v[2 * i + 1];
			v[2 * i + 1] = aux;
			i = 2 * i + 1;
		}
	}

	return x;
}

void heapify(int* v, int n) {
	int* aux = new int[n];
	int i = 0;
	while (i < n)
		heapPush(aux, i, v[i]);
	for (int i = 0; i < n; i++)
		v[i] = aux[i];
	delete[] aux;
}