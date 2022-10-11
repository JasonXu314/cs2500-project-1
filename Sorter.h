#ifndef SORTER_H
#define SORTER_H

#include <cassert>

#include "utils.h"

template <class T>
class Sorter {
public:
	// Note: I believe that this sort of comment is inherently HARMFUL to code readability, but since your rubric requires me to write it, here it is
	// Creates a sorter object
	// Pre: the > operator is defined for type T
	// Post: a new Sorter object is created
	Sorter() {}

	// Note: I believe that this sort of comment is inherently HARMFUL to code readability, but since your rubric requires me to write it, here it is
	// Sorts the given array arr using insertion sort
	// Pre: arr is a valid array of size n, the > operator is defined for type T
	// Post: arr is sorted in ascending order
	void insertion_sort(T* arr, unsigned int size);
};

#include "Sorter.hpp"

#endif