#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <random>

#include "Sorter.h"
#include "utils.h"

using namespace std;
using namespace chrono;

int main() {
	Sorter<int> sorter;
	default_random_engine rand(time(nullptr));

	cout << "Random Order:" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		int* arr = new int[SIZES[i]];

		for (int j = 0; j < SIZES[i]; j++) {
			arr[j] = j;
		}

		shuffle(arr, arr + SIZES[i], rand);

#if DEBUG == 1
		cout << "[";
		for (int j = 0; j < SIZES[i]; j++) {
			cout << arr[j];

			if (j < SIZES[i] - 1) {
				cout << ", ";
			}
		}
		cout << "]" << endl;
#endif

		double start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

		sorter.insertion_sort(arr, SIZES[i]);

		double end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
		cout << SIZES[i] << ": " << end - start << "ns" << endl;

#if DEBUG == 1
		cout << "[";
		for (int j = 0; j < SIZES[i]; j++) {
			cout << arr[j];

			if (j < SIZES[i] - 1) {
				cout << ", ";
			}
		}
		cout << "]" << endl;
#endif

		delete[] arr;
	}

	cout << "Reverse Order:" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		int* arr = new int[SIZES[i]];

		for (int j = 0; j < SIZES[i]; j++) {
			arr[j] = SIZES[i] - j;
		}

		double start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

		sorter.insertion_sort(arr, SIZES[i]);

		double end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
		cout << SIZES[i] << ": " << end - start << "ns" << endl;

		delete[] arr;
	}

	cout << "Almost Sorted:" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		int* arr = new int[SIZES[i]];

		// Perform random swaps for 10% of the array
		for (int j = 0; j < SIZES[i] / 10; j++) {
			int a = rand() % SIZES[i], b = rand() % SIZES[i];

			int temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}

		double start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

		sorter.insertion_sort(arr, SIZES[i]);

		double end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
		cout << SIZES[i] << ": " << end - start << "ns" << endl;

		delete[] arr;
	}

	return 0;
}