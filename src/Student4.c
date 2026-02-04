#include "Student4.h"

/*
4.1 a single interface
for all algorithms from modules 1 to 3
*/
void ExecutePermutation(int* arr, int n, PermutationParams params){
    // checking the basic parameters for all algorithms
    if (arr == NULL || n <= 0 || params.callback == NULL){
        puts("Error: Basic parameters (arr, n, callback) must be set.\n");
        return;
    }

    switch (params.method){
        // student 1
        case PERM_BACKTRACK:
            PermutationsBacktrack(arr, n, params.callback); 
            break;
        case PERM_SWAP:
            PermutationsRecursiveSwap(arr, n, params.callback); 
            break;
        case PERM_LEX_RECURSIVE:
            PermRecursiveLexicographic(arr, n, params.callback); 
            break;
        case PERM_MULTISET:
            MultisetPermutations(arr, n, params.callback);
            break;
        case PERM_CONSTRAINED: 
            // Checking the limiter function
            if (params.constraint == NULL){
                puts("Error: constraint function is required for PERM_CONSTRAINED.\n");
                return;
            }
            PermutationsWithConstraints(arr, n, params.constraint, 
                                        params.constraintData, params.callback); 
            break;

        // student 2
        case PERM_NARAYANA: 
            // Checking the direction
            if (params.direction != 0 && params.direction != 1){
                puts("Error: direction is required for PERM_CONSTRAINED (0/1 - backward/forward).\n");
                return;
            }
            ChoosePermutationNarayana(arr, n, params.callback, params.direction); 
            break;
        case PERM_FACTORIAL_SYSTEM: 
            PermutationsFactorialSystem(arr, n, params.callback);
            break;
        case PERM_INVERSION_TABLE:  
            PermutationsInversionTable(arr, n, params.callback);
            break;
        case PERM_PLUS_ONE:         
            PermutationsPlusOne(arr, n, params.callback);
            break;
        // student 3
        case PERM_JOHNSON_TROTTER: 
            PermutationsJohnsonTrotter(arr, n, params.callback);
            break;
        case PERM_HEAP:            
            PermutationsHeap(arr, n, params.callback);
            break;
        case PERM_MINIMAL_CHANGE:  
            PermutationsMinimalChange(arr, n, params.callback);
            break;
        case PERM_CYCLE_LEADER:    
            PermutationsCycleLeader(arr, n, params.callback);
            break;
        case PERM_BINARY_MASKS:    
            PermutationsBinaryMasks(arr, n, params.callback); 
            break;
        case PERM_PSEUDO_LEX:      
            PermutationsPseudoLexicographic(arr, n, params.callback);
            break;
        default:
            puts("Error: Unknown method\n");
            break;
    }
}

/*
4.2 benchmarking
1) creates an array of n elements(filled from 1-n+1)
and checks the execution time for each algorithm.
2) checks the execution time for algorithm
*/
// iteration counter
unsigned long long counter = 0;
void BenchmarkCallback(int* perm, int n) {
    counter++;
}

// for PERM_CONSTRAINED
bool BenchmarkConstraint(int* partial, int k, int next, void* data) {
    return true; 
}

void AllPermutationBenchmark(int n){
    int* testArr = (int*)malloc(n * sizeof(int));
    if (testArr == NULL){
        puts("Error: malloc");
        return;
    }
    printf("Benchmark(n = %d)\n", n);
    for(int i = 0; i < n; i++)
        *(testArr + i) = i + 1;
    const char* names[] = {
        "Backtrack(S1)", "Swap Recursive(S1)", "Lex Recursive(S1)", "Constrained(S1)", "Multiset(S1)",
        "Narayana(S2)", "Factorial System(S2)", "Inversion Table(S2)", "Plus One(S2)",
        "Johnson-Trotter(S3)", "Heap(S3)", "Minimal Change(S3)", "Cycle Leader(S3)", "Binary Masks(S3)", "Pseudo-Lex(S3)"
    };

    for (int m = 0; m <= PERM_PSEUDO_LEX; m++){
        counter = 0;
        PermutationParams params;
        params.method = (PermutationMethod)m;
        params.callback = BenchmarkCallback;
        params.constraint = BenchmarkConstraint;
        params.constraintData = NULL;
        params.direction = 1;
        // resetting the array
        for(int i = 0; i < n; i++) 
            *(testArr + i) = i + 1;
        clock_t start = clock();
        ExecutePermutation(testArr, n, params);
        clock_t end = clock();
        double algTime = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%s %f %llu\n", names[m], algTime, counter);
    }
    free(testArr);
    printf("Benchmark end\n");
}

void PermutationBenchmark(int* arr, int n, PermutationParams params){
    clock_t start = clock();
    ExecutePermutation(arr, n, params);
    clock_t end = clock();
    double algTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%d %f\n", params.method, algTime);
}

/*
4.4 adaptive selection
without additional data
*/
// checking for duplicates
bool HasDuplicates(int* arr, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j]) return true;
    return false;
}

void ExecuteAdaptivePermutation(int* arr, int n, void (*callback)(int*, int)) {
    PermutationParams params;
    params.callback = callback;
    // there are identical numbers
    if (HasDuplicates(arr, n)){
        params.method = PERM_MULTISET;
    } 
    // large amount of data
    else if (n >= 11){
        params.method = PERM_HEAP;
    } 
    // others
    else{
        params.method = PERM_JOHNSON_TROTTER; 
    }
    ExecutePermutation(arr, n, params);
}
