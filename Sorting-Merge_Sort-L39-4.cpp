// practicing the Merge Sort Algorithm
#include <iostream>
using namespace std;

void merge(int *arr , int Aleft , int Aright , int Bleft , int Bright);

void mergeSort(int *arr , int left , int right);

int main()
{
    int arr[]= {6 , 4, 5, 2, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr , 0 , size);

    // printing the array 
    for (int &ele : arr){
        cout << ele << " ";
    }
    return 0;
}

void merge(int *arr , int Aleft , int Aright , int Bleft , int Bright){
    // merging the sorted arrays
    int Asize = Aright - Aleft + 1;
    int Bsize = Bright - Bleft + 1;

    // making the temp arrays a and b
    int a[Asize];
    int b[Bsize];

    for(int i = 0 ; i < Asize ; i++) a[i] = arr[Aleft + i];
    for(int i = 0 ; i < Bsize ; i++) b[i] = arr[Bleft + i];
    
    // merging the arrays
    int i = 0 , j = 0 , k = Aleft;

    while (i < Asize and j < Bsize){
        if (a[i] < b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    // filling the remaining elements
    while (i < Asize) arr[k++] = a[i++];
    while (j < Bsize) arr[k++] = b[j++];

    return;
}


void mergeSort(int *arr , int left , int right){
    // this is a recursive relation that we recursively sort the left and right part of array and merge them into one final array
    
    // Base Case
    if (left == right) return;
    
    // assumption and self work
    int mid = (left + right) / 2;

    mergeSort(arr , left , mid);
    mergeSort(arr , mid + 1 , right);
    merge(arr , left , mid , mid + 1 , right);

    return;
}