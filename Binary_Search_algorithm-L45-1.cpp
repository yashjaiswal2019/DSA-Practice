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

vector<int> firstAndLast(vector<int> arr , int target);

int main()
{
    vector<int> arr = {-2, -1, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5};

    int target;
    cout << "please enter the value of the targert : ";
    cin >> target;

    vector<int> ans = firstAndLast(arr ,target);

    // printing the ans 
    cout << "[";
    for (int &ele : ans) cout << ele << " ";
    cout << "]" << endl;

    return 0;
}

vector<int> firstAndLast(vector<int> arr , int target){
    // we will use binary search algorithm twice 
    // one or finding the first occourence and one for finding the last occourence.

    // first occourence 

    int first = -1;

    int Flo = 0 , Fhi = arr.size() - 1;

    while (Flo <= Fhi){
        int Fmid = Flo + (Fhi - Flo) / 2;

        if (arr[Fmid] == target){
            first = Fmid;
            Fhi = Fmid - 1;
        }
        else if (arr[Fmid] > target) Fhi = Fmid -1;
        else Flo = Fmid + 1;
    }

    if (first == -1) return {-1 , -1};

    // last occourence 

    int last = -1;

    int Llo = 0 , Lhi = arr.size() - 1;

    while (Llo <= Lhi){
        int Lmid = Llo + (Lhi - Llo) / 2;

        if(arr[Lmid] == target) {
            last = Lmid;
            Llo = Lmid + 1;
        }
        else if (arr[Lmid] < target) Llo = Lmid + 1;
        else Lhi = Lmid - 1;
    }

    return {first , last};
}

/**
 *  Time Complexity = O(log n)
 * Space Complexity = O(1) 
 */