// practice insertion sort
#include <iostream>
using namespace std;

void selectionSort(int *arr , int size);

int main()
{
    int arr[] = {6, 4, 2, 5, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr , size);

    // printing the array
    for (int &ele : arr){
        cout << ele << " ";
    }
    return 0;
}

void selectionSort(int *arr , int size){
    // selection sort --> repeatedly select the element from the unsorted array and place it in the sorted array
    for (int i = 1 ; i < size ; i++){
        int curr = arr[i];
        int j = i-1;
        while (j >= 0 and arr[j] >= curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
    return;
}