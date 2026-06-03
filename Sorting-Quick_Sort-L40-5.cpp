// practicing the Quick Sort algorithm 

#include <iostream>
using namespace std;

int pivot (int *arr , int first , int last);

void quickSort(int *arr , int first , int last);

int main()
{
    int arr[] = {3 , 4, 2, 5, 1, 6, 7, 8, 2, 4 , -1 , 2, -4 , -6 , 0 , -22 , 786 , 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr , 0 , size - 1);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

int pivot (int *arr , int first , int last){
    int i = first - 1 , curr = arr[last];

    for(int j = first ; j < last ; j++){
        if (arr[j] < curr){
            i++;
            if (i != j) swap(arr[i] , arr[j]);
        }
    }

    // after this our i will be pointing at the index from which all elements on left are smaller and all elements on right are bigger
    
    swap (arr[i + 1] , arr[last]);

    return i + 1;
}

void quickSort(int *arr , int first , int last){
    // repeatedly select the pivot element from the unsorted array and place it its correct index in the array

    // base - case
    if (first >= last) return;

    // assumption and self work
    int pIdx = pivot(arr , first , last);
    quickSort(arr , first , pIdx - 1);
    quickSort(arr , pIdx + 1 , last);

    return;
}