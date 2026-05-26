#include <climits>
#include <iostream>
using namespace std;

void countSort (int *arr , int size);

int main()
{
    int arr[] = {2, 6, 3, 4, 1, 6, 9, 7, 0, 8, 3, 5, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the sorted array
    for (int &ele :  arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort (int *arr , int size){
    // finding the highest element
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
    }

    // making the freq array
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

    // copying back to freq array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}