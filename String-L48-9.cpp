// You are given two strings 's' and 't' return true if t is an anagram of s else return false.

// My solution.

#include <iostream>
#include <string>
using namespace std;

bool checkAnagram(string &s1 , string &s2);

int main()
{
    string s = "aad";
    string t = "bbd";

    // cin >> s;
    // cin >> t;

    // we know that two strongs are anagram if both of them have same number of each alphabet.

    cout << checkAnagram(s, t) << endl;
    return 0;
}

bool checkAnagram(string &s1 , string &s2){
    // both string will have equal length 
    // we can solve this ques in one pass if we observe number of each possible alphabet 
    // odd + odd = even                                                 }
    // even + even = even                                               } ---> This is wrong
    // no matter what every alphabet's total occourence will be even    }

    if(s1.length() != s2.size()) return false;
    else{
        int length = s1.size();
        int freq1[26] = {0};
        int freq2[26] = {0};

        for (int i = 0 ; i < length ; i++){
            freq1[int (s1[i] - 'a')]++;
            freq2[int (s2[i] - 'a')]++;
        }

        // checking 
        for (int i = 0 ; i < length ; i++){
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }
}