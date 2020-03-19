#include "minheap.h"

void heapSort(int* v, int n) {
	int* h = new int[n];
	for (int i = 0; i < n; i++)
		h[i] = v[i];
	heapify(h, n);
	
	int i = n;
	while (i)
		v[i] = heapPop(h, i);
	delete[] h;

	for (int i = 0; i < n / 2; i++) {
		int aux = v[i];
		v[i] = v[n - i - 1];
		v[n - i - 1] = aux;
	}
}