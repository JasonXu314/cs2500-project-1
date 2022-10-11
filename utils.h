#ifndef UTILS_H
#define UTILS_H

#define DEBUG 0
#define NUM_SIZES 6

int SIZES[] = {10, 1000, 10000, 100000, 200000, 500000};

// Tests whether the array is sorted in ascending order on the interval [0, n)
template <typename T>
bool sorted(T* arr, unsigned int n);

// Tests whether the array is sorted in ascending order on the interval [a, b)
template <typename T>
bool sorted(T* arr, unsigned int a, unsigned int b);

double averageTimes(double* times, unsigned int n);

#include "utils.hpp"

#endif