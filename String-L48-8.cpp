// sort the given string into the lexicographical order 

#include <iostream>
#include <string>
using namespace std;

string lexicographicalOrder (string &name);

int main()
{
    string name = "codingwallah";

    // we have to convert this string into lexicographical order 

    string result = lexicographicalOrder(name);

    cout << result << endl;
    return 0;
}

string lexicographicalOrder (string &name){
    // we will use the count sort algorithm to sort this string 
    
    int size = name.size();

    // making the freq array
    int freq[26] = {0};
    for (int i = 0 ; i < size ; i++) {
        freq[int (name[i] - 'a')]++;
    }

    // we have to make the count sort stable so --> making the cumilative freq array
    for (int i = 0 ; i < 25 ; i++){
        freq[i+1] += freq[i]; 
    }

    // I am thinking to make the ans string directly without making the ans array first ---> Let's leave this for a second

    // making the ans array
    int ans[size] = {0};
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[int (name[i] - 'a')]] = int (name[i] - 'a');
    }

    // makig the ans string 
    string result;
    for (int i = 0 ; i < size ; i++){
        result += char (ans[i] + 'a');
    }

    return result;
}