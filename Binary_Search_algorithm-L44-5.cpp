/**find the first occourence of an element X , given that the array is sorted 
 * if no occourences of x is found , return -1;
 * 
 * example : arr[] = {2 , 5 , 5, 5 , 6 , 6 , 8, 9, 9, 9}
 */

#include <iostream>
using namespace std;

int firstOccourence(int *arr , int size , int target);

int main()
{
    int arr[]= {2 , 5 , 5, 5 , 6 , 6 , 8, 9, 9, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "please enter the value of X :";
    cin >> target;

    int ans = firstOccourence(arr , size , target);
    cout << ans << endl;

    return 0;
}

int firstOccourence(int *arr , int size , int target){
    // we will use binary search algorithm for this question 

    int lo = 0 , hi = size -1;
    int index = -1;

    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target){
            // have to check left
            hi = mid - 1;
            index = mid;
        }
        else if(arr[mid] > target) hi = mid - 1;
        else { // in this case our arr[mid] < target ==> we have to check the right of the array
            lo = mid + 1;
        }
    }

    return index;
}