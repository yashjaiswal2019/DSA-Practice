// longest subString without Repeating 
// my solution

#include <iostream>
#include <string>
using namespace std;

 int lengthOfLongestSubstring(string& s);

int main() 
{
    string s = "1R1T7";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}

int lengthOfLongestSubstring(string& s) {
    int maxSize = 0;
    int freq[128] =  {0};
    int p1 = 0 , p2 = 0, size = s.length();
    while (p2 < size) {
        if (freq[int(s[p2])] >= 1) {
            // character already exists in the substr
            // p1 = p2;
            // for (int &ele : freq) ele = 0;
            while (freq[int(s[p2])] != 0) {
                freq[int(s[p1])]--;
                p1++;
            }
            freq[int(s[p2])]++;
            p2++;

        }
        else {
            // we can check the string size now 
            int currSize = p2 - p1 + 1;
            maxSize = max(maxSize , currSize);
            freq[int(s[p2])]++;
            p2++;
        }
    }
    return maxSize;
}