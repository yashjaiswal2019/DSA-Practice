// practicing the binary search problems.

/**given an array of integers sorted in non decreasing-order find the first and last position 
 * of the given target 'target' element in sorted array. follow the "0" based indexing 
 * if the target is not found in the array return [-1 , -1].
 * 
 * input = [1 , 2, 3, 3, 3, 5 , 11]     target = 3
 * output = [2 , 4].
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> firstAndLast(vector<int> &arr , int target);

int main()
{
    vector<int> arr = {1 , 2, 3, 3, 3, 5 , 11};

    int target;
    cout << "please enter the value of target : ";
    cin >> target;

    vector<int> ans = firstAndLast(arr , target);
    // printing the ans array
    for (int &ele : ans) cout << ele << " ";

    return 0;
}

vector<int> firstAndLast(vector<int> &arr , int target){
    // we will use binary search algorithm twice 
    // first --> to find the first occourence and then to find the last occourence 

    // first occourence.
    int flo = 0 , fhi = arr.size() - 1;
    
    int first = -1;
    while (flo <= fhi){
        int fmid = flo + (fhi - flo) / 2;

        if (arr[fmid] == target){
            first = fmid;
            fhi = fmid - 1;
        }
        else if (arr[fmid] > target) fhi = fmid - 1;
        else flo = fmid + 1; 
    }

    if (first == -1) return {-1 , -1};

    // last occourenc.
    int llo = 0 , lhi = arr.size() - 1;

    int last = -1;

    while (llo <= lhi){
        int lmid = llo + (lhi - llo) / 2;

        if (arr[lmid] == target){
            last = lmid;
            llo = lmid + 1;
        }
        else if(arr[lmid] < target) llo = lmid + 1;
        else lhi = lmid - 1;
    }

    return {first , last};
}