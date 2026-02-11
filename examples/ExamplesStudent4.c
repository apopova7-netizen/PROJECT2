#include "Student4.h"

void SimplePrint(int* perm, int n){
    for(int i = 0; i < n; i++) printf("%d ", perm[i]);
    printf("\n");
}

void FuncPass(int* perm, int n){
    return;
}

int main() {
    puts("\nExamplesStudent4 starting:");
    int data1[] = {1, 1, 2};
    puts("\n>>> Adaptive: duplicates {1,1,2}");
    ExecuteAdaptivePermutation(data1, 3, SimplePrint);
  
    int data2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    puts("\n>>> Adaptive: Large n = 11");
    puts("nothing for the speed of work (FuncPass)");
    ExecuteAdaptivePermutation(data2, 11, FuncPass); 

    int data[] = {1, 2, 3, 4};
    PermutationParams params = {PERM_NARAYANA, SimplePrint, NULL, NULL, 1};
    puts("\n>>> Narayana Lexicographic (Forward)");
    ExecutePermutation(data, 4, params);

    puts("\n>>> Benchmark: all algorithms");
    puts(">>> Format: [Method Name] [Time] [Count]");
    AllPermutationBenchmark(6);
    puts("\n>>>ExamplesStudent4 end.");
        
    return 0;
}
