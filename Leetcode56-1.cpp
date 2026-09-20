// Merge Intervals

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals);

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = merge(intervals);

    // printing the ans 
    for (vector<int> arr : result) {
        for(int ele : arr) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // sort the array first so that all overlaping intervals come together
    sort(intervals.begin(), intervals.end());

    // mergin the intervals
    vector<vector<int>> ans;
    int size = intervals.size();
    ans.push_back(intervals[0]);
    for (int i = 1; i < size ; i++) {
        if (ans.back()[1] >= intervals[i][0]) {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else ans.push_back(intervals[i]);
    }

    return ans;
}