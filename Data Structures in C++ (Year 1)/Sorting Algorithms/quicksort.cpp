long partition(int* v, int left, int right) {
	long i = left, j = right, x = v[left];
	while (i < j) {
		while (i < j && v[j] >= x)
			j--;
		v[i] = v[j];
		while (i < j && v[i] <= x)
			i++;
		v[j] = v[i];
	}
	v[i] = x;
	return i;
}

void quickSort(int* v, int left, int right) {
	int m = partition(v, left, right);
	if (m > left + 1)
		quickSort(v, left, m - 1);
	if (m < right - 1)
		quickSort(v, m + 1, right);
}
