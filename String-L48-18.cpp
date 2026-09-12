// given a binary string and an integer k , return the maximum number of conseutive number of 1's in the string if you can flip at most  0's

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxOnes (string &str , int k);

int main()
{
    string str = "0001101011";
    int k = 2;
    int result = maxOnes(str , k);

    cout << result << endl;
    return 0;
}

int maxOnes (string &str , int k) {
    // we will use sliding window technique 
    int start = 0 , end = 0;
    int zeroCount = 0;
    int windowSize = 0;

    int size = str.size();
    for ( ; end < size ; end++) {
        if (str[end] == '0') zeroCount++;
        
        while (zeroCount > k) {
            if(str[start] == '0') zeroCount--;
            start++;
        }

        int currentWindow = end - start + 1;
        windowSize = max(currentWindow , windowSize);
        
    }
    
    return windowSize;
}