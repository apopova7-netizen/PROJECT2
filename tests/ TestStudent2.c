
#include "Student2.h"

int TestsPassed = 0;
int TestsFailed = 0;


#define START(name) printf("\nTesting the %s function\n\n", name)
#define CHECK(condition, message) \
    do { \
        if (!(condition)) { \
            printf("Test failed: %s\n", message); \
            TestsFailed++;\
            return 1; \
        } else \
            printf("%s\n", message); \
         \
    } while(0)

#define END() \
    do { \
        TestsPassed++; \
        printf("Test passed\n\n"); \
        return 0; \
    } while(0)


int ArraysEqual(int* a,int* b, int n) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) != *(b + i)) return 0;
    }
    return 1;
}

int TestSwap() {
    START("Swap");

    int a = 5, b = 10;

    printf("Before: a = %d, b = %d\n",a,b);
    Swap(&a, &b);
    printf("After: a = %d, b = %d\n",a,b);

    CHECK(a == 10, "a should be equal to 10");
    CHECK(b == 5, "b should be equal to 5");
    END();
}

int TestReverse() {
    START("Reverse");

    int arr[] = {1, 2, 3, 4, 5};
    int expected1[] = {5, 4, 3, 2, 1};
    int expected2[] = {1, 4, 3, 2, 5};

    printf("Before: ");
    PrintPermutation(arr,5);
    Reverse(arr, 0, 4);
    printf("After: ");
    PrintPermutation(arr,5);

    CHECK(ArraysEqual(arr, expected1, 5),
           "The entire array should flip over");
    printf("=======================\n");

    int arr2[] = {1, 2, 3, 4, 5};

    printf("Before: ");
    PrintPermutation(arr2,5);
    Reverse(arr2, 1, 3);
    printf("After: ");
    PrintPermutation(arr2,5);

    CHECK(ArraysEqual(arr2, expected2, 5),
          "The elements with indexes 1 through 3"
          " must be flipped");
    END();
}

int TestSorting() {
    START("Sorting");

    int arr[] = {5, 3, 1, 4, 2};
    int expected[] = {1, 2, 3, 4, 5};

    printf("Before: ");
    PrintPermutation(arr,5);
    Sorting(arr, 5);
    printf("After: ");
    PrintPermutation(arr,5);

    CHECK(ArraysEqual(arr, expected, 5),
          "The array must be sorted in ascending order");
    END();
}

int TestNoDuplicate() {
    START("NoDuplicate");

    int arr1[] = {1, 2, 3, 4, 5};

    printf("Array: ");
    PrintPermutation(arr1,5);
    printf("result: %d\n", NoDuplicate(arr1, 5));

    CHECK(NoDuplicate(arr1, 5) == 1,
          "An array without duplicates should return 1");
    printf("=======================\n");

    int arr2[] = {1, 2, 3, 2, 4};
    printf("Array: ");
    PrintPermutation(arr2,5);
    int res = NoDuplicate(arr2, 5);
    printf("result: %d\n", res);

    CHECK(res == 0,
          "An array with duplicates should return 0");
    printf("=======================\n");

    int arr3[] = {7};

    printf("Array: ");
    PrintPermutation(arr3,1);
    int res1 = NoDuplicate(arr3, 1);
    printf("result: %d\n", res1);

    CHECK(res1 == 1,
          "An array of 1 element should return 1");
    END();
}


int TestFactorial2() {
    START("Factorial");

    CHECK(Factorial(0) == 1, "0! should be 1");
    CHECK(Factorial(1) == 1, "1! should be 1");
    CHECK(Factorial(2) == 2, "2! should be 2");
    CHECK(Factorial(3) == 6, "3! should be 6");
    CHECK(Factorial(4) == 24, "4! should be 24");
    CHECK(Factorial(5) == 120, "5! should be 120");

    END();
}


int TestSorting2dBubble() {
    START("Sorting2dBubble");

    int arr[6][3] = {{2,1,3},
                    {3,1,2},
                    {1,2,3},
                    {3,2,1},
                    {2,3,1},
                    {1,3,2}};

    printf("Before sorting:\n");
    for (int i = 0; i < 6; i++) {
        printf("  ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int** arr1 = (int**)malloc(sizeof(int*) * 6);

    if (arr1 == NULL){
        puts("Memory allocation error");
        return 1;
    }

    for (int i = 0; i < 6;i++ ) {
        *(arr1 + i) = (int*)malloc(3 * sizeof(int));
        if (*(arr1 + i) == NULL) {
            for (int j = 0; j < i; j++)
                free(*(arr1 + j));
            free(arr1);
            return 1;
        }
    }

    for (int i = 0; i < 6; i++) {
        memcpy(*(arr1 + i), arr[i],sizeof(int) * 3);
    }

    Sorting2dBubble(arr1, 6, 3);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < 6; i++) {
        printf("  ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }


    int expected[6][3] = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2,3,1},
        {3,1,2},
        {3,2,1}
    };

    for (int i = 0; i < 6; i++) {
        int is_equal = 1;
        for (int j = 0; j < 3; j++) {
            if (arr1[i][j] != expected[i][j]) {
                is_equal = 0;
                break;
            }
        }
        CHECK(is_equal == 1, "Row should be in correct position");
    }
    for (int k = 0; k < 6;k++)
        free(*(arr1 + k));
    free(arr1);

    END();
}
int TestCreateList() {
    START("CreateList");

    LIST* list = CreateList();
    CHECK(list != NULL, "List should be created successfully");
    CHECK(list->next == NULL, "New list should be empty");
    CHECK(list->value == 0, "The value of the terminal element is 0");

    free(list);
    END();
}

int TestIsEmpty() {
    START("IsEmpty");

    LIST* list = CreateList();
    CHECK(IsEmpty(list) == true, "New list should be empty");


    Insert(list, 5, 0);
    CHECK(IsEmpty(list) == false, "List with elements should not be empty");

    Pop(list);
    CHECK(IsEmpty(list) == true, "After popping, list should be empty again");

    free(list);
    END();
}

int TestInsert() {
    START("Insert");

    LIST* list = CreateList();


    Insert(list, 10, 0);
    CHECK(list->next != NULL, "Element should be inserted");
    CHECK(list->next->value == 10, "Inserted value should be 10");
    CHECK(list->next->next == NULL, "Should be only one element");


    Insert(list, 5, 0);
    CHECK(list->next->value == 5, "First element should be 5");
    CHECK(list->next->next->value == 10, "Second element should be 10");

    Insert(list, 15, 2);
    CHECK(list->next->next->next->value == 15, "Third element should be 15");
    CHECK(list->next->next->next->next == NULL, "Should be exactly 3 elements");


    int arr[3];
    Fill(list, arr);
    CHECK(arr[0] == 5, "First element in array should be 5");
    CHECK(arr[1] == 10, "Second element in array should be 10");
    CHECK(arr[2] == 15, "Third element in array should be 15");

    DeletingListElements(list);
    free(list);
    END();
}

int TestPop() {
    START("Pop");

    LIST* list = CreateList();

    Insert(list, 1, 0);
    Insert(list, 2, 1);
    Insert(list, 3, 2);

    CHECK(IsEmpty(list) == false, "List should not be empty");

    Pop(list);
    CHECK(list->next->value == 2, "After first pop, first element should be 2");
    CHECK(list->next->next->value == 3, "Second element should be 3");
    CHECK(list->next->next->next == NULL, "Should be 2 elements");

    Pop(list);
    CHECK(list->next->value == 3, "After second pop, first element should be 3");
    CHECK(list->next->next == NULL, "Should be 1 element");

    Pop(list);
    CHECK(IsEmpty(list) == true, "After popping all, list should be empty");

    Pop(list);
    CHECK(IsEmpty(list) == true, "Should still be empty");

    free(list);
    END();
}

int TestFill() {
    START("Fill");

    LIST* list = CreateList();

    Insert(list, 10, 0);
    Insert(list, 20, 1);
    Insert(list, 30, 2);
    Insert(list, 40, 3);

    int arr[4];
    Fill(list, arr);

    CHECK(arr[0] == 10, "First element should be 10");
    CHECK(arr[1] == 20, "Second element should be 20");
    CHECK(arr[2] == 30, "Third element should be 30");
    CHECK(arr[3] == 40, "Fourth element should be 40");

    DeletingListElements(list);
    free(list);
    END();
}

int TestDeletingListElements() {
    START("DeletingListElements");

    LIST* list = CreateList();

    for (int i = 0; i < 10; i++) {
        Insert(list, i * 10, i);
    }
    CHECK(IsEmpty(list) == false, "List should not be empty before deletion");

    DeletingListElements(list);

    CHECK(IsEmpty(list) == true, "List should be empty after deletion");
    CHECK(list->next == NULL, "Next pointer should be NULL");

    DeletingListElements(list);
    CHECK(IsEmpty(list) == true, "Should still be empty");

    free(list);
    END();
}

int TestNextPermutationNarayana() {
    START("NextPermutationNarayana");

    int arr1[] = {1, 2, 3};
    int expected1[] = {1, 3, 2};

    printf("Before: ");
    PrintPermutation(arr1,3);
    bool res = NextPermutationNarayana(arr1, 3);
    printf("result: %d\n", res);
    printf("After: ");
    PrintPermutation(arr1,3);

    CHECK(res == true, "The next permutation must exist");
    CHECK(ArraysEqual(arr1, expected1, 3),
          "There should be a permutation 1 3 2");
    printf("=======================\n");

    int arr2[] = {3, 2, 1};
    int expected2[] = {3,2,1};


    printf("Before: ");
    PrintPermutation(arr2,3);
    res = NextPermutationNarayana(arr2, 3);
    printf("result: %d\n", res);
    printf("After: ");
    PrintPermutation(arr2,3);

    CHECK(res == false,
          "For the last permutation, it should return false");

    CHECK(ArraysEqual(arr2,expected2,3),"The array itself"
                                        " should not change");
    printf("=======================\n");

    int arr3[] = {12};

    printf("Before: ");
    PrintPermutation(arr3,1);
    res = NextPermutationNarayana(arr3, 1);
    printf("result: %d\n", res);
    printf("After: ");
    PrintPermutation(arr3,1);

    CHECK(res == false,
          "For one element or less, it should return false");
    END();
}

int TestPrevPermutationNarayana() {
    START("PrevPermutationNarayana");

    int arr1[] = {3, 2, 1};
    int expected1[] = {3, 1, 2};

    printf("Before: ");
    PrintPermutation(arr1,3);
    bool res = PrevPermutationNarayana(arr1, 3);
    printf("result: %d\n", res);
    printf("After: ");
    PrintPermutation(arr1,3);

    CHECK(res == true, "The previous permutation must exist");
    CHECK(ArraysEqual(arr1, expected1, 3),
          "There should be a permutation 3 1 2");
    printf("=======================\n");

    int arr2[] = {1,2,3};
    int expected2[] = {1,2,3};


    printf("Before: ");
    PrintPermutation(arr2,3);
    res = PrevPermutationNarayana(arr2, 3);
    printf("result: %d\n", res);
    printf("After: ");
    PrintPermutation(arr2,3);

    CHECK(res == false,
          "For the first permutation, it should return false");

    CHECK(ArraysEqual(arr2,expected2,3),"The array itself should not"
                                        " change");
    printf("=======================\n");

    int arr3[] = {22};

    printf("Before: ");
    PrintPermutation(arr3,1);
    res = PrevPermutationNarayana(arr3, 1);
    printf("result: %d\n", res);
    printf("After: ");
    PrintPermutation(arr3,1);

    CHECK(res == false,
          "For one element or less, it should return false");
    END();
}


int TestChooseStepPermutationNarayana() {
    START("ChooseStepPermutationNarayana");

    int arr1[] = {7,4,8};
    int expected1[] = {7,8,4};

    printf("Array: ");
    PrintPermutation(arr1,3);
    printf("direction: %d\n",1);
    bool res1 = ChooseStepPermutationNarayana(arr1, 3, 1);
    printf("result: %d\n", res1);
    printf("After: ");
    PrintPermutation(arr1,3);

    CHECK(res1 == true, "The next permutation must exist");
    CHECK(ArraysEqual(arr1, expected1, 3),
          "There should be a permutation 7 8 4 ");
    printf("=======================\n");



    int arr2[] = {34,47,88};
    int expected2[] = {34,47,88};

    printf("Array: ");
    PrintPermutation(arr2,3);
    printf("direction: %d\n",0);
    bool res2 = ChooseStepPermutationNarayana(arr2, 3, 0);
    printf("result: %d\n", res2);
    printf("After: ");
    PrintPermutation(arr2,3);

    CHECK(res2 == false, "You cannot get the previous permutation"
                                            " from the first one.");
    CHECK(ArraysEqual(arr2,expected2, 3), "The array itself should not"
                                        " change");
    END();
}


int CallbackCounter = 0;

void CountingCallback(int* perm, int n) {
    CallbackCounter++;
    PrintPermutation(perm,n);

}

int TestPermutationNarayana() {
    START("PermutationNarayana");

    int arr[] = {1, 2, 3};
    CallbackCounter = 0;
    printf("Array: ");
    PrintPermutation(arr,3);
    puts("permutations:");
    PermutationNarayana(arr, 3, CountingCallback);

    CHECK(CallbackCounter == 6,
          "There should be 6 permutations for 3 elements");
    END();
}
int TestReversePermutationNarayana() {
    START("PermutationReverseNarayana");

    int arr[] = {4,8,2};
    CallbackCounter = 0;

    printf("Array: ");
    PrintPermutation(arr,3);
    puts("permutations:");
    PermutationReverseNarayana(arr, 3, CountingCallback);

    CHECK(CallbackCounter == 6,
          "There should be 6 permutations for 3 elements");
    END();

}


int TestChoosePermutationNarayana() {
    START("ChoosePermutationNarayana");

    int arr[] = {1,2,3};
    CallbackCounter = 0;

    printf("Array: ");
    PrintPermutation(arr,3);
    puts("permutations:");
    ChoosePermutationNarayana(arr, 3, CountingCallback,1);

    CHECK(CallbackCounter == 6,
          "There should be 6 permutations for 3 elements");

    int arr1[] = {3,1,2};
    CallbackCounter = 0;

    printf("Array: ");
    PrintPermutation(arr1,3);
    puts("permutations:");
    ChoosePermutationNarayana(arr1, 3, CountingCallback,0);

    CHECK(CallbackCounter == 6,
          "There should be 6 permutations for 3 elements");
    END();

}

int TestPermutationFromIndex() {
    START("PermutationFromIndex");

    int arr[] = {1, 2, 3, 4};
    int expected0[] = {1, 2, 3, 4};

    int res[4];
    printf("Array: ");
    PrintPermutation(arr,4);
    printf("=======================\n");
    puts("Index = 0");
    printf("Permutation: ");
    PermutationFromIndex(arr, 4, 0, res);
    PrintPermutation(res,4);

    CHECK(ArraysEqual(res, expected0, 4),
          "An index of 0 should give the first permutation");
    printf("=======================\n");

    int expected1[] = {1, 2, 4, 3};
    puts("Index = 1");
    printf("Permutation: ");
    PermutationFromIndex(arr, 4, 1, res);
    PrintPermutation(res,4);

    CHECK(ArraysEqual(res, expected1, 4),
          "An index of 1 should give the second permutation");
    printf("=======================\n");

    int expected23[] = {4, 3, 2, 1};
    puts("Index = 23");
    printf("Permutation: ");
    PermutationFromIndex(arr, 4, 23, res);
    PrintPermutation(res,4);

    CHECK(ArraysEqual(res, expected23, 4),
          "An index of 23 should give the last permutation");


    printf("=======================\n");

    int expected24[] = {1,2,3,4};
    puts("Index = 24");
    printf("Permutation: ");
    PermutationFromIndex(arr, 4, 24, res);
    PrintPermutation(res,4);

    CHECK(ArraysEqual(res, expected24, 4),
          "An index of 24 should give the first permutation");

    END();
}

int TestPermutationsFactorialSystem() {
    START("PermutationsFactorialSystem");

    int arr[] = {67,4,12};
    CallbackCounter = 0;

    printf("Array: ");
    PrintPermutation(arr,3);
    puts("permutations:");
    PermutationNarayana(arr, 3, CountingCallback);

    CHECK(CallbackCounter == 6,
          "There are 6 permutations for 3 elements.");
    END();
}


int TestNextInversionTable() {
    START("NextInversionTable");

    int inv[] = {0, 0, 0};
    int expected1[] = {0, 1, 0};
    int expected2[] = {1, 0, 0};

    printf("The inversion table: ");
    PrintPermutation(inv,3);
    int res = NextInversionTable(inv, 3);
    printf("result: %d\n", res);

    CHECK(res == 1, "The next table exists");
    PrintPermutation(inv,3);
    CHECK(ArraysEqual(inv, expected1, 3),
          "The next table of inversions");
    printf("=======================\n");

    res = NextInversionTable(inv, 3);
    printf("result: %d\n", res);

    CHECK(res == 1, "The next table exists");
    PrintPermutation(inv,3);
    CHECK(ArraysEqual(inv, expected2, 3),
          "The next table of inversions");
    END();
}

int TestPermutationFromInversionTable() {
    START("PermutationFromInversionTable");

    int arr[] = {1, 2, 3};
    int inv1[] = {0, 0, 0};
    int expected1[] = {1, 2, 3};
    int res[3];

    printf("Array: ");
    PrintPermutation(arr,3);
    printf("Inversion table: ");
    PrintPermutation(inv1,3);
    PermutationFromInversionTable(inv1, 3, arr, res);
    printf("Permutation: ");
    PrintPermutation(res,3);

    CHECK(ArraysEqual(res, expected1, 3),
          "[0,0,0] -> [1,2,3]");
    printf("=======================\n");

    int inv2[] = {2, 1, 0};
    int expected2[] = {3, 2, 1};

    printf("Inversion table: ");
    PrintPermutation(inv2,3);
    PermutationFromInversionTable(inv2, 3, arr, res);
    printf("Permutation: ");
    PrintPermutation(res,3);

    CHECK(ArraysEqual(res, expected2, 3),
          "[2,1,0] -> [3,2,1]");
    END();
}


int TestPermutationsInversionTable() {
    START("PermutationsInversionTable");

    int arr[] = {7, 11, 2};
    CallbackCounter = 0;

    printf("Array: ");
    PrintPermutation(arr,3);
    puts("permutations:");
    PermutationsInversionTable(arr, 3, CountingCallback);

    CHECK(CallbackCounter == 6,
          "There should be 6 permutations for 3 elements");
    END();
}

int TestPermutationsPlusOne() {
    START("PermutationsPlusOne");

    int arr[] = {8,12,0,3};
    CallbackCounter = 0;

    printf("Array: ");
    PrintPermutation(arr,4);
    puts("permutations:");
    PermutationsInversionTable(arr, 4, CountingCallback);

    CHECK(CallbackCounter == 24,
          "There should be 24 permutations for 4 elements");
    END();
}


int TestBoundaryCases() {
    START("TestBoundaryCases");

    int arr0[] = {};
    CallbackCounter = 0;

    PermutationNarayana(arr0, 0, CountingCallback);
    PermutationReverseNarayana(arr0, 0, CountingCallback);
    ChoosePermutationNarayana(arr0, 0, CountingCallback,1);
    ChoosePermutationNarayana(arr0, 0, CountingCallback,0);
    PermutationsFactorialSystem(arr0, 0, CountingCallback);
    PermutationsInversionTable(arr0,0,CountingCallback);
    PermutationsPlusOne(arr0, 0, CountingCallback);
    CHECK(CallbackCounter == 0, "An empty array should not produce permutations.");


    int arr1[] = {7};
    printf("Array: ");
    PrintPermutation(arr1,1);

    CallbackCounter = 0;
    printf("Permutation: ");
    PermutationReverseNarayana(arr1, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "One element = one permutation");

    CallbackCounter = 0;
    printf("Permutation: ");
    ChoosePermutationNarayana(arr1, 1, CountingCallback,1);
    CHECK(CallbackCounter == 1, "One element = one permutation");

    CallbackCounter = 0;
    printf("Permutation: ");
    ChoosePermutationNarayana(arr1, 1, CountingCallback,0);
    CHECK(CallbackCounter == 1, "One element = one permutation");

    CallbackCounter = 0;
    printf("Permutation: ");
    PermutationsFactorialSystem(arr1, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "One element = one permutation");

    CallbackCounter = 0;
    printf("Permutation: ");
    PermutationsInversionTable(arr1, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "One element = one permutation");

    CallbackCounter = 0;
    printf("Permutation: ");
    PermutationsPlusOne(arr1, 1, CountingCallback);
    CHECK(CallbackCounter == 1, "One element = one permutation");


    int arr2[] = {1,2,1};

    CallbackCounter = 0;

    PermutationNarayana(arr2, 3, CountingCallback);
    PermutationReverseNarayana(arr2, 0, CountingCallback);
    ChoosePermutationNarayana(arr2, 0, CountingCallback,1);
    ChoosePermutationNarayana(arr2, 0, CountingCallback,0);
    PermutationsFactorialSystem(arr2, 0, CountingCallback);
    PermutationsInversionTable(arr2,0,CountingCallback);
    PermutationsPlusOne(arr2, 0, CountingCallback);

    CHECK(CallbackCounter == 0, "Duplicates should stop generating");
    END();
}



int main() {

    TestSwap();
    TestReverse();
    TestSorting();
    TestNoDuplicate();
    TestFactorial2();
    TestSorting2dBubble();
    TestCreateList();
    TestIsEmpty();
    TestInsert();
    TestPop();
    TestFill();
    TestDeletingListElements();
    TestNextPermutationNarayana();
    TestPrevPermutationNarayana();
    TestChooseStepPermutationNarayana();
    TestPermutationNarayana();
    TestReversePermutationNarayana();
    TestChoosePermutationNarayana();
    TestPermutationFromIndex();
    TestPermutationsFactorialSystem();
    TestNextInversionTable();
    TestPermutationFromInversionTable();
    TestPermutationsInversionTable();
    TestPermutationsPlusOne();
    TestBoundaryCases();

    puts("========================================");
    puts(" Test results");
    puts("========================================");

    int TotalTests = TestsPassed + TestsFailed;

    printf("Total tests: %d\n", TotalTests);
    printf("Passed: %d \n",TestsPassed);
    printf("Failed: %d \n", TestsFailed);

    if (TestsFailed == 0) {
        puts("All tests passed successfully");
    } else {
        printf("\nThere are errors.\n");
    }

    if (TestsFailed > 0)
        return 1;
    return 0;

}






