// practing the selection sort sorting algorithm 
#include <iostream>
using namespace std;

void selectionSort(int *arr , int size);

int main()
{
    int arr[] = {3 , 4, 2, 5, 1, 6, 7, 8, 2, 4 , -1 , 2, -4 , -6 , 0 , -22 , 786 , 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void selectionSort(int *arr , int size){
    // repeatedly select the smallest element from the unsorted array and place it at the end of sorted array
    for(int i = 0 ; i < size - 1 ; i++){        // we do not have to sort all of the elements if total - 1 elements are sorted then the last element will be at correct place 
        int minIdx = i;

        for (int j = i + 1 ; j < size ; j++){
            if(arr[j] < arr[minIdx]) minIdx = j;
        }

        if (minIdx != i) swap(arr[i] , arr[minIdx]);
    }

    return;
}