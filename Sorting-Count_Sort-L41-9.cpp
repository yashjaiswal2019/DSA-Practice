// practicing the count sort algorithm 

#include <iostream>
using namespace std;

void countSort (int *arr , int size);

int main()
{
    int arr[]= {3 , 4, 2, 5, 1, 6, 7, 8, 2, 4 , -1 , 2, -4 , -6 , 0 , -22 , 786 , 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort (int *arr , int size){
    // finding the max element and min elemet
    int max = INT32_MIN;
    int min = INT32_MAX;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    // making the freq array
    int freq[max - min + 1] = {0};
    for (int i = 0 ; i < size ; i++){
        freq[arr[i] - min]++;
    }

    // making the cumilative freq array
    for (int i = 0 ; i < max - min ; i++){
        freq[i + 1] += freq[i];
    }

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[arr[i] - min]] = arr[i];
    }

    // copying back the ans array to the given array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}