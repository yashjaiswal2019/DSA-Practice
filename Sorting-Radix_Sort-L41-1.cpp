// Radix Sort algorithm 

#include <iostream>
using namespace std;

void countSort(int *arr , int size , int pos);

void radixSort(int *arr , int size);

int main()
{
    int arr[] = {3 , 2, 5, 1, 6 , 1, 7, 4, 2, 5, 3, 8, 2, 9, 2, 0, 5, 6, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort(int *arr , int size , int pos){
    // making the freq array
    int freq[10] = {0};
    for (int i = 0 ; i < size ; i++){
        freq[(arr[i] / pos) % 10]++;
    }

    // making the cumilative freq array
    for (int i = 0 ; i < 9 ; i ++){
        freq[i + 1] += freq[i];
    }

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[(arr[i] / pos) % 10]] = arr[i];
    }

    // copying back to the given array from ans array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}

void radixSort(int *arr , int size){
    // Radix Sort --> sort elements from least significant digit to most significant digit using the count sort algo
    
    // finding the max element
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
    }

    // sorting the array using position 
    for (int pos = 1 ; max / pos > 0 ; pos *= 10){
        countSort(arr , size , pos);
    }

    return;
}