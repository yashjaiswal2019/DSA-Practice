// practicing the count sort algorithm 

#include <iostream>
using namespace std;

void countSort(int *arr , int size);

int main()
{
    int arr[] = {3 , 2, 5, 4, 1, 6, 8 ,5, 2, 4, 3, 1, 5 , 6, 7, 8, 4, 5, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the freq array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort(int *arr , int size){
    // finding the largest element
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
    }

    // making the freq array
    int freq[max + 1] = {0};
    for(int i = 0 ; i < size ; i++){
        freq[arr[i]]++;
    }

    // making the contigual freq array
    for (int i = 0 ; i < max ; i++){
        freq[i + 1] += freq[i];
    }

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--){      // filling in this way makes the count sort a stable sorting algorithm
        ans[--freq[arr[i]]] = arr[i];
    }

    // copying the ans array to the given array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}