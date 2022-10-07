template <class T>
void Sorter<T>::insertion_sort(T* arr, unsigned int size) {
	// Outer loop invariant is that the array is sorted up to the current index

#if DEBUG == 1
	assert(sorted(arr, 1));	 // 1 is the initial value of j
#endif

	for (unsigned int j = 1; j < size; j++) {
#if DEBUG == 1
		assert(sorted(arr, j));	 // the array is sorted up to (but not including) j
#endif

		T elem = arr[j];
		int i = j - 1;

		for (; i >= 0 && arr[i] > elem; i--) {
			arr[i + 1] = arr[i];
		}

		arr[i + 1] = elem;

#if DEBUG == 1
		assert(sorted(arr, j));	 // the array is still sorted up to j
#endif
	}

#if DEBUG == 1
	assert(sorted(arr, size));	// the array is now fully sorted (array is sorted up to size)
#endif
}