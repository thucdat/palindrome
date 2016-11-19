// This is the C++ version of the program to find the longest
// palindrome in a very long string
#include <iostream>
#include <algorithm>

using namespace std;

// This function verifies if a string is a palindrome
bool is_palindrome(string aStr)
{
    string bStr(aStr);
    reverse(bStr.begin(), bStr.end());
    return aStr == bStr;
}

// This function scans a string to find the longest palindrome
// It returns the found string or an empty string if not found
string find_longest_palindrome(string aLongStr)
{
    string result(""); 
    int ln = aLongStr.length();
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

