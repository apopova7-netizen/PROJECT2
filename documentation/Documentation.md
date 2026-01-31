# Documentation: interactive permutation generation algorithms

## Introduction
Implementation of iterative algorithms for generating permutations, providing a deterministic order, the possibility of interrupting and resuming generation, as well as efficient memory use without recursion.льных целых чисел. Перестановки могут быть получены в прямом и обратном лексикографическом порядке. Реализация предназначена для учебных целей и демонстрации различных комбинаторных подходов.

Implemented methods:
* Narayana's algorithm (forward and reverse) – efficient generation of the next/previous permutation.
* Factorial number system – obtaining a permutation by its ordinal number.
* Inversion tables – generation of permutations through an intermediate data structure.
* The "Plus one" algorithm is a direct iteration through the emulation of addition in the factorial system.

### Section 2.1, 2.5: Narayana's Algorithm
* bool NextPermutationNarayana(int* arr, int n) – Converts the arr array to the next permutation. Returns false if the current one is the last one.
* bool PrevPermutationNarayana(int* arr, int n) – Converts the arr array to the next (direction=1) previous (direction=0) permutation. Returns false if the current one is the first one.
* bool ChooseStepPermutationNarayana(int* arr, int n) – Converts the arr array to the previous permutation. Returns false if the current one is the first one.
* void PermutationNarayana(int arr[], int n, void(*callback)(int* perm, int n)) – Generates and outputs all permutations in lexicographic order.
* void PermutationReverseNarayana(int arr[], int n, void(*callback)(int* perm, int n)) – Generates and outputs all permutations in an anti-lexicographic order.
* void ChoosePermutationNarayana(... int direction) is a universal function for generating in forward (direction=1) or reverse (direction=0) order.
* 
### Section 2.2: The factorial number system
* void PermutationFromIndex(int* arr, int n, int index, int* result) – Writes a permutation with the index sequence number to result.
* void PermutationsFactorialSystem(int arr[], int n, void(*callback)(int* perm, int n)) – Generates all permutations using direct index transformation.

### Section 2.3: Tables of inversions
* void PermutationFromInversionTable(const int* invTable,int n,const int* arr,int* res)  – sets the default permutation to invTable and the sorted value of arr.
* void PermutationsInversionTable(int arr[], int n, void(*callback)(int* perm, int n)) – generate all the templates, convert them to settings and enter them into the lexicographic series.
* int NextInversionTable(int* inv,int n) Receives an array (table of inversions) as input data and creates the following from it

### Section 2.4: The "Plus one" algorithm
* void PermutationsPlusOne(int arr[], int n, void(*callback)(int* perm, int n)) – Generates all permutations by iterating through all possible arrays of indexes in the factorial system.
  
### Auxiliary functions
*   void Swap(int* a1, int* a2), void Reverse(int* arr, int start, int end),void Sorting(int* arr,int n),int NoDuplicate(int arr[],int n), void PrintPermutation(int* perm,int n), int Factorial(int n), LIST* CreateList(),void Fill(const LIST* list,int* arr),void Insert(LIST* list,int value,int indInsert),bool IsEmpty(const LIST* list),void Pop(LIST* list),void DeletingListElements(LIST* list), void Sorting2dBubble(int** arr,int quantityPerm,int n)

## Description of algorithms with examples

### 2.1, 2.5 Narayana's Algorithm
How it works: To get the following permutation:
1. Find the largest index i such that arr[i] < arr[i+1].
2. Find the largest index j such that arr[j] > arr[i].
3. Swap arr[i] and arr[j].
4. Expand the sequence of elements from i+1 to the end.
   
 **Example for an array [1, 3, 4, 2]:**
1. i = 1 (element 3, because 3 < 4).
2. j = 2 (element 4, because 4 > 3).
3. Exchange: [1, 4, 3, 2].
4. Tail reversal (from i+1=2): [1, 4, 2, 3].

### How it works: To get the previous permutation:
How it works: To get the following permutation:
1. Find the largest index i such that arr[i] > arr[i+1].
2. Find the largest index j such that arr[j] < arr[i].
3. Swap arr[i] and arr[j].
4. Expand the sequence of elements from i+1 to the end.
   
 **Example for an array [1, 3, 4, 2]:**
1. i = 1 (element 3, because 4 > 2).
2. j = 2 (element 4, because 2 < 4).
3. Exchange: [1, 3, 2, 4].
4. Tail reversal (from i+1=3): [1, 3, 2, 4].

   

