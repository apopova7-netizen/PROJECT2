
#include "Student2.h"

//2.1, 2.5
static void Swap(int* a1, int* a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

/*Overwrites the array from the "start" index to the end in
 *the opposite direction.*/
void Reverse(int* arr, int start, int end) {

    while (start < end) {

        int tmp = *(arr + start); 
        *(arr + start) = *(arr + end);
        *(arr + end) = tmp;

        start++;
        end--;
    }
}


/*Sorts an array using the bubble method*/
void Sorting(int* arr,int n){

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {

            if (*(arr + j) > *(arr + j + 1))
                Swap(arr + j, arr + j + 1);
        }
}

/* Checks the array for duplicates*/
int NoDuplicate(int arr[],int n) {

    int* copy = (int*)malloc(sizeof(int) * n);

    if (copy == NULL) {
        puts("Memory allocation error");
        return -1;
    }

    memcpy(copy, arr, sizeof(int) * n);
    Sorting(copy,n);

    for (int i = 0; i < n - 1; i++)
        if (*(copy + i) == *(copy + i + 1)) {
            free(copy);
            puts("Enter different numbers");
            return 0;
        }

    free(copy);
    return 1;
}


/*Prints an array*/
void PrintPermutation(int* perm,int n) {
    for (int i = 0; i < n; i++)
        printf("%d ",*(perm + i));
    puts("");
}

/*It receives an array (the previous permutation) as input and uses Narayana's
 *algorithm to create the next permutation in lexicographic order.*/
bool NextPermutationNarayana(int* arr, int n) {

    if (n <= 1)
        return false;

    /* Finds the first element on the right that is larger than the one
     *next to it on the right and remembers its index (i)*/
    int i = n - 2;
    while (i >= 0 && *(arr + i) >= *(arr + i + 1))
        i--;

    /* If there is no such index, then this is the last permutation.*/
    if (i < 0)
        return false;

    /*Finds the first element on the right, which is larger
     *than the element whose index was found in the previous
     *step, and we also remember it (j). */
    int j = n - 1;
    while (*(arr + j) <= *(arr + i))
        j--;

    /*Swaps these elements and expands the tail of the list from
     *the element following the element with the index i */
    Swap(arr + j,arr + i);
    Reverse(arr, i + 1, n - 1);

    return true;
}


/*It receives an array (permutation) as input and uses
 *the reverse Narayana algorithm to create the next previous
 *one in lexicographic order.*/
bool PrevPermutationNarayana(int* arr, int n) {

    if (n <= 1)
        return false;

    int i = n - 2;
    while (i >= 0 && (*(arr + i) <= *(arr + i + 1)))
        i--;

    if (i < 0)
        return false;

    int j = n - 1;
    while (*(arr + j) >= *(arr + i))
        j--;

    Swap(arr + i,arr + j);
    Reverse(arr, i + 1, n - 1);

    return true;
}


/*Creates all permutations using Narayana's algorithm and
 *prints them in lexicographic order*/
void PermutationNarayana(int arr[],int n,
                          void (*callback)(int* perm, int n)) {

    if ( n <= 0 || n > MAX_LENGTH_ARRAY) {
        puts("The length of the array must be in the range [1,12].");
        return;
    }

    if (NoDuplicate(arr,n) != 1)
        return;

    /*Creates a copy of the array and sorts it.*/
    int* copy = (int*)malloc(sizeof(int) * n);

    if (copy == NULL) {
        puts("Memory allocation error");
        return;
    }

    memcpy(copy, arr, sizeof(int) * n);
    Sorting(copy,n);

    /* prints the first permutation separately, then creates the
     * next ones and prints them*/

    callback(copy, n);
    while (NextPermutationNarayana(copy,n))
        callback(copy,n);

    free(copy);
}

/*Creates all permutations using the reverse Narayana algorithm and
 *prints them in an anti-lexicographic order*/
void PermutationReverseNarayana(int arr[], int n,
                          void (*callback)(int* perm, int n)) {

    if ( n <= 0 || n > MAX_LENGTH_ARRAY) {
        puts("The length of the array must be in the range [1,12].");
        return;
    }

    if (NoDuplicate(arr,n) != 1)
        return;

    /*Creates a copy of the array and sorts it.*/
    int* copy = (int*)malloc(sizeof(int) * n);

    if (copy == NULL) {
        puts("Memory allocation error");
        return;
    }

    memcpy(copy, arr, sizeof(int) * n);
    Sorting(copy,n);
    Reverse(copy,0,n - 1);

    callback(copy, n);
    while (PrevPermutationNarayana(copy,n))
        callback(copy,n);

    free(copy);
}


/*uses Narayana's algorithm to create the previous or next
 *permutation. If direction = 1, then the next one,
 *if direction = 0, then the previous one.*/
bool ChooseStepPermutationNarayana(int* arr,int n, int direction) {

    if (n <= 1)
        return false;

    int i = n - 2;

    if (direction)
        while (i >= 0 && *(arr + i) >= *(arr + i + 1))
            i--;
    else
        while (i >= 0 && *(arr + i) <= *(arr + i + 1))
            i--;

    if (i < 0)
        return false;

    int j = n - 1;

    if (direction)
        while (*(arr + j) <= *(arr + i))
            j--;
    else
        while (*(arr + j) >= *(arr + i))
            j--;


    Swap(arr + i,arr + j);
    Reverse(arr, i + 1, n - 1);

    return true;
}

/*Creates all permutations using Narayana's algorithm and
 *prints them in lexicographic order or anti-lexicographic order
 * if direction = 1, then in lexicographic order,
 * if direction = 0, then in anti-lexicographic order. */
void ChoosePermutationNarayana(int arr[],int n,
                          void (*callback)(int* perm, int n),int direction){

    if ( n <= 0 || n > MAX_LENGTH_ARRAY) {
        puts("The length of the array must be in the range [1,12].");
        return;
    }

    if (NoDuplicate(arr,n) != 1)
        return;

    /*Creates a copy of the array and sorts it.*/
    int* copy = (int*)malloc(sizeof(int) * n);

    if (copy == NULL) {
        puts("Memory allocation error");
        return;
    }

    memcpy(copy, arr, sizeof(int) * n);
    Sorting(copy,n);

    if (!direction)
        Reverse(copy,0,n - 1);

    callback(copy, n);


    while (ChooseStepPermutationNarayana(copy,n,direction))
        callback(copy,n);

    free(copy);
}

//2.2
int Factorial2(int n){
    int result = 1;

    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

/*By the number (index) of the permutation, it restores the permutation
 * itself using the factorial number system.*/
void PermutationFromIndex(int* arr,int n, int  index, int* result) {

    if (n == 0)
        return;

    /*Processes indexes outside the range [0, n-1] in a loop*/
    int totalPerm = Factorial2(n);
    index = (index % totalPerm + totalPerm) % totalPerm;

   /*We allocate memory for an array that will contain
    *the factorial digits of the index.*/
    int* facDigits = (int*)malloc(n * sizeof(int));

    if (facDigits == NULL){
        puts("Memory allocation error");
        return;
    }

    /*Converts the index to the factorial number system*/
    int tmp = index;

    int d = totalPerm;
    for (int i = 1; i <= n; i++) {
        int div = d / (n - i + 1);
        d = div;
        *(facDigits + i - 1) = tmp / div;
        tmp %= div;
    }


    int* copy = (int*)malloc(sizeof(int) * n);

    if (copy == NULL) {
        puts("Memory allocation error");
        free(facDigits);
        return;
    }

    memcpy(copy, arr, sizeof(int) * n);
    Sorting(copy,n);

    /*Using factorial numbers, we make a permutation:
     * res[i] = copy[facDigits[i]], In this case, each used
     * element is removed from the list, and the rest are shifted. */

    int realLen = n;
    for (int i = 0; i < n; i++) {
        const int takeInd = *(facDigits + i);
        *(result + i) = *(copy + takeInd);

        for (int j = takeInd; j < realLen - 1; j++)
            *(copy + j) = *(copy + j + 1);
        realLen--;
    }

free(facDigits);
free(copy);
}


/*Generates and prints all permutations by converting the permutation
 *index into the permutation itself using the factorial number system.*/
void PermutationsFactorialSystem(int arr[],int n,
                                  void (*callback)(int* perm, int n)) {

    if ( n <= 0 || n > MAX_LENGTH_ARRAY) {
        puts("The length of the array must be in the range [1,12].");
        return;
    }

    if (NoDuplicate(arr,n) != 1)
        return;

    /*Counts the total number of permutations*/
    int totalPerm = Factorial2(n);

    int* perm = (int*)malloc(n * sizeof(int));

    if (perm == NULL){
        puts("Memory allocation error");
        return;
    }
    int* newcopy = (int*)malloc(n * sizeof(int));

    if (newcopy == NULL){
        puts("Memory allocation error");
        free(perm);
        return;
    }

    /*it goes through all the indexes and creates
     *a corresponding permutation for each one and prints it*/
    for (int ind = 0; ind < totalPerm; ind++) {
        memcpy(newcopy,arr,sizeof(int) * n);
        PermutationFromIndex(newcopy,n,ind,perm);
        callback(perm,n);

    }
    free(newcopy);
    free(perm);
}

//2.3
/*Creates a terminal element of a singly linked list*/
LIST* CreateList() {
    LIST* cur = (LIST*)malloc(sizeof(LIST));

    if (cur == NULL){
        puts("Memory allocation error");
        return NULL;
    }

    cur->value = 0;
    cur->next = NULL;
    return cur;
}

/*Fills the array with values from the list*/
void Fill(const LIST* list,int* arr) {
    const LIST* cur = list->next;
    int i = 0;
    while (cur) {
        *(arr + i) = cur->value;
        cur = cur->next;
        i++;
    }
}


/*Creates a new list item and inserts it at the
 *specified position (indInsert)*/
void Insert(LIST* list,int value,int indInsert) {
    LIST* cur = (LIST*)malloc(sizeof(LIST));

    cur->value = value;
    LIST* ptr = list;

    for (int i = 0 ; i < indInsert; i++)
        ptr = ptr -> next;

    cur->next = ptr->next;
    ptr->next = cur;

}

/*Checking if the list is empty*/
bool IsEmpty(const LIST* list) {
    return !list->next;
}


/*Deletes an item from the beginning of the list*/
void Pop(LIST* list) {
    if (!IsEmpty(list)) {
        LIST* del = list->next;
        list->next = list->next->next;
        free(del);
    }
}
/*Deletes all items from the list*/
void DeletingListElements(LIST* list) {
    while (!IsEmpty(list)) {
        Pop(list);
    }
}

/*Receives an array (table of inversions)
 *as input and creates the following from it*/
int NextInversionTable(int* inv,int n) {

    /*It goes from the end of the array and checks whether
     *it is possible to increase the number at this position
     *so that the array remains a correct permutation*/
    for (int i = n - 1; i >= 0; i--)
        if (*(inv + i) < n - 1 - i) {
            (*(inv + i))++;

            /*Reset all elements to the right of the enlarged one.*/
            for (int j = i + 1; j < n; j++) {
                *(inv + j) = 0;
            }
            return 1;
        }
    return 0;
}

/*Builds a permutation based on the inversion table.*/
void PermutationFromInversionTable(const int* invTable,int n,const int* arr,int* res) {

    LIST* list = CreateList();

    if (list == NULL){
        puts("Memory allocation error");
        return;
    }

    /*Each value in the inversion table corresponds to the number of elements
     *larger than the number in the sorted array of elements at the same
     *position as the value. Starting from the larger element (from the end
     *of the array), we arrange the elements in the list (permutation)*/
    for (int i = n - 1; i >= 0; i--) {
        Insert(list, *(arr + i),*(invTable + i));
    }

    Fill(list, res);
    DeletingListElements(list);
    free(list);
}

/*sorts a two-dimensional array using the bubble method*/
void Sorting2dBubble(int** arr,int quantityPerm,int n) {
    for (int i = 0; i < quantityPerm - 1; i++)
        for (int j = 0; j < quantityPerm - i - 1; j++) {

            int flag = 0;

            for (int k = 0; k < n; k++) {

                if (*(*(arr + j) + k) > *(*(arr + j + 1) + k)) {
                    flag = 1;
                    break;
                }
                if (*(*(arr + j) + k) < *(*(arr + j + 1) + k))
                    break;

            }

            if (flag) {
                int* temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
}

/*Generates all tables of inversions and builds permutations
 *based on them , and then outputs them in lexicographic order.*/
void PermutationsInversionTable(int arr[],int n,void (*callback)(int* perm, int n)) {

    if ( n <= 0 || n > MAX_LENGTH_ARRAY) {
        puts("The length of the array must be in the range [1,12].");
        return;
    }

    if (NoDuplicate(arr,n) != 1)
        return;

    int* copy = (int*)malloc(n * sizeof(int));

    if (copy == NULL){
        puts("Memory allocation error");
        return;
    }

    memcpy(copy, arr, sizeof(int) * n);
    Sorting(copy,n);

    int* inv = (int*)calloc(n, sizeof(int));

    if (inv == NULL) {
        puts("Memory allocation error");
        free(copy);
        return;
    }

    int* perm = malloc(n * sizeof(int));

    if (perm == NULL) {
        puts("Memory allocation error");
        free(copy);
        free(inv);
        return;
    }
    /*Determines the number of permutations*/
    const int quantity = Factorial2(n);

    /* Сreates a two-dimensional array and
     * fills it with permutations*/
    int** allPerm = (int**)malloc(sizeof(int*) * quantity);

    if (allPerm == NULL){
        puts("Memory allocation error");
        free(copy);
        free(inv);
        free(perm);
        return;
    }

    for (int i = 0; i < quantity;i++ ) {
        *(allPerm + i) = (int*)malloc(n * sizeof(int));
        if (*(allPerm + i) == NULL) {
            for (int j = 0; j < i; j++)
                free(*(allPerm + j));
            free(allPerm);
            free(copy);
            free(inv);
            free(perm);
            return;
        }
    }

    int i = 0;
    do {
        PermutationFromInversionTable(inv,n, copy, perm);
        memcpy(*(allPerm + i), perm, n * sizeof(int));
        i++;

    } while (NextInversionTable(inv,n));

    free(copy);
    free(inv);
    free(perm);

    /*Sorts the array and outputs the permutations in
     *lexicographic order*/
    Sorting2dBubble(allPerm,quantity,n);

    for (int k = 0; k < quantity;k++)
        callback(*(allPerm + k),n);

    for (int k = 0; k < quantity;k++)
        free(*(allPerm + k));
    free(allPerm);
}

//2.4

/*Generates all combinations of indexes, converts each combination
 *into a permutation, and outputs the permutations in lexicographic order.*/

void PermutationsPlusOne(int arr[], int n,
                            void (*callback)(int* perm, int n)) {

    if ( n <= 0 || n > MAX_LENGTH_ARRAY) {
        puts("The length of the array must be in the range [1,12].");
        return;
    }

    if (NoDuplicate(arr,n) != 1)
        return;

    int* ind = (int*)calloc(n, sizeof(int));

    if (ind == NULL) {
        puts("Memory allocation error");
        return;
    }

    int* perm = (int*)malloc(sizeof(int) * n);

    if (perm == NULL){
        puts("Memory allocation error");
        free(ind);
        return;
    }
    int* copy = (int*)malloc(sizeof(int) * n);

    if (copy == NULL) {
        puts("Memory allocation error");
        free(ind);
        free(perm);
        return;
    }

    memcpy(copy, arr, sizeof(int) * n);
    Sorting(copy,n);

    int* newcopy = (int*)malloc(sizeof(int) * n);

    if (newcopy == NULL) {
        puts("Memory allocation error");
        free(ind);
        free(perm);
        free(copy);
        return;
    }

    /*Converting an array of indexes into a permutation*/
    while (1) {

        memcpy(newcopy, copy, sizeof(int) * n);
        int realLen = n;

        for (int i = 0; i < n; i++) {
            int takeInd = *(ind + i);
            *(perm + i) = *(newcopy + takeInd);

            for (int j = takeInd; j < realLen - 1; j++)
                *(newcopy + j) = *(newcopy + j + 1);

            realLen--;
        }

        callback(perm, n);

        /*Incrementally modifies the index array as a number
         *in the factorial number system*/

        /*It starts with the last digit and increases it
         *by 1, if the number remains in the acceptable range,
         *then a new array is received, if not, then we reset
         *this number and add 1 to the next digit.*/
        int pos = n - 1;
        while (pos >= 0) {
            (*(ind + pos))++;
            if (*(ind + pos) < n - pos)
                break;

            *(ind + pos) = 0;
            pos--;
        }

        if (pos < 0)
            break;
    }

    free(ind);
    free(perm);
    free(copy);
    free(newcopy);
}












