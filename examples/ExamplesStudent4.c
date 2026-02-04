#include "Student4.h"

void SimplePrint(int* perm, int n){
    for(int i = 0; i < n; i++) printf("%d ", perm[i]);
    printf("\n");
}

int main(){
    int data1[] = {1, 1, 2};
    printf("Adaptive:\n");
    ExecuteAdaptivePermutation(data1, 3, simple_print);
  
    int data2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    printf("\nAdaptive(large n):\n");
    ExecuteAdaptivePermutation(data2, 11, NULL); 

    int data[] = {1, 2, 3, 4};
    int n = 4;
    PermutationParams params;
    params.method = PERM_NARAYANA;
    params.callback = SimplePrint;
    params.direction = 1;
    printf("Narayana:\n");
    ExecutePermutation(data, n, params);

    AllPermutationBenchmark(9); 
  
    return 0;
}
