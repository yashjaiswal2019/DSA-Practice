// radix sort Algorithm

#include <iostream>
using namespace std;

void countSort (int *arr , int size , int pos);

void radixSort (int *arr , int size);

int main()
{
    int arr [] = {5 , 4, 6, 3, 7, 2, 8, 1, 9 , 0, 1, 2, 7, 5, 3, 4, 7, 8, 2, 3, 6, 5, 4, 8, 9, 4, 65, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort (int *arr , int size , int pos){
    // we do not have to find the max element as it will in the range from 0 to 9.

    // making the freq arr
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

    // copying the elements 
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}

void radixSort (int *arr , int size){
    // repeatedly sort element from least significant digit to most significant digit repeatedly 

    // finding the max element
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
    }

    // calling the count sort fn with position 
    for (int pos = 1 ; max / pos > 0 ; pos *= 10){
        countSort(arr , size , pos);
    }

    return;
}