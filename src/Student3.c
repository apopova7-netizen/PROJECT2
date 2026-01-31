#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * TASK 3.1: Johnson-Trotter algorithm
 * Generates permutations by moving the largest mobile element.
 */
void PermutationsJohnsonTrotter(int arr[], int n,
    void (*callback)(int* perm, int n))
{
    if (n <= 0 || callback == NULL) 
        return;

    int* dir = malloc(n * sizeof(int));
    int* pos = malloc(n * sizeof(int));

    if (!dir || !pos) {
        puts("Memory allocation error");
        free(dir);
        free(pos);
        return;
    }

    /*Initialize directions(left = -1) and positions*/
    for (int i = 0; i < n; i++) {
        *(dir + i) = -1;
        *(pos + i) = i;
    }

    callback(arr, n);

    while (1) {
        int largestMobile = -1;
        int mobileIndex = -1;

        /*Find the largest mobile element*/
        for (int i = 0; i < n; i++) {
            int currentPos = *(pos + i);
            int nextPos = currentPos + *(dir + i);

            if (nextPos >= 0 && nextPos < n &&
                *(arr + currentPos) > *(arr + nextPos))
                if (*(arr + currentPos) > largestMobile) {
                    largestMobile = *(arr + currentPos);
                    mobileIndex = i;
                }
        }

        if (mobileIndex == -1) 
            break;

        /*Move the mobile element*/
        int oldPos = *(pos + mobileIndex);
        int newPos = oldPos + *(dir + mobileIndex);

        Swap(arr + oldPos, arr + newPos);
        *(pos + mobileIndex) = newPos;

        /*Reverse directions of all elements larger than the mobile element*/
        for (int i = 0; i < n; i++)
            if (*(arr + i) > largestMobile)
                *(dir + i) = -*(dir + i);

        callback(arr, n);
    }

    free(dir);
    free(pos);
}

/*
 * TASK 3.2: Heap's algorithm (non-recursive)
 * Generates permutations with minimal swaps.
 */
void PermutationsHeap(int arr[], int n,
    void (*callback)(int* perm, int n))
{
    if (n <= 0 || callback == NULL) 
        return;

    int* c = calloc(n, sizeof(int));
    if (!c) {
        puts("Memory allocation error");
        return;
    }

    callback(arr, n);

    int i = 0;
    while (i < n) {
        if (*(c + i) < i) {
            if (i % 2 == 0)
                Swap(arr, arr + i);
            else
                Swap(arr + *(c + i), arr + i);
            callback(arr, n);
            (*(c + i))++;
            i = 0;
        }
        else {
            *(c + i) = 0;
            i++;
        }
    }

    free(c);
}

/*
 * TASK 3.3: Minimal-change permutation generation (Ehrlich's algorithm)
 * Each step differs by a single adjacent transposition.
 */
void PermutationsMinimalChange(int arr[], int n,
    void (*callback)(int* perm, int n))
{
    if (n <= 0 || callback == NULL) 
        return;

    int* c = malloc(n * sizeof(int));
    if (!c) {
        puts("Memory allocation error");
        return;
    }

    for (int i = 0; i < n; i++)
        *(c + i) = 0;

    callback(arr, n);

    int k = 1;
    while (k < n) {
        if (*(c + k) < k) {
            int j = (k % 2 == 0) ? 0 : *(c + k);
            Swap(arr + j, arr + j + 1);
            callback(arr, n);
            (*(c + k))++;
            k = 1;
        }
        else {
            *(c + k) = 0;
            k++;
        }
    }

    free(c);
}

/*
 * TASK 3.4: Cycle leader algorithm
 * Cycles elements to generate permutations.
 */
void PermutationsCycleLeader(int arr[], int n,
    void (*callback)(int* perm, int n))
{
    if (n <= 0 || callback == NULL) 
        return;

    callback(arr, n);

    for (int shift = 1; shift < n; shift++) {
        int temp = *arr;
        for (int i = 0; i < n - 1; i++)
            *(arr + i) = *(arr + i + 1);
        *(arr + n - 1) = temp;
        callback(arr, n);
    }
}

/*
 * TASK 3.5: Binary mask permutation generation
 * Generates permutations using factorial number system.
 */
void PermutationsBinaryMasks(int arr[], int n,
    void (*callback)(int* perm, int n))
{
    if (n <= 0 || n > 16 || callback == NULL) 
        return;

    int total = 1;
    for (int i = 2; i <= n; i++) 
        total *= i;

    int* temp = malloc(n * sizeof(int));
    int* used = malloc(n * sizeof(int));

    if (!temp || !used) {
        puts("Memory allocation error");
        free(temp);
        free(used);
        return;
    }

    for (int idx = 0; idx < total; idx++) {
        int val = idx;
        for (int i = 0; i < n; i++)
            *(used + i) = 0;

        for (int i = 0; i < n; i++) {
            int fact = 1;
            for (int j = 2; j <= n - 1 - i; j++) fact *= j;
            if (fact == 0) fact = 1;

            int chosen = val / fact;
            val %= fact;

            int skip = 0;
            int j = 0;
            while (skip <= chosen) {
                if (*(used + j) == 0)
                    skip++;
                j++;
            }
            j--;

            *(used + j) = 1;
            *(temp + i) = *(arr + j);
        }

        for (int i = 0; i < n; i++)
            *(arr + i) = *(temp + i);
        callback(arr, n);
    }

    free(temp);
    free(used);
}

/*
 * TASK 3.6: Pseudo-lexicographic permutation generation
 * Fast generation with near-lexicographic order.
 */
void PermutationsPseudoLexicographic(int arr[], int n,
    void (*callback)(int* perm, int n))
{
    if (n <= 0 || callback == NULL) 
        return;

    callback(arr, n);

    while (1) {
        int i = n - 2;
        while (i >= 0 && *(arr + i) >= *(arr + i + 1)) 
            i--;

        if (i < 0) 
            break;

        int j = n - 1;
        while (*(arr + j) <= *(arr + i)) 
            j--;

        Swap(arr + i, arr + j);

        int low = i + 1;
        int high = n - 1;
        while (low < high) {
            Swap(arr + low, arr + high);
            low++;
            high--;
        }

        callback(arr, n);
    }
}