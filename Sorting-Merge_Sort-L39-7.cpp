// practicing the merge sortalgorithm 

#include <iostream>
using namespace std;

void merge (int *arr , int Aleft , int Aright , int Bleft , int Bright);

void mergeSort (int *arr , int start , int end);

int main()
{
    int arr[] = {3 , 4, 2, 5, 1, 6, 7, 8, 2, 4 , -1 , 2, -4 , -6 , 0 , -22 , 786 , 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr , 0 , size - 1);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void merge (int *arr , int Aleft , int Aright , int Bleft , int Bright){
    // merging the sorted arrays

    // findig the size of arrays 
    int Asize = Aright - Aleft + 1;
    int Bsize = Bright - Bleft + 1;

    // making the temp arrays a and b 
    int a[Asize];
    int b[Bsize];

    for (int i = 0 ; i < Asize ; i++) a[i] = arr[Aleft + i];
    for (int i = 0 ; i < Bsize ; i++) b[i] = arr[Bleft + i];

    // mergeing the arrays a and b int one array
    int i = 0 , j = 0 , k = Aleft;
    
    while (i < Asize and j < Bsize){
        if (a[i] < b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    // filling in the elements left after merging the array if ont array exhausts 
    while (i < Asize) arr[k++] = a[i++];
    while (j < Bsize) arr[k++] = b[j++];
    
    return;
}

void mergeSort (int *arr , int start , int end){
    // repeatedly sort the subarrays and then merge them together in one algorithm 

    // base-case 
    if(start >= end) return;

    // assumption and self - work
    int mid = (start + end) / 2;
    mergeSort(arr , start , mid);
    mergeSort(arr , mid + 1 , end);

    merge(arr , start , mid , mid + 1 , end);

    return;
}
