#ifndef UTILS_H
#define UTILS_H

#define DEBUG 0
#define NUM_SIZES 6

int SIZES[] = {10, 1000, 10000, 100000, 200000, 500000};

template <typename T>
bool sorted(T* arr, unsigned int n);

#include "utils.hpp"

#endif