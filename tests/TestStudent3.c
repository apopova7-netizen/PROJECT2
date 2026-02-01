#include <stdio.h>
#include <string.h>
#include "Student3.h"

int TestsPassed = 0;
int TestsFailed = 0;

#define START(name) printf("\nTesting the %s function\n\n", name)
#define CHECK(condition, message) \
    do { \
        if (!(condition)) { \
            printf("Test failed: %s\n", message); \
            TestsFailed++; \
            return 1; \
        } else \
            printf("%s\n", message); \
    } while(0)

#define END() \
    do { \
        TestsPassed++; \
        printf("Test passed\n\n"); \
        return 0; \
    } while(0)

int CallbackCounter = 0;

void CountingCallback(int* perm, int n) {
    (void)perm;
    (void)n;
    CallbackCounter++;
}

int TestPermutationsJohnsonTrotter() {
    int arr[] = { 1, 2, 3 };
    int arr_single[] = { 5 };

    START("PermutationsJohnsonTrotter");

    CallbackCounter = 0;
    PermutationsJohnsonTrotter(arr, 3, CountingCallback);
    CHECK(CallbackCounter == 6, "There should be 6 permutations for 3 elements");

    CallbackCounter = 0;
    PermutationsJohnsonTrotter(arr_single, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "Single element should produce 1 permutation");

    CallbackCounter = 0;
    PermutationsJohnsonTrotter(NULL, 0, CountingCallback);  // Передаём NULL и n=0
    CHECK(CallbackCounter == 0, "Empty array should produce 0 permutations");

    END();
}

int TestPermutationsHeap() {
    int arr[] = { 1, 2, 3 };
    int arr_single[] = { 5 };

    START("PermutationsHeap");

    CallbackCounter = 0;
    PermutationsHeap(arr, 3, CountingCallback);
    CHECK(CallbackCounter == 6, "There should be 6 permutations for 3 elements");

    CallbackCounter = 0;
    PermutationsHeap(arr_single, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "Single element should produce 1 permutation");

    CallbackCounter = 0;
    PermutationsHeap(NULL, 0, CountingCallback);
    CHECK(CallbackCounter == 0, "Empty array should produce 0 permutations");

    END();
}

int TestPermutationsMinimalChange() {
    int arr[] = { 1, 2, 3 };
    int arr_single[] = { 5 };

    START("PermutationsMinimalChange");

    CallbackCounter = 0;
    PermutationsMinimalChange(arr, 3, CountingCallback);
    CHECK(CallbackCounter == 6, "There should be 6 permutations for 3 elements");

    CallbackCounter = 0;
    PermutationsMinimalChange(arr_single, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "Single element should produce 1 permutation");

    CallbackCounter = 0;
    PermutationsMinimalChange(NULL, 0, CountingCallback);
    CHECK(CallbackCounter == 0, "Empty array should produce 0 permutations");

    END();
}

int TestPermutationsCycleLeader() {
    int arr[] = { 1, 2, 3 };
    int arr_single[] = { 5 };

    START("PermutationsCycleLeader");

    CallbackCounter = 0;
    PermutationsCycleLeader(arr, 3, CountingCallback);
    CHECK(CallbackCounter == 3, "Cycle leader generates 3 shifts for 3 elements");

    CallbackCounter = 0;
    PermutationsCycleLeader(arr_single, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "Single element should produce 1 permutation");

    CallbackCounter = 0;
    PermutationsCycleLeader(NULL, 0, CountingCallback);
    CHECK(CallbackCounter == 0, "Empty array should produce 0 permutations");

    END();
}

int TestPermutationsBinaryMasks() {
    int arr[] = { 1, 2, 3 };
    int arr_single[] = { 5 };

    START("PermutationsBinaryMasks");

    CallbackCounter = 0;
    PermutationsBinaryMasks(arr, 3, CountingCallback);
    CHECK(CallbackCounter == 6, "There should be 6 permutations for 3 elements");

    CallbackCounter = 0;
    PermutationsBinaryMasks(arr_single, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "Single element should produce 1 permutation");

    CallbackCounter = 0;
    PermutationsBinaryMasks(NULL, 0, CountingCallback);
    CHECK(CallbackCounter == 0, "Empty array should produce 0 permutations");

    END();
}

int TestPermutationsPseudoLexicographic() {
    int arr[] = { 1, 2, 3 };
    int arr_single[] = { 5 };

    START("PermutationsPseudoLexicographic");

    CallbackCounter = 0;
    PermutationsPseudoLexicographic(arr, 3, CountingCallback);
    CHECK(CallbackCounter == 6, "There should be 6 permutations for 3 elements");

    CallbackCounter = 0;
    PermutationsPseudoLexicographic(arr_single, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "Single element should produce 1 permutation");

    CallbackCounter = 0;
    PermutationsPseudoLexicographic(NULL, 0, CountingCallback);
    CHECK(CallbackCounter == 0, "Empty array should produce 0 permutations");

    END();
}

int main() {
    TestPermutationsJohnsonTrotter();
    TestPermutationsHeap();
    TestPermutationsMinimalChange();
    TestPermutationsCycleLeader();
    TestPermutationsBinaryMasks();
    TestPermutationsPseudoLexicographic();

    puts("========================================");
    puts(" Test results");
    puts("========================================");

    int TotalTests = TestsPassed + TestsFailed;

    printf("Total tests: %d\n", TotalTests);
    printf("Passed: %d \n", TestsPassed);
    printf("Failed: %d \n", TestsFailed);

    if (TestsFailed == 0)
        puts("All tests passed successfully");
    else
        printf("\nThere are errors.\n");

    if (TestsFailed > 0)
        return 1;
    return 0;
}