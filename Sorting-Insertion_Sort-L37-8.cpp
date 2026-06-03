// practicing the insertion sort Algorithm 

#include <iostream>
using namespace std;

void insertionSort(int *arr , int size);

int main()
{
    int arr[] = {3 , 4, 2, 5, 1, 6, 7, 8, 2, 4 , -1 , 2, -4 , -6 , 0 , -22 , 786 , 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void insertionSort(int *arr , int size){
    // repeatedly select the element from the unsorted array and insert it inside the sorted array
    for(int i = 0 ; i < size ; i++){
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 and  arr[j] > curr) {
            arr[j + 1] = arr[j];
            j--;
        }
        // now our j will be ponting at the place from which all elements of left including it will be less than curr and 
        // to the right all elements will be greater than the current element

        arr[j + 1] = curr;
    }

    return;
}