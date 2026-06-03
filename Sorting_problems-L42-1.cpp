// find the kth smallest element in the given array using quick sort algorithm 

#include <iostream>
using namespace std;

int partition (int *arr , int start , int end);

int kthsmallest (int *arr , int start , int end , int k);

int main()
{
    int arr[] = {3 , 5, 2, 1, 4, 7, 8 , 6};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    int result = kthsmallest (arr , 0 , size - 1 , k);

    cout << "the kth smallest element is = " << result;

    return 0;
}

int partition (int *arr , int start , int end){
    // using the quick sort algo 
    int i = start - 1 , pivot = arr[end];

    for (int j = start ; j < end ; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[j] , arr[i]);
        }
    }

    // now our i will be pointing at the position from which elements on left are smaller ans elements on right are bigger
    // our ans will be i + 1

    swap(arr[i + 1] , arr[end]);
    
    return i + 1;

}

int kthsmallest (int *arr , int start , int end , int k){
    // using the Quick sort algo --> we have to pick the pick the element and find its position using the partition fn 
    
    if (k < 0 || k > end - start + 1) return INT32_MAX;
    
    int pos = partition (arr , start , end);

    if (pos - start == k - 1) return arr[pos];
    else if (pos - start > k - 1) return kthsmallest (arr , start , pos - 1 , k);      // if the (pos > k - 1) then we have to check the left side of our array 
    else return kthsmallest (arr , pos + 1 , end , k - (pos - start + 1));


}