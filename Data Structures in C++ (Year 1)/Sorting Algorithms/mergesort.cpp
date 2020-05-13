void merge(int* v, int left, int mid, int right) {
	int* w = new int[right-left+1];
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
		if (v[i] < v[j])
			w[k++] = v[i++];
		else
			w[k++] = v[j++];
	while (i <= mid)
		w[k++] = v[i++];
	while (j <= right)
		w[k++] = v[j++];
	for (k = 0; k < right - left + 1; k++)
		v[k + left] = w[k];
}

void mergeSort(int* v, int left, int right) {
	if (right > left) {
		int mid = (right + left) / 2;
		mergeSort(v, left, mid);
		mergeSort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
}
