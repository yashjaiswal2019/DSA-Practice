// practicing the insertion sort 

#include <iostream>
using namespace std;

void insertionsort(int *arr , int size);

int main()
{
    int arr[] = {4 , 2, 3, 1, 6, 5, 7, 9, 8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    insertionsort(arr , size);

    // printing the array
    for (int &ele : arr) cout << ele << " ";
    
    return 0;
}

void insertionsort(int *arr , int size){
    // repeatedly take the element from the unsorted array and insert it in the sorted array

    for (int i = 1 ; i < size ; i++){
        int curr = arr[i] , j = i - 1;
        while (j >= 0 and arr[j] > curr){
            arr[j+1] = arr[j];
            j--;
        }

        // now j will be pointing at the element which is less than curr the we will swap arr[j+1] and curr
        arr[j+1] = curr;
    }
    return;
}