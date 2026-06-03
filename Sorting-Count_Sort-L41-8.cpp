// practicing the count sort algorithm 

#include <iostream>
using namespace std;

void countSort(int *arr , int size);

int main()
{
    int arr[] = {4 , 3, 5, 2, 6, 1, 7, 0, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort(int *arr , int size){
    // finding the max element and min element
    int max = INT32_MIN;
    int min = INT32_MAX;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    // making the freq array
    int freq[max + 1] = {0};
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
        ans[--freq[arr[i] - min]] = arr[i];     // no need to subtract the min from all elements as the changes we made didn't change the origional array
    }

    // copying back elements from ans array to given array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}