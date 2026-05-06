// Quick Sort Algo practice
#include <iostream>
using namespace std;

int pivot(int *arr , int first , int last);

void quickSort (int *arr , int first , int last);  

int main()
{
    int arr[] = {5 , 3, 4, 6, 1, 2, 8, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort (arr , 0 , size - 1);

    // printing the array
    for (int &ele : arr){
        cout << ele << " ";
    }
    return 0;
}

int pivot(int *arr , int first , int last){
    int i = first - 1 , pivot = arr[last];

    for (int j = first ; j < last ; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }

    // now our i will be at index on ehich left elements are less and right elements are bigger 
    // so the ans will be i + 1
    swap(arr[i+1] , arr[last]);
    return i + 1;
}

void quickSort (int *arr , int first , int last){
    // repeatedly place the pivot element at its correct position
    // correct position --> where all elements to left are smaller and on right all elements are bigger than pivot
    
    // base case
    if (first >= last) return;

    // assumption
    int p_idx = pivot(arr , first , last);
    quickSort (arr , first , p_idx-1);
    quickSort(arr , p_idx + 1 , last);
    return;
}