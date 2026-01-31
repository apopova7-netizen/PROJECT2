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

### 2.2 Factorial Number System Algorithm

How it works: To get permutation by index:
1. Convert the index to factorial number system: index = a₁·1! + a₂·2! + ... + aₙ₋₁·(n-1)!, where 0 ≤ aₖ ≤ k.
2. Start with sorted array of elements [e₁, e₂, ..., eₙ].
3. For each digit aₖ from most significant to least:
   · Take element at position aₖ from current list.
   · Remove this element from the list.
   · Append it to result permutation.
4. Append the last remaining element.

**Example for n=4, index=15:**
1. Convert 15 to factorial digits:
   · 15 ÷ 6 = 2 rem 3 (6 = 3!)
   · 3 ÷ 2 = 1 rem 1 (2 = 2!)
   · 1 ÷ 1 = 1 rem 0 (1 = 1!)
     Digits: [2, 1, 1] (reading from most significant)
2. Sorted array: [1, 2, 3, 4]
3. Process digits:
   · Take element at position 2: [1, 2, 3, 4] → 3, remaining: [1, 2, 4]
   · Take element at position 1: [1, 2, 4] → 2, remaining: [1, 4]
   · Take element at position 1: [1, 4] → 4, remaining: [1]
   · Take last element: 1
4. Result permutation: [3, 2, 4, 1]


### 2.3 Inversion Table Algorithm

How it works: To generate permutations via inversion tables:
1. An inversion table I = [i₁, i₂, ..., iₙ] for permutation P satisfies: 0 ≤ iₖ ≤ n-k, where iₖ counts elements in P to the left of position k that are larger than P[k].
2. All valid inversion tables can be generated by counting from [0,0,...,0] to [n-1, n-2, ..., 0].
3. To convert inversion table to permutation:
   . We start from the end of the list.
   · We put the kth element in the list, skipping the iₖ elements from the beginning of the list
     
Example for inversion table [1, 2, 0, 1, 0], n=5:

1. Sorted array: [1, 2, 3, 4, 5]
2. Process from last to first:
   
   · i₅ = 0: => [5]
   · i₄ = 1: => [5,4]
   · i₃ = 0: => [3,4,5]
   · i₂ = 2: => [3,4,2,5]
   · i₁ = 1: => [3,1,4,2,5]
4. Final permutation: [3,1,4,2,5]

How to generate next inversion table:
1. Start from the last position.
2. Increment the current digit if possible (iₖ < n-k).
3. If incremented, set all following digits to 0.
4. If not possible (iₖ = n-k), move left and repeat.


### 2.4 Algorithm "Plus One" (Factorial Counting)

How it works: To generate all permutations:
1. Maintain an index array idx = [idx₁, idx₂, ..., idxₙ] where 0 ≤ idxₖ < n-k+1.
2. Start with idx = [0, 0, ..., 0].
3. For each index array:
   · Copy sorted array S = [s₁, s₂, ..., sₙ].
   · For k = 1 to n:
     · Take element at position idxₖ from current S.
     · Remove it from S.
     · Append to result permutation.
4. Increment idx as a mixed-radix number in factorial base:
   · Start from last digit.
   · Increment current digit.
   · If digit exceeds its limit (idxₖ ≥ n-k+1), reset to 0 and carry to next digit.

Example for n=3:
Sorted array: [1, 2, 3]   
Step 1: idx = [0, 0, 0]

· Take idx₁=0: [1,2,3] → 1, remaining: [2,3]
· Take idx₂=0: [2,3] → 2, remaining: [3]
· Take idx₃=0: [3] → 3
  Result: [1, 2, 3]

Step 2: idx = [0, 1, 0] (incremented last digit)

· Take idx₁=0: [1,2,3] → 1, remaining: [2,3]
· Take idx₂=1: [2,3] → 3, remaining: [2]
· Take idx₃=0: [2] → 2
  Result: [1, 3, 2]

Step 3: idx = [1, 0, 0] (carry occurred)

· Take idx₁=1: [1,2,3] → 2, remaining: [1,3]
· Take idx₂=0: [1,3] → 1, remaining: [3]
· Take idx₃=0: [3] → 3
  Result: [2, 1, 3]

Continue until idx = [2, 1, 0] (last valid array)

All permutations for n=3:
idx=[0,0,0] → [1,2,3]
idx=[0,1,0] → [1,3,2]
idx=[1,0,0] → [2,1,3]
idx=[1,1,0] → [2,3,1]
idx=[2,0,0] → [3,1,2]
idx=[2,1,0] → [3,2,1]



