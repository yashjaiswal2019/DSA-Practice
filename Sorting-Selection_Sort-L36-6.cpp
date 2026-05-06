// practice selection sort
#include <iostream>
using namespace std;

void selectionSort(int *arr , int size);

int main()
{
    int arr[] = {7, 5, 3, 6, 4, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    selectionSort(arr , size);

    // printing the array
    for (int &ele : arr){
        cout << ele << " ";
    }
    return 0;
}

void selectionSort(int *arr , int size){
    // selection sort --> repeatedly select the minimum element from the unsorted array and place it in the end of sorted array
    for (int i = 0  ; i < size - 1 ; i++){
        int min_idx = i;
        for (int j = i ; j < size ; j++){
            if (arr[j] < arr[min_idx]) min_idx = j;
        }

        if (min_idx != i) swap(arr[min_idx] , arr[i]);
    }
    return;
}