#ifndef SORTER_H
#define SORTER_H

#include <cassert>

#include "utils.h"

template <class T>
class Sorter {
public:
	Sorter() {}

	void insertion_sort(T* arr, unsigned int size);
};

#include "Sorter.hpp"

#endif