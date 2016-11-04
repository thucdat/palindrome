def is_palyndrome(aStr):
    return aStr == aStr[::-1]
	
def find_longest_palyndrome(aLongStr):
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
