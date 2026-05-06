// pravticing the merge sort algorithm

#include <iostream>
using namespace std;

void merge(int *arr , int Aleft , int Aright , int Bleft , int Bright);

void mergeSort (int *arr , int first , int last);

int main()
{
    int arr[] = {6 , 7, 3, 5, 4, 1, 2 , 9, 8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort (arr , 0 , size - 1);

    // printing the sorted array

    for (int &ele : arr){
        cout << ele << " ";
    }
    return 0;
}

void merge(int *arr , int Aleft , int Aright , int Bleft , int Bright){
    // size of the arrays
    int Asize = Aright - Aleft + 1;
    int Bsize = Bright - Bleft + 1;

    // making the temp arrays 'a' and 'b'.
    int a[Asize] , b[Bsize];

    for (int i = 0 ; i < Asize ; i++) a[i] = arr[Aleft + i];
    for (int i = 0 ; i < Bsize ; i++) b[i] = arr[Bleft + i];

    // sorting the arrays in the ans array
    
    int i = 0 , j = 0 , k = Aleft;

    while (i < Asize and j < Bsize){
        if (a[i] < b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    // fillin in the element left after on array exhausts
    while (i < Asize) arr[k++] = a[i++];
    while (j < Bsize) arr[k++] = b[j++];

    return;
}

void mergeSort (int *arr , int first , int last){
    // repeatedly sort the smmaller arrays and merge them into one final sorted aray

    // base case 
    if (first == last) return;

    // self work and assumption

    int mid = (first + last) / 2;

    mergeSort(arr , first , mid);
    mergeSort(arr , mid + 1 , last);
    merge(arr , first , mid , mid + 1 , last);

    return;
}