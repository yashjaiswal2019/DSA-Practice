// how concatination works in strings 
// how can we concatinate character arrays using "strcat" fn  
// how we use push_back fn in strings

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    string s1 = "Yash";
    string s2 = "Jayasaval";

    cout << s1 + s2 << endl;

    // if i have to append s2 to s1 
    s1 += s2; // this will add s2 to s1
    cout << s1 << endl;

    // cincatinating character arrays
    char s3[20] = "Yash";
    char s4[20] = "Jaiswal";

    strcat(s3 , s4);
    cout << s3 << endl;

    // using push_back fn in string
    char ch = 'X';  // have to store the character in a character variable
    s1.push_back(ch);
    s1.push_back('Y');
    cout << s1 << endl;
    
}