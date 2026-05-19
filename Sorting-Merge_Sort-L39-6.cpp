// practicing the merge sort algorithm

#include <iostream>
using namespace std;

void merge(int *arr , int Aleft , int Aright , int Bleft , int Bright);

void mergeSort(int *arr , int first , int last);

int main()
{
    int arr[] = {2 , 0, 6, 8, 3, 4, 1, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr , 0 , size - 1);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }
    return 0;
}

void merge(int *arr , int Aleft , int Aright , int Bleft , int Bright){
    // size of arrays
    int Asize = Aright - Aleft + 1;
    int Bsize = Bright - Bleft + 1;
    
    // maiing temp arrays 'a' and 'b'
    int a[Asize];
    int b[Bsize];
    for (int i = 0 ; i < Asize ; i++) a[i] = arr[Aleft + i];
    for (int i = 0 ; i < Bsize ; i++) b[i] = arr[Bleft + i];

    // merging the arrays

    int i = 0 , j = 0 , k = Aleft;

    while (i < Asize and j < Bsize){
        if (a[i] < b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    // filling in the remaining elements after or array is exhausted 
    while (i < Asize) arr[k++] = a[i++];
    while (j < Bsize) arr[k++] = b[j++];

    return;
}

void mergeSort(int *arr , int first , int last){
    // merge sort Algorithm --> repeatedly merge the two sorted arrays into one single sorted array

    // base case 
    if (first >= last) return;

    // assumption and self work
    int mid = (first + last ) / 2 ;
    mergeSort(arr , first , mid);
    mergeSort(arr , mid + 1 , last);

    merge(arr , first , mid , mid + 1 , last);

    return;
}