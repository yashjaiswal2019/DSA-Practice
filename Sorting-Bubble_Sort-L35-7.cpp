// practicing the bubble sort algorithm

#include <iostream>
using namespace std;

void mergeSort(int *arr , int size);

int main()
{
    int arr[] = {5 , 3, 4, 6, 1, 2 , 8, 7, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr , size);

    // printing the sorted array
    for (int &ele : arr) {
        cout << ele << " ";
    }
    return 0;
}

void mergeSort(int *arr , int size){
    // repeatedly swap the adjacent elements if they are in wrong order
    for (int i = 0 ; i < size - 1 ; i++){
        bool flag = false;
        for (int j = 0 ; j < size - i - 1 ; j++){
            if (arr[j] > arr[j+1]){
                swap (arr[j] , arr[j+1]);
                flag = true;
            }
        }

        if (flag == false) break;
    }
    return;
}