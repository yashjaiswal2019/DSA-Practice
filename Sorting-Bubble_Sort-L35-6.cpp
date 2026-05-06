// Bubble Sort practice 
#include <iostream>
using namespace std;

void bubbleSort (int *arr ,int size);

int main()
{
    int arr[]= {5 , 3, 6, 4, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort (arr , size);

    // printing the ans array
    for (int &ele : arr){
        cout << ele << " ";
    }
    return 0;
}

void bubbleSort (int *arr ,int size){
    // bubble Sort --> repeatedly swap adjacent elements if they are in wrong place 
    for (int i = 0 ; i < size -1 ; i++){
        
        bool flag = false;

        for (int j = 0 ; j < size - i - 1 ; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                flag = true;
            }
        }

        if (flag == false) break;
    }
    return;
}