// practicing the count sort Algorithm 

#include <iostream>
using namespace std;

void countSort(int *arr , int size);

int main()
{
    int arr[] = {3, 2, 4, 1, 5, 9, 6, 7, 0, 4, 5, 3, 2, 7, 6, 1, 8, 9, 0, -2, -56, -4, -3, 2, -7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;

}

void countSort(int *arr , int size){
    // since out array have both +ve and -ve numbers we will have to normalize our array first
    
    // finding the max and min element 
    int max = INT32_MIN;
    int min = INT32_MAX;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    // normalising the array , and making the freq array at the same time for better time complexity
    int freq[max - min + 1] = {0};
    for (int i = 0 ; i < size ; i++){
        freq[arr[i] - min]++;
    }
    
    // making the cumilative freq array
    for (int i = 0 ; i < max - min + 1 ; i++){
        freq[i + 1] += freq[i];
    }

    // making the ans array
    int ans[size];
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[arr[i] - min]] = arr[i];     // we do not have to add back the min ele as the changes we have made was not in the array
    }

    // copying back the elements to the ans array
    for (int i = 0 ; i < size ; i++){
        arr[i] = ans[i];
    }

    return;
}