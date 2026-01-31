#include <stdio.h>
#include <string.h>
#include "Student3.h"

int g_count = 0;

void PrintPermutation(int* perm, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(perm + i));
    }
    puts("");
}

void CountPermutation(int* perm, int n) {
    (void)perm;
    (void)n;
    g_count++;
}


int main() {
    /*Test Case 1: Empty array*/
    int arr0[] = {};
    int n0 = 0;
    printf("n = %d, arr = {}\n", n0);
    puts("--- PermutationsJohnsonTrotter ---");
    g_count = 0;
    PermutationsJohnsonTrotter(arr0, n0, CountPermutation);
    printf("Total: %d\n", g_count);

    puts("--- PermutationsHeap ---");
    g_count = 0;
    PermutationsHeap(arr0, n0, CountPermutation);
    printf("Total: %d\n", g_count);

    puts("--- PermutationsMinimalChange ---");
    g_count = 0;
    PermutationsMinimalChange(arr0, n0, CountPermutation);
    printf("Total: %d\n", g_count);

    puts("--- PermutationsCycleLeader ---");
    g_count = 0;
    PermutationsCycleLeader(arr0, n0, CountPermutation);
    printf("Total: %d\n", g_count);

    puts("--- PermutationsBinaryMasks ---");
    g_count = 0;
    PermutationsBinaryMasks(arr0, n0, CountPermutation);
    printf("Total: %d\n", g_count);

    puts("--- PermutationsPseudoLexicographic ---");
    g_count = 0;
    PermutationsPseudoLexicographic(arr0, n0, CountPermutation);
    printf("Total: %d\n", g_count);

    puts("==================================");

    /*Test Case 2: Single element*/
    int arr1[] = { 5 };
    int n1 = 1;
    printf("n = %d, arr = {5}\n", n1);
    puts("--- PermutationsJohnsonTrotter ---");
    PermutationsJohnsonTrotter(arr1, n1, PrintPermutation);

    puts("--- PermutationsHeap ---");
    PermutationsHeap(arr1, n1, PrintPermutation);

    puts("--- PermutationsMinimalChange ---");
    PermutationsMinimalChange(arr1, n1, PrintPermutation);

    puts("--- PermutationsCycleLeader ---");
    PermutationsCycleLeader(arr1, n1, PrintPermutation);

    puts("--- PermutationsBinaryMasks ---");
    PermutationsBinaryMasks(arr1, n1, PrintPermutation);

    puts("--- PermutationsPseudoLexicographic ---");
    PermutationsPseudoLexicographic(arr1, n1, PrintPermutation);

    puts("==================================");

    /*Test Case 3: Two elements*/
    int arr2[] = { 1, 2 };
    int n2 = 2;
    printf("n = %d, arr = {1, 2}\n", n2);
    puts("--- PermutationsJohnsonTrotter ---");
    PermutationsJohnsonTrotter(arr2, n2, PrintPermutation);

    puts("--- PermutationsHeap ---");
    PermutationsHeap(arr2, n2, PrintPermutation);

    puts("--- PermutationsMinimalChange ---");
    PermutationsMinimalChange(arr2, n2, PrintPermutation);

    puts("--- PermutationsCycleLeader ---");
    PermutationsCycleLeader(arr2, n2, PrintPermutation);

    puts("--- PermutationsBinaryMasks ---");
    PermutationsBinaryMasks(arr2, n2, PrintPermutation);

    puts("--- PermutationsPseudoLexicographic ---");
    PermutationsPseudoLexicographic(arr2, n2, PrintPermutation);

    puts("==================================");

    /*Test Case 4: Three elements*/
    int arr3[] = { 3, 1, 2 };
    int n3 = 3;
    printf("n = %d, arr = {3, 1, 2}\n", n3);
    puts("--- PermutationsJohnsonTrotter ---");
    PermutationsJohnsonTrotter(arr3, n3, PrintPermutation);

    puts("--- PermutationsHeap ---");
    PermutationsHeap(arr3, n3, PrintPermutation);

    puts("--- PermutationsMinimalChange ---");
    PermutationsMinimalChange(arr3, n3, PrintPermutation);

    puts("--- PermutationsCycleLeader ---");
    PermutationsCycleLeader(arr3, n3, PrintPermutation);

    puts("--- PermutationsBinaryMasks ---");
    PermutationsBinaryMasks(arr3, n3, PrintPermutation);

    puts("--- PermutationsPseudoLexicographic ---");
    PermutationsPseudoLexicographic(arr3, n3, PrintPermutation);

    puts("==================================");

    /*Test Case 5: Invalid n*/
    int n_invalid = -1;
    printf("n = %d (invalid)\n", n_invalid);
    puts("--- PermutationsJohnsonTrotter ---");
    PermutationsJohnsonTrotter(arr3, n_invalid, PrintPermutation);

    puts("--- PermutationsHeap ---");
    PermutationsHeap(arr3, n_invalid, PrintPermutation);

    puts("--- PermutationsMinimalChange ---");
    PermutationsMinimalChange(arr3, n_invalid, PrintPermutation);

    puts("--- PermutationsCycleLeader ---");
    PermutationsCycleLeader(arr3, n_invalid, PrintPermutation);

    puts("--- PermutationsBinaryMasks ---");
    PermutationsBinaryMasks(arr3, n_invalid, PrintPermutation);

    puts("--- PermutationsPseudoLexicographic ---");
    PermutationsPseudoLexicographic(arr3, n_invalid, PrintPermutation);

    puts("==================================");

    /*Test Case 6: Large n*/
    int arr_large[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int n_large = 12;
    printf("n = %d (max valid)\n", n_large);
    puts("--- PermutationsHeap (count only) ---");
    g_count = 0;
    PermutationsHeap(arr_large, n_large, CountPermutation);
    printf("Total permutations generated: %d\n", g_count);

    return 0;
}