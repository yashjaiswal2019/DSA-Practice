// we are given an array of striings and we have to return the longest prefix in the array of strings

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPrefix(vector<string> &arr);

int main()
{
    vector<string> arr = {"flash" , "flush"};

    string ans = longestPrefix(arr);

    if(ans.length() == 0) cout << "No Common prefix" << endl;
    else cout << ans << endl;
    return 0;
}

string longestPrefix(vector<string> &arr) {
    // we can check for every string in the vector 
    string result; 
    
    int size = arr[0].size();
    int arrSize = arr.size();
    for (int i = 0 ; i < arrSize ; i++ ) { // for iterating on strings
        for (int j = 0 ; j < size ; j++) {  // for iteraing on letters
            if (arr[i][j] != arr[0][j]) return result;
            else result += arr[0][j];
        }
    }
}