// practicing the merge sort algorithm 

#include <iostream>
using namespace std;

void merge (int *arr , int Aleft , int Aright , int Bleft , int Bright);

void mergeSort(int *arr , int start , int end);

int main()
{
    int arr[] = {3 , 4, 2, 5, 1, 6, 7, 8, 2, 4 , -1 , 2, -4 , -6 , 0 , -22 , 786 , 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr , 0 , size - 1);

    // printing the sorted array.
    for (int &ele : arr) cout << ele << " ";

    return 0;
}

void merge (int *arr , int Aleft , int Aright , int Bleft , int Bright){
    // finding the size of arrays 'a' and 'b'.
    int Asize = Aright - Aleft + 1;
    int Bsize = Bright - Bleft + 1;

    // making the temp arrays 'a' and 'b' 
    int a[Asize] , b[Bsize];
    for (int i = 0 ; i < Asize ; i++) a[i] = arr[Aleft + i];
    for (int i = 0 ; i < Bsize ; i++) b[i] = arr[Bleft + i];

    // merging the arrays 
    int i = 0 , j = 0 , k = Aleft;
    while (i < Asize && j < Bsize){
        if (a[i] < b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    // filling in the elements left after one of the arrays is exhausted;
    while (i < Asize) arr[k++] = a[i++];
    while (j < Bsize) arr[k++] = b[j++];

    return;
}

void mergeSort(int *arr , int start , int end){
    // this is a recursive function.

    // base case
    if (start >= end) return;

    // self - work and assumption 
    int mid = start + (end - start) / 2;
    
    mergeSort(arr , start , mid);
    mergeSort(arr , mid + 1 , end);

    merge(arr , start , mid , mid + 1 , end);

    return;
}