
/*
* @param arr is an array of different integers
* @param n is the size of the array (0 <= n <= 12),
 must match the actual length of the array
* @param callback is function for processing each permutation
*
* For the ChoosePermutationNarayan function:
*
* @param direction is the direction of generating permutations
* direction = 0 - generation in lexicographic order
* direction = 1 - generation in an anti-lexicographic order
*/

#include "Student2.h"

int main() {
    int arr[] = {};
    int n = sizeof(arr) / sizeof(int);

    printf("n = %d, arr = {}\n", n);

    puts("PermutationNarayana");
    PermutationNarayana(arr,n,PrintPermutation);
    puts("PermutationReverseNarayana");
    PermutationReverseNarayana(arr,n,PrintPermutation);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr,n,PrintPermutation,1);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr,n,PrintPermutation,0);
    puts("PermutationsFactorialSystem");
    PermutationsFactorialSystem(arr,n,PrintPermutation);
    puts("PermutationsInversionTable");
    PermutationsInversionTable(arr,n,PrintPermutation);
    puts("PermutationsPlusOne");
    PermutationsPlusOne(arr,n,PrintPermutation);

    puts("===================================================================================");

    int arr1[] = {5};
    int n1 = sizeof(arr1) / sizeof(int);

    printf("n = %d, arr = {5}\n", n1);

    puts("PermutationNarayana");
    PermutationNarayana(arr1,n1,PrintPermutation);
    puts("PermutationReverseNarayana");
    PermutationReverseNarayana(arr1,n1,PrintPermutation);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr1,n1,PrintPermutation,1);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr1,n1,PrintPermutation,0);
    puts("PermutationsFactorialSystem");
    PermutationsFactorialSystem(arr1,n1,PrintPermutation);
    puts("PermutationsInversionTable");
    PermutationsInversionTable(arr1,n1,PrintPermutation);
    puts("PermutationsPlusOne");
    PermutationsPlusOne(arr1,n1,PrintPermutation);

    puts("===================================================================================");

    int arr2[] = {1,2};
    int n2 = sizeof(arr2) / sizeof(int);

    printf("n = %d, arr = {1,2}\n", n2);

    puts("PermutationNarayana");
    PermutationNarayana(arr2,n2,PrintPermutation);
    puts("PermutationReverseNarayana");
    PermutationReverseNarayana(arr2,n2,PrintPermutation);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr2,n2,PrintPermutation,1);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr2,n2,PrintPermutation,0);
    puts("PermutationsFactorialSystem");
    PermutationsFactorialSystem(arr2,n2,PrintPermutation);
    puts("PermutationsInversionTable");
    PermutationsInversionTable(arr2,n2,PrintPermutation);
    puts("PermutationsPlusOne");
    PermutationsPlusOne(arr2,n2,PrintPermutation);

    puts("===================================================================================");

    int arr3[] = {3,1,2};
    int n3 = sizeof(arr3) / sizeof(int);

    printf("n = %d, arr = {3,1,2}\n", n3);

    puts("PermutationNarayana");
    PermutationNarayana(arr3,n3,PrintPermutation);
    puts("PermutationReverseNarayana");
    PermutationReverseNarayana(arr3,n3,PrintPermutation);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr3,n3,PrintPermutation,1);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr3,n3,PrintPermutation,0);
    puts("PermutationsFactorialSystem");
    PermutationsFactorialSystem(arr3,n3,PrintPermutation);
    puts("PermutationsInversionTable");
    PermutationsInversionTable(arr3,n3,PrintPermutation);
    puts("PermutationsPlusOne");
    PermutationsPlusOne(arr3,n3,PrintPermutation);

    puts("===================================================================================");

    int arrNegative[] = {};
    int nNegativ = -7;

    printf("n = %d, arr = {}\n", nNegativ);

    puts("PermutationNarayana");
    PermutationNarayana(arrNegative,nNegativ,PrintPermutation);
    puts("PermutationReverseNarayana");
    PermutationReverseNarayana(arrNegative,nNegativ,PrintPermutation);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arrNegative,nNegativ,PrintPermutation,1);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arrNegative,nNegativ,PrintPermutation,0);
    puts("PermutationsFactorialSystem");
    PermutationsFactorialSystem(arrNegative,nNegativ,PrintPermutation);
    puts("PermutationsInversionTable");
    PermutationsInversionTable(arrNegative,nNegativ,PrintPermutation);
    puts("PermutationsPlusOne");
    PermutationsPlusOne(arrNegative,nNegativ,PrintPermutation);

    puts("===================================================================================");

    int arrExcess[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int nExcess = 17;

    printf("n = %d, arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17}\n", nExcess);

    puts("PermutationNarayana");
    PermutationNarayana(arrExcess,nExcess,PrintPermutation);
    puts("PermutationReverseNarayana");
    PermutationReverseNarayana(arrExcess,nExcess,PrintPermutation);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arrExcess,nExcess,PrintPermutation,1);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arrExcess,nExcess,PrintPermutation,0);
    puts("PermutationsFactorialSystem");
    PermutationsFactorialSystem(arrExcess,nExcess,PrintPermutation);
    puts("PermutationsInversionTable");
    PermutationsInversionTable(arrExcess,nExcess,PrintPermutation);
    puts("PermutationsPlusOne");
    PermutationsPlusOne(arrExcess,nExcess,PrintPermutation);

    puts("===================================================================================");

    int arr8[] = {3,11,4,1,0,6,2324,5};
    int n8 = sizeof(arr8) / sizeof(int);

    printf("n = %d, arr = {3,11,4,1,0,6,2324,5}\n", n8);

    puts("PermutationNarayana");
    PermutationNarayana(arr8,n8,PrintPermutation);
    puts("PermutationReverseNarayana");
    PermutationReverseNarayana(arr8,n8,PrintPermutation);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr8,n8,PrintPermutation,1);
    puts("ChoosePermutationNarayana, direction = 1");
    ChoosePermutationNarayana(arr8,n8,PrintPermutation,0);
    puts("PermutationsFactorialSystem");
    PermutationsFactorialSystem(arr8,n8,PrintPermutation);
    puts("PermutationsInversionTable");
    PermutationsInversionTable(arr8,n8,PrintPermutation);
    puts("PermutationsPlusOne");
    PermutationsPlusOne(arr8,n8,PrintPermutation);

    return 0;


}


}
