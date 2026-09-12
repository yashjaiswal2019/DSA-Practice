// we are given an Encoded string and have to return the decoded string 

// my solution

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string decode(string &str , int i);

int main()
{
    string str = "3[b2[ca]]";
    
    string result = decode(str , 0);

    cout << result << endl;
    return 0;
}

string decode(string &str , int i) {
    // base case 
    if (str[i] == '[') return decode(str , ++i);
    else if (str[i] == ']') return "";
    else if ('a' <= str[i] and str[i] <= 'z') {
        string x;
        x += str[i];
        return x;
    }
    else {
        int x = int (str[i] - '0');

        string y;
        while (str[i] != ']') {
            y += str[i];
            i++;
        }

        string z;
        while (x >= 0) {
            y += y;
            x--;
        }
        return z + decode(str , ++i);
    }

}