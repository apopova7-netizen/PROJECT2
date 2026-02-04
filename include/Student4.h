#ifndef STUDENT4_H
#define STUDENT4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "Student1.h"
#include "Student2.h"
#include "Student3.h"

// full list of methods
typedef enum {
    // Student 1
    PERM_BACKTRACK,
    PERM_SWAP,
    PERM_LEX_RECURSIVE,
    PERM_CONSTRAINED,
    PERM_MULTISET,
    // Student 2
    PERM_NARAYANA,
    PERM_FACTORIAL_SYSTEM,
    PERM_INVERSION_TABLE,
    PERM_PLUS_ONE,
    // Student 3
    PERM_JOHNSON_TROTTER,
    PERM_HEAP,
    PERM_MINIMAL_CHANGE, 
    PERM_CYCLE_LEADER,
    PERM_BINARY_MASKS,
    PERM_PSEUDO_LEX
} PermutationMethod;

// the structure of the parameters
typedef struct {
    PermutationMethod method;
    void (*callback)(int* perm, int n);
    // Additional information
    bool (*constraint)(int* partial, int k, int nextElem, void* data);
    void* constraintData;
    int direction; 
} PermutationParams;

// main function
void ExecutePermutation(int arr[], int n, PermutationParams params);
// Benchmark function
void AllPermutationBenchmark(int n);
void PermutationBenchmark(int* arr, int n, PermutationParams params);
// adaptive selection
void ExecuteAdaptivePermute(int arr[], int n, void (*callback)(int*, int));

#endif
