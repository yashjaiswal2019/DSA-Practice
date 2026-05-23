// practicing the count sort algorithm 

#include <iostream>
using namespace std;

void countSort(int *arr , int size);

int main()
{
    int arr[] = {3 , 4, 12, 5, 3, 6, 7, 5, 23, 4, 5, 2, 9, 67, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the ans array 
    for (int &ele : arr) cout << ele << " ";

    return 0;
}

void countSort(int *arr , int size){
    // finding the maximum element
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++) if (arr[i] > max) max = arr[i];

    // making the freq arry
    int freq[max + 1] = {0};
    for(int i = 0 ; i < size ;i++) freq[arr[i]]++;

    // making the contigual freq array
    for (int i = 0 ; i < max ; i++) freq[i + 1] += freq[i];

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--) ans[--freq[arr[i]]] = arr[i];

    // copying the ans array to the given array
    for (int i = 0 ; i < size ; i++) arr[i] = ans[i];

    return;
}