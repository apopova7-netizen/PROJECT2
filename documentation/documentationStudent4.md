# Documentation: Student 4 

This module provides a single entry point, automated algorithm selection, and benchmarking tools.

## 1. API Architecture

### PermutationMethod

Defines a unique identifier for each of the 15 available algorithms.

**S1 (Recursive & Constrained:** `PERM_BACKTRACK`, `PERM_SWAP`, `PERM_LEX_RECURSIVE`, `PERM_CONSTRAINED`, `PERM_MULTISET`.
    
**S2 (Iterative & Combinatoric):** `PERM_NARAYANA`, `PERM_FACTORIAL_SYSTEM`, `PERM_INVERSION_TABLE`, `PERM_PLUS_ONE`.
    
**S3 (Optimized & Minimal Change):** `PERM_JOHNSON_TROTTER`, `PERM_HEAP`, `PERM_MINIMAL_CHANGE`, `PERM_CYCLE_LEADER`, `PERM_BINARY_MASKS`, `PERM_PSEUDO_LEX`.
    

### PermutationParams
A separate container used to configure the algorithm execution.
``` C
typedef struct {
    PermutationMethod method;                // Selected algorithm ID
    void (*callback)(int* perm, int n);      // Function to process each result
    bool (*constraint)(int*, int, int, void*); // Filter for PERM_CONSTRAINED (opt.)
    void* constraintData;                    // External data for filter (opt.)
    int direction;                           // 1 for Forward, 0 for Reverse (Narayana)
} PermutationParams;

```

## 2. Core Functions
### `ExecutePermutation`
Performs a specific algorithm with built-in security checks (Checks that `arr != NULL`, `n > 0` and `callback != NULL` and special checks for `individual algorithms`)
        
## 3. Benchmarking 
The module evaluates the algorithm execution speed 
Uses "clock_t" to calculate the time
The callback counts the number of permutations without console I/O.
    
## 4.  Example
``` C
#include "interface.h"

// callback to print results
void print_handler(int* p, int n) { /* ... */ }

int main(){
    int data[] = {1, 2, 3, 4, 5};
    
    // Heap's Algorithm
    PermutationParams params = { .method = PERM_HEAP, .callback = print_handler };
    ExecutePermutation(data, 5, params);

    // adaptive selection
    ExecuteAdaptivePermutation(data, 5, print_handler);

    return 0;
}
```
