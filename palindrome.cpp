#include <iostream>
#include <algorithm>

using namespace std;

bool is_palindrome(string aStr)
{
    string bStr(aStr);                  // (1)
    reverse(bStr.begin(), bStr.end());
    return aStr == bStr;                // (2)
}

string find_longest_palindrome(string aLongStr)
{
    string result("");                      // (3)
    int ln = aLongStr.length();             // (4)
    for (int n = ln; n > 0; n--)
    {
        string aStr;
        for (int ind = 0; ind < n; ind++)
        {
            aStr = aLongStr.substr(ind, n-ind+1);
            if (is_palindrome(aStr) and (aStr.length() > result.length()))
            {
                result = aStr;              // if any palindrome is found,
                break;                      // skip the rest
            }
        }
        if (aStr.length() == n) break;      // if the first iterative with length n
                                            // is palindrome, skip the rest
    }
    return result;
}

int main(int argc, char** argv) {
    cout << "Longest Palyndrome is: " << find_longest_palindrome(argv[1]) << endl;
    return 0;
}

// (1) Since reverse() changes a string in place, a copy is made.
// (2) This is how to prove if a string is a palindrome
// (3) Create a local string
// (4) Take the length of the input string