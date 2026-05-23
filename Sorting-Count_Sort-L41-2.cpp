// practicing the count sort algorithm 

#include <iostream>
using namespace  std;

void countSort(int *arr , int size);

int main()
{
    int arr[] = {3 , 6, 4, 5, 2, 1 , 3, 2, 4, 5, 8, 9, 6, 7, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort(int *arr , int size){
    // fining the miximum element
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
    }

    // making the freq array
    int freq[max + 1] = {0};        // initializing the freq array with 0
    for (int i = 0 ; i < size ; i++){
        freq[arr[i]]++;
    }

    // making the contigual freq array
    for (int i = 0 ; i < max ; i++){
        freq[i + 1] += freq[i];
    }

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[arr[i]]] = arr[i];       // at the position in the ans array we are placing the value given at i th index in the given array. 
    }

    // copying the values to the given array from ans array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}