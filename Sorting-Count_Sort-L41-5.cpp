// practicing the count sort Algorithm 

#include <iostream>
using namespace std;

void countSort(int *arr , int size);

int main()
{
    int arr[] = {6 , 3,  2, 4, 1, 8, 6, 9, 5, 3, 4, 2, 6, 7, 1, 4, 2, 8, 89, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}


void countSort(int *arr , int size){
    // finding the largest element in the given array
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
    }

    // makinag the freq array
    int freq[max + 1] = {0};
    for (int i = 0 ; i < size ; i++){
        freq[arr[i]]++;
    }

    // making the cumilative freq array
    for (int i = 0 ; i < max ; i++){
        freq[i + 1] += freq[i];
    }

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[arr[i]]] = arr[i];
    }

    // copying the values to the givemn array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}