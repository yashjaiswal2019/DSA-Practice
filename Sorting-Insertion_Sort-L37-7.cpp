// practicing the insertion sort algorithm

#include <iostream>
using namespace std;

void insertionSort(int *arr , int size);

int main()
{
    int arr[] = {4 , 0, 8, 9, 5, 6, 2, 3, 1, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }
    return 0;
}

void insertionSort(int *arr , int size){
    // insertion sort --> repeatedly select the element from the unsorted array and insert it in the sorted array
    for (int i = 1 ; i < size ; i++){
        int curr = arr[i];
        
        int j = i - 1;
        while (j >= 0 and arr[j] > curr){
            arr[j+1] = arr[j];
            j--;
        }

        // now our j ill be pointing at the index on which left elemnts are smaller then curr 
        arr[j+1] = curr;
    }
    return;
}