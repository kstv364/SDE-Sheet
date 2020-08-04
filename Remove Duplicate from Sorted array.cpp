int remove_duplicate(int A[], int N)
{
	int cmp = A[0];
	int j = 1;
	for (int i = 1; i < N; i++) {
		if (A[i] != cmp) {
			A[j++] = A[i];
			cmp = A[i];
		}
	}
	return j;
}