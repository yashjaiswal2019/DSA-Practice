// practicing the radix sort algorithm 

#include <iostream>
using namespace std;

void countSort (int *arr , int size , int pos);

void radixSort (int *arr , int size);

int main()
{
    int arr[] = {2 , 7, 4, 5, 6, 1, 9, 7, 8, 0, 6, 4, 5, 3, 7, 2, 3, 8, 4, 5, 1, 0, -1};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort (int *arr , int size , int pos){

    // don't have to find the maximum element

    // making the freq array
    int freq[10] = {0};
    for (int i = 0 ; i < size ; i++){
        freq[(arr[i] / pos) % 10]++;
    }

    // making the cumilative freq array
    for (int i = 0 ; i < 9 ; i++){
        freq[i + 1] += freq[i];
    }

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[(arr[i] / pos) % 10]] = arr[i];
    }

    // copying back from the ans array to the given array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}

void radixSort (int *arr , int size){
    // repeately sort the array's elements from lest significant digit to most significant digit

    // finding the max element
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
    }

    // using count sort for sorting the elements 
    for (int pos = 1 ; max / pos > 0 ; pos *= 10){
        countSort(arr , size , pos);
    }

    return;
}