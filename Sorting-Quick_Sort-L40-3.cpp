// practicing the Quick Sort Algorithm
#include <iostream>
using namespace std;

int pivot (int *arr , int first , int last);

void quickSort(int *arr , int first , int last);

int main()
{
    int arr[] = {4 , 3, 6, 5, 1, 2, 7, 9, 8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr , 0 , size - 1);

    // printing thr sorted array
    for (int &ele : arr) cout << ele << " ";
    return 0;
}

int pivot (int *arr , int first , int last){
    // take the element from the last of array and place it in its correct position
    int pivot = arr[last] , i = first - 1;
    
    for (int j = first ; j < last ; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }

    // now i is pointing to elements on which to left elements are less and to right elements are greater
    swap (arr[i+1] , arr[last]);
    return i + 1;
}

void quickSort(int *arr , int first , int last){
    // repeatedly place the pivot element at the correct position in the array
    // correct position --> elements to the left are smaller and elements to the right are larger then the current element

    // bast case 
    if (first >= last) return;

    // assumption and self work
    int pivot_idx = pivot(arr , first , last);

    quickSort(arr , first , pivot_idx - 1);
    quickSort(arr , pivot_idx + 1 , last);
    return;
}