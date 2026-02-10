#ifndef STUDENT1_H
#define STUDENT1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct PositionConstraint {
    int element;
    int position;
} PosConstraint;

typedef struct RelativeConstraint {
    int elemA;
    int elemB;
} RelConstraint;

typedef struct ConstraintData {
    PosConstraint* posConstraints;
    size_t numPosConstraints;
    RelConstraint* relConstraints;
    size_t numRelConstraints;
} ConstraintData;

#define MAX_CACHE_SIZE 1000

typedef struct CacheElem {
    char key[256];
    long value;
} CacheElem;

extern CacheElem cache[MAX_CACHE_SIZE];
extern int cacheSize;

void Swap(int *a, int *b);
void Generate(int* arr, int n, int* curPerm, int depth, 
              char* used, void (*callback)(int*, int));
void PermutationsBacktrack(int arr[], int n, 
                           void (*callback)(int perm[], int n));
void GenerateSwap(int arr[], int n, int depth, 
                  void (*callback)(int perm[], int n));
void PermutationsRecursiveSwap(int arr[], int n,
                               void (*callback)(int perm[], int n));
void QuickSort(int arr[], int left, int right);
void GeneratePermutations(int arr[], int start, int end, 
                          void (*callback)(int perm[], int size));
void PermRecursiveLexicographic(int arr[], int n,
                                void (*callback)(int perm[], int n));
bool CheckConstraint(int partial[], int k, int nextElem, void* data);
void GeneratePerm(int arr[], int n, int depth, int used[], 
                  int curPerm[], bool (*constraint)(int partial[],
                  int k, int next_elem, void* data),
                  void* constraintData, void (*callback)(int perm[], int n));
void PermutationsWithConstraints(int arr[], int n,
                                 bool (*constraint)(int partial[], int k, 
                                 int nextElem, void* data),
                                 void* constraintData,
                                 void (*callback)(int perm[], int n));
long FindInCache(char *key);
void SaveToCache(char *key, long value);
long Factorial(long n);
long CountUniquePermutations(int arr[], int n);
void GeneratePermutationsRecursive(int freq[], int maxVal, int depth, int len,
                                   int cur[], void (*callback)(int [], int));
void MultisetPermutations(int arr[], int n, 
                         void (*callback)(int perm[], int n));

#endif  /* STUDENT1_H */ 
