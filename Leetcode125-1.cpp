// 125. Valid Palindrome
// my solution

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &str);

int main()
{
    string s = "0P";
    cout << isPalindrome(s) << endl;
    return 0;
}

bool isPalindrome(string &str) {
    // we can use two pointers to check if palindrome
    // lets take the string via refernce and create a copy string 
    int strSize = str.length();
    string s;
    for (int i = 0 ; i < strSize ; i++) {
        if (str[i] >= 'A' and str[i] <= 'Z') {
            s += char(int('a' + (str[i] - 'A')));
        }
        else if (str[i] >= 'a' and str[i] <= 'z') {
            s += str[i]; 
        }
        else if (str[i] >= '0' and str[i] <= '9') {
            s += str[i]; 
        }
        
    }

    // now we can check if palindrome 
    int size = s.length();
    int l = 0 , r = size - 1;
    bool isTrue = true;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return isTrue;
}