// we are given an array of striings and we have to return the longest prefix in the array of strings

// Mam's Solution
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPrefix(vector<string> &arr);

int main () {
    vector<string> arr = {"ant" , "anti" , "anthem"};

    string ans = longestPrefix(arr);\
    if(ans.size() == 0) cout << "no common prefix" << endl;
    else cout << ans << endl;
    return 0;
}

string longestPrefix(vector<string> &arr){
    // we can sort the array of strings and then we can compare the first and the last string
    // and the common prfix in first and last string then it will be present in all other strings

    // mam used the sort fn that is butilt in the arrays
    sort(arr.begin() , arr.end());

    string ans;
    int last = arr.size() - 1;
    int size = min(arr[0].size() , arr[last].size());
    for (int i = 0 ; i < size ; i++) {
        if (arr[0][i] == arr[last][i]) ans += arr[0][i];
        else return ans;
    }
}