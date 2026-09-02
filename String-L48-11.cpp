// we are given two strings 's' and 't' and we have to tell wherther they are ismorpic or not.
// solving using mam's solution.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int index (char &x);

bool isIsomorphic(string &s1, string &s2);

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (isIsomorphic(s1, s2)) cout << "isomorphic" << endl;
    else cout << "Not isomorphic" << endl;

    return 0;
}

int index (char &x){
    // this fn returns the index of the alphabet from ASCII to 0 based indexing
        return int(x - 'a');
}

bool isIsomorphic(string &s1, string &s2) {
    // we have to check in both the strings that if
    // a is maped to b then in other string b is mapped to a
    vector<int> freq1(26, -1);
    vector<int> freq2(26, -1);

    if (s1.size() != s2.size()) return false;
    // checking if these have same column number in that freq array
    int size = s1.size();
    for (int i = 0 ; i < size ; i++){
        int idx1 = index(s1[i]);
        int idx2 = index(s2[i]);
        if (freq1[idx1] != freq2[idx2]) return false;
        else freq1[idx1] = freq2[idx2] = i;
    }

    return true;
}
