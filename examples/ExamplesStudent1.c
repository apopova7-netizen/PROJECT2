#include "Student1.h"

int g_countA = 0;
int g_countB = 0;

void PrintPermutation(int perm[], int n) {
    if (n <= 0) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", perm[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void LimitedPrint7(int perm[], int n) {
    if (g_countA < 7) {
        PrintPermutation(perm, n);
        g_countA++;
    }
}

void CountOnly(int perm[], int n) {
    (void)perm; 
    (void)n;    
    g_countB++;
}

bool Constraint(int partial[], int k, int nextElem, void* data) {
    (void)partial; 
    (void)data;    
    
    if (nextElem == 3 && k == 1) {
        return false;
    }
    return true;
}

int main() {
    int arr0[] = {};
    int n0 = sizeof(arr0) / sizeof(int);
    
    printf("n = %d, arr = {}\n", n0);
    puts("PermutationsBacktrack:");
    PermutationsBacktrack(arr0, n0, PrintPermutation);
    puts("PermutationsRecursiveSwap:");
    PermutationsRecursiveSwap(arr0, n0, PrintPermutation);
    puts("PermRecursiveLexicographic:");
    PermRecursiveLexicographic(arr0, n0, PrintPermutation);
    puts("MultisetPermutations:");
    MultisetPermutations(arr0, n0, PrintPermutation);
    
    puts("===================================================================================");

    int arr1[] = {7};
    int n1 = sizeof(arr1) / sizeof(int);
    
    printf("n = %d, arr = {7}\n", n1);
    puts("PermutationsBacktrack:");
    PermutationsBacktrack(arr1, n1, PrintPermutation);
    puts("PermutationsRecursiveSwap:");
    PermutationsRecursiveSwap(arr1, n1, PrintPermutation);
    puts("PermRecursiveLexicographic:");
    PermRecursiveLexicographic(arr1, n1, PrintPermutation);
    puts("MultisetPermutations:");
    MultisetPermutations(arr1, n1, PrintPermutation);
    
    puts("===================================================================================");

    int arr2[] = {4, 6};
    int n2 = sizeof(arr2) / sizeof(int);
    
    printf("n = %d, arr = {4, 6}\n", n2);
    puts("PermutationsBacktrack:");
    PermutationsBacktrack(arr2, n2, PrintPermutation);
    puts("PermutationsRecursiveSwap:");
    PermutationsRecursiveSwap(arr2, n2, PrintPermutation);
    puts("PermRecursiveLexicographic:");
    PermRecursiveLexicographic(arr2, n2, PrintPermutation);
    puts("MultisetPermutations:");
    MultisetPermutations(arr2, n2, PrintPermutation);
    
    puts("===================================================================================");

    int arr3[] = {9, 5, 2};
    int n3 = sizeof(arr3) / sizeof(int);
    
    printf("n = %d, arr = {9, 5, 2}\n", n3);
    puts("PermutationsBacktrack:");
    PermutationsBacktrack(arr3, n3, PrintPermutation);
    puts("PermutationsRecursiveSwap:");
    PermutationsRecursiveSwap(arr3, n3, PrintPermutation);
    puts("PermRecursiveLexicographic (sorted lexicographically):");
    PermRecursiveLexicographic(arr3, n3, PrintPermutation);
    puts("MultisetPermutations:");
    MultisetPermutations(arr3, n3, PrintPermutation);
    
    puts("===================================================================================");

    int arr4[] = {1, 3, 3};
    int n4 = sizeof(arr4) / sizeof(int);
    
    printf("n = %d, arr = {1, 3, 3} (a multiset)\n", n4);
    puts("PermutationsBacktrack (all permutations, including duplicates):");
    PermutationsBacktrack(arr4, n4, PrintPermutation);
    puts("MultisetPermutations (only unique permutations):");
    MultisetPermutations(arr4, n4, PrintPermutation);
    
    puts("===================================================================================");

    int arr5[] = {1, 2, 3, 7};
    int n5 = sizeof(arr5) / sizeof(int);
    
    printf("n = %d, arr = {1, 2, 3, 7}\n", n5);
    puts("PermutationsBacktrack (the first 7 of 24 permutations):");
    
    g_countA = 0; 
    PermutationsBacktrack(arr5, n5, LimitedPrint7);
    printf("... and another %d permutations\n", 24 - 7);
    
    puts("===================================================================================");

    int arrNegative[] = {};
    int nNegative = -9;
    
    printf("n = %d, arr = {} (negative size)\n", nNegative);
    puts("PermutationsBacktrack:");
    PermutationsBacktrack(arrNegative, nNegative, PrintPermutation);
    puts("PermutationsRecursiveSwap:");
    PermutationsRecursiveSwap(arrNegative, nNegative, PrintPermutation);
    
    puts("===================================================================================");

    printf("n = 3, arr = NULL\n");
    puts("PermutationsBacktrack:");
    PermutationsBacktrack(NULL, 3, PrintPermutation);
    puts("PermutationsRecursiveSwap:");
    PermutationsRecursiveSwap(NULL, 3, PrintPermutation);
    
    puts("===================================================================================");

    int arr6[] = {1, 2, 3, 4};
    int n6 = sizeof(arr6) / sizeof(int);
    
    printf("n = %d, arr = {1, 2, 3, 4} with constraints\n", n6);
    
    puts("PermutationsWithConstraints (3 can't be the second one):");
    PermutationsWithConstraints(arr6, n6, Constraint, NULL, PrintPermutation);
    
    puts("===================================================================================");

    int arr7[] = {5, 8, 2, 1};
    int n7 = sizeof(arr7) / sizeof(int);
    
    printf("n = %d, arr = {5, 8, 2, 1}\n", n7);
    puts("PermutationsRecursiveSwap (in-place method):");
    PermutationsRecursiveSwap(arr7, n7, PrintPermutation);
    
    puts("===================================================================================");

    int arr8[] = {2, 1, 3};
    int n8 = sizeof(arr8) / sizeof(int);
    
    printf("n = %d, arr = {2, 1, 3} - comparison of methods\n", n8);
    
    puts("1. PermutationsBacktrack (the method with a refund):");
    PermutationsBacktrack(arr8, n8, PrintPermutation);
    
    puts("\n2. PermutationsRecursiveSwap (The exchange method):");
    PermutationsRecursiveSwap(arr8, n8, PrintPermutation);
    
    puts("\n3. PermRecursiveLexicographic (lexicographic):");
    PermRecursiveLexicographic(arr8, n8, PrintPermutation);
    
    puts("\n4. MultisetPermutations (for unique ones):");
    MultisetPermutations(arr8, n8, PrintPermutation);
    
    puts("===================================================================================");

    int arr9[] = {1, 1, 2, 2};
    int n9 = sizeof(arr9) / sizeof(int);
    
    printf("n = %d, arr = {1, 1, 2, 2} (a multiset with repeats)\n", n9);
    
    puts("PermutationsBacktrack (all combinations, lots of duplicates):");
    g_countB = 0; 
    PermutationsBacktrack(arr9, n9, CountOnly);
    printf("Total permutations (with duplicates): %d\n", g_countB);
    
    puts("\nMultisetPermutations (only unique ones):");
    g_countB = 0; 
    MultisetPermutations(arr9, n9, CountOnly);
    printf("Unique permutations: %d\n", g_countB);
    
    puts("===================================================================================");

    int arr10[] = {1, 2, 3, 4, 5};
    int n10 = sizeof(arr10) / sizeof(int);
    
    printf("n = %d, arr = {1, 2, 3, 4, 5}\n", n10);
    puts("Counting permutations using different methods:");
    
    g_countB = 0;
    PermutationsBacktrack(arr10, n10, CountOnly);
    printf("PermutationsBacktrack: %d permutations\n", g_countB);
    
    g_countB = 0;
    PermutationsRecursiveSwap(arr10, n10, CountOnly);
    printf("PermutationsRecursiveSwap: %d permutations\n", g_countB);
    
    g_countB = 0;
    PermRecursiveLexicographic(arr10, n10, CountOnly); 
    printf("PermRecursiveLexicographic: %d permutations\n", g_countB);
    
    puts("===================================================================================");

    return 0;
}
