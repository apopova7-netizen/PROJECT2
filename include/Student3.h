#ifndef PROJECT2_STUDENT3_H
#define PROJECT2_STUDENT3_H

#include <stdlib.h>
#include <stdint.h>

void PermutationsJohnsonTrotter(int arr[], int n,
    void (*callback)(int* perm, int n));

void PermutationsHeap(int arr[], int n,
    void (*callback)(int* perm, int n));

void PermutationsMinimalChange(int arr[], int n,
    void (*callback)(int* perm, int n));

void PermutationsCycleLeader(int arr[], int n,
    void (*callback)(int* perm, int n));

void PermutationsBinaryMasks(int arr[], int n,
    void (*callback)(int* perm, int n));

void PermutationsPseudoLexicographic(int arr[], int n,
    void (*callback)(int* perm, int n));

#endif //PROJECT2_STUDENT3_H
