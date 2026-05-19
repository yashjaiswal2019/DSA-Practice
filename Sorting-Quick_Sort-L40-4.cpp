#include <iostream>
using namespace std;

int pivot (int *arr , int first , int last);

void quickSort(int *arr , int first , int last);

int main()
{
    int arr [] = {3 , 6, 4, 8, 5, 7, 1, 9, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr , 0 , size - 1);

    // printing the sorted array
    for (int &ele : arr) cout << ele << " ";

    return 0;
}

int pivot (int *arr , int first , int last){
    int curr = arr[last] , i = first - 1;

    for (int j = first ; j < last ; j++){
        if (arr[j] < curr){
            i++;
            if(j!=i) swap(arr[j] , arr[i]);
        }
    }

    // now our i will be pointing at the element on which left elemants are smaller than the curr and right elements are bigger than curr
    swap(arr[last] , arr[i+1]);

    return i + 1; 
}

void quickSort(int *arr , int first , int last){
    // Quick Sort --> repeatedly select pivot element form unsorted array and place it ar its correct position
    // correct position --> element on left are smaller than pivot element and elements on right are bigger than pivot element

    // base case 
    if (first >= last) return;

    // assumption and left work

    int p_idx = pivot(arr , first , last);
    
    quickSort(arr , first , p_idx - 1);
    quickSort(arr , p_idx + 1 , last);

    return;
}