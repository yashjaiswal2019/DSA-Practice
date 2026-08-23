// how we use size() fn for strings

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    string str = "Yash";

    cout << str.length() << endl << str.size() << endl;
    // these have O(1) Time complexity

    // if we had an character array
    char name[] = "Jaiswal";
    cout << strlen(name) << endl; 
    return 0;
}