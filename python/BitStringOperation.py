# Given two bit strings of length n, find the bitwise AND,
# bitwise OR, and bitwise XOR of these strings.

def AND(strA, strB):
    result = ''
    n = len(strA)
    for i in range(0, n):
        if(strA[i] == '1' and strB[i] == '1'):
            result += '1'
        else:
            result += '0'
    return result


# Test data
a = '0101101'
b = '1111111'
c = AND(a, b)
print(c)
