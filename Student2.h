//
// Created by Lenovo on 22.01.2026.
//

#ifndef PROJECT2_STUDENT2_H
#define PROJECT2_STUDENT2_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct list {
    int value;
    struct list* next;
}LIST;

void Swap(int* a1, int* a2);
void Reverse(int arr[], int start, int end);
void Sorting(int* arr, int n);
void PrintPermutation(int* perm,int n);

bool NextPermutationNarayana(int* arr, int n);
bool PrevPermutationNarayana(int* arr, int n);

void PermutationNarayana(int arr[], int n,
                          void (*callback)(int* perm, int n));
void PermutationReverseNarayana(int arr[], int n,
                          void (*callback)(int* perm, int n));

bool ChooseStepPermutationNarayana(int arr[], int n, int direction);
void ChoosePermutationNarayana(int arr[], int n,void (*callback)
                                       (int* perm, int n), int direction);


long Factorial(int n);
void PermutationFromIndex(int arr[], int n,
                        long index, int result[]);
void PermutationsFactorialSystem(int arr[],
        int n,void (*callback)(int* perm, int n));

LIST* CreateList();
void Fill(const LIST* list,int* arr);
void Insert(LIST* list, int value, int indInsert);
bool IsEmpty(const LIST* list);
void Pop(LIST* list);
void DeletingListElements(LIST* list);
int NextInversionTable(int* inv, int n);
void PermutationFromInversionTable(const int* invTable, int n,const int* arr,int* res);

void Sorting2dBubble(int** arr, int quantityPerm, int n);
void PermutationsInversionTable(int arr[],int n,void (*callback)(int* perm, int n));

void PermutationsPlusOne(int arr[], int n,
                            void (*callback)(int* perm, int n));

#endif //PROJECT2_STUDENT2_H


