// we are given an Encoded string and have to return the decoded string 

// my solution

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string decode(string &str);

int main()
{
    string str = "3[b2[ca]]";
    
    string result = decode(str);

    cout << result << endl << "yash";
    return 0;
}

string decode(string &str) {
    // lets use a for loop and traverse the srting in reverse direction
    string ans;
    int size = str.size();
    for(int i = size - 1; i >= 0 ; i--){
       if (str[i] == ']' || str[i] == '[') continue;
        else if ('a' <= str[i] and str[i] <= 'z') ans = str[i] + ans;
        else {
            int j = str[i] - '0';
            string temp = ans;
            while (j > 1){
                ans += temp;
                j--; 
            }
        }
    }
    return ans;
}

// this solution only works in this testcase and will now work cases like these 3[a]2[bc]. 