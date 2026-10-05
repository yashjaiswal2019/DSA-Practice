// 242. Valid Anagram

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isAnagram(string &s, string &t);

int main()
{
    string s = "anagram" , t = "nagaram";
    cout << isAnagram(s, t) << endl;
    return 0;
}

bool isAnagram(string &s, string &t) {
    // we can use a freq array to store the freq of each string;
    // strings have to be of same size to be anagram
    if (s.length() != t.length()) return false;
    int n = s.length();
    vector<int> freq (26, 0);
    for (int i = 0 ; i < n ; i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    // checking if anagram
    for (int ele : freq) {
        if (ele != 0) return false;
    }
    return true;
}