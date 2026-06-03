// practicing the radix sort algorithm 

#include <iostream>
using namespace std;

void countSort (int *arr , int size , int pos);

void radixSort(int *arr , int size);

int main()
{
    int arr[] = {3 , 4, 2, 5, 1, 6, 7, 8, 2, 4 , -1 , 2, -4 , -6 , 0 , -22 , 786 , 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr , size);

    // printing the Sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort (int *arr , int size , int pos){
    // we do not have to find the largest element
    
    // making the freq array
    int freq[10] = {0};
    for (int i = 0; i < size ; i++){
        freq[(arr[i] / pos) % 10]++;
    }

    // making the cmilstive freq array
    for (int i = 0 ; i < 9 ; i++){
        freq[i + 1] += freq[i];
    }

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[(arr[i] / pos ) % 10]] = arr[i];
    }

    // copying the elements back from the ans array to the given array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}

void radixSort(int *arr , int size){
    // repeatedly sort the elements of the array from least significant digit to most significant digit 

    // finding the max element 
    int max = INT32_MIN;
    int min = INT32_MAX;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    // narmalising our array in case if it contains -ve elements 
    for (int i = 0 ; i < size ; i++){
        arr[i] -= min;
    }

    // repeatedly calling the count sort fn to sort the array according to the position 
    for (int pos = 1 ; (max - min)/ pos > 0 ; pos *= 10){
        countSort(arr , size , pos);
    }

    // adding back the min element so our array remains unchanged
    for (int i = 0 ; i < size ; i++){
        arr[i] += min;
    }

}