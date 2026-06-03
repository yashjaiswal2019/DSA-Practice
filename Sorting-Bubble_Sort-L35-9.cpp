// practicing the bubble sort algorithm

#include <iostream>
using namespace std;

void countSort(int *arr , int size);

int main()
{
    int arr[] = {3 , 4, 2, 5, 1, 6, 7, 8, 2, 4 , -1 , 2, -4 , -6 , 0 , -22 , 786 , 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr , size);

    // printing the sorted array
    for (int &ele : arr){
        cout << ele << " ";
    }

    return 0;
}

void countSort(int *arr , int size){
    // countSort --> repeatdly swap the adjacent elements if the are not in correct order

    for (int i = 0 ; i < size - 1 ; i++){
        bool swapHappen = false;
        for (int j = 0 ; j < size - i - 1 ; j++){
            if (arr[j] > arr[j + 1]) {
                swap(arr[j] , arr[j + 1]);
                swapHappen = true;
            }
        }

        if (swapHappen == false) break;
    }

    return;
}