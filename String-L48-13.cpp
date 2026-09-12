// we are given an array of striings and we have to return the longest prefix in the array of strings

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPrefix(vector<string> &arr);

int main () {
    vector<string> arr = {"flower" , "flow" , "flight"};

    string ans = longestPrefix(arr);

    if(ans.length() == 0) cout << "No Common prefix" << endl;
    else cout << ans << endl;
    return 0;
}

string longestPrefix(vector<string> &arr) {
    int arrSize = arr.size();
    int stringSize = arr[0].size();
    string ans;

    for (int i = 1 ; i < arrSize ; i++) {
        for (int j = 0 ; j < stringSize ; j++) {
            if (arr[i][j] == '\0') return ans;
            else {
                if (arr[i][j] == arr[0][j]) ans += arr[i][j];
                else return ans;
            }

            // if (arr[i][j] == arr[0][j]) ans += arr[i][j];
            // else return ans;
        }
    }
}

// this solution is wrong 