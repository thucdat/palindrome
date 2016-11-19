# This is the Python version of the program to find the longest
# palindrome in a very long string

def is_palyndrome(aStr):
    '''
    This function verifies if a string is a palindrome
    '''
    return aStr == aStr[::-1]
	
def find_longest_palyndrome(aLongStr):
    '''
    This function scans and finds the longest palindrome in a string
    It returns the found palindrome or an empty string if not found
    '''
    result = ""
    ln = len(aLongStr)
    for n in range (ln, 0, -1):
        aStr = ""
        for ind in range(0, n): 
            aStr = aLongStr[ind:n]
            if is_palyndrome(aStr) and len(aStr) > len(result):
                result = aStr
                break
        if len(aStr) == n: break
    return result  

import sys
print find_longest_palyndrome(sys.argv[1])
