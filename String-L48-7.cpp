// sort the given string into the lexicographical order 

#include <iostream>
#include <string>
using namespace std;

void stringSort(string &st);

int main()
{
    string st = "codingwallah";

    stringSort(st);

    cout << st << endl;
}

void stringSort(string &st){
    // we will use countsort to solve this problem in O(n) time complexity
    
    // since there are only 26 alphabets we can just create an array of 26 size
    int length = st.length();

    int freq[26] = {0};
    for (int i = 0 ; i < length ; i++){
        freq[int (st[i] - 'a')]++;
    }

    // making the cumilative freq array
    for (int i = 0 ; i < 25 ; i++) freq[i + 1] += freq[i];

    // making the ans string
    int ans[length] = {0};
    for (int i = length - 1 ; i >= 0 ; i--){
        ans[--freq[int (st[i] - 'a')]] = int (st[i] - 'a');
    }
    
    // copying back the elements to the given string 
    for (int i = 0 ; i < length ; i++) st[i] = char (ans[i] + 'a');

}