// we are given an Encoded string and have to return the decoded string

// after seeing mam's solution

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string decode(string &str);

int main()
{
    string str = "3[ab2[2[x]3[y]]]";

    string result = decode(str);
    cout << result << endl;

    return 0;
}

string decode(string &str)
{
    string result;
    int size = str.length();

    for (int i = 0; i < size; i++)
    { // this loop decodes the innermost string at a time
        if (str[i] != ']')
            result += str[i];
        else
        {
            string temp;
            // extracting the temp string from result
            int j = result.length() - 1;
            while (result[j] != '[')
            {
                temp = result[j] + temp;
                result.pop_back();
                j--;
            }

            // popping the last character in string
            result.pop_back();

            // extracting the number from the string and convertig it to integer
            int k = result.length() - 1;
            int num = 0;
            int pos = 1;
            while ('0' <= result[k] and result[k] <= '9')
            {
                int digit = result[k] - '0';
                num += digit * pos;
                pos *= 10;
                result.pop_back();
                k--;
            }

            // adding this temp string to the reult num times
            while (num >= 1)
            {
                result.insert(result.length(), temp);
                num--;
            }
        }
    }
    return result;
}
