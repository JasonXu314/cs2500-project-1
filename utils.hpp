template <typename T>
bool sorted(T* arr, unsigned int n) {
	for (unsigned int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}

	return true;
}