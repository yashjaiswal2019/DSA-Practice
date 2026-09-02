// You are given two strings 's' and 't' return true if t is an anagram of s else return false.

// Mam's Solution

#include <iostream>
#include <string>
using namespace std;

bool checkAnagram(string &s1 , string &s2);

int main()
{
    string s = "aad";
    string t = "bbd";

    (checkAnagram(s , t)) ? cout << "True" << endl : cout << "false" << endl;
    return 0;
}

bool checkAnagram(string &s1 , string &s2){
    // we can solve this with creating single array as 
    // do ++ for s1 and --> for s2.
    // if some element left +ve s1 have extra alphabets and if -ve left s2 have an extra alphabet

    if(s1.size() != s2.size()) return false;
    else{
        int arr[26] = {0};
        int size = s1.size();
        for (int i = 0 ; i < size ; i++){
            arr[int (s1[i] - 'a')]++;
            arr[int (s2[i] - 'a')]--;
        }

        // checking 
        for (int i = 0 ; i < size ; i++){
            if (arr[i] != 0) return false;
        }
        return true;
    }
}