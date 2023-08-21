# Program converts binary string to decimal
# next it calculates how many operations are needed to bring value down to 0
# if even divide by 2
# if odd substract - 1

A1 = "011100"
A2 = "111"
A3 = "1111010101111"

def convertBinToInt(S):
    return int("".join(str(x) for x in S), 2);

def solution(S):
    count = 0

    value = (convertBinToInt(S))

    while (value != 0):
        if value % 2 == 0:
            value = value / 2
            count = count + 1
        else:
            value = value - 1
            count = count + 1
    return count

print(A1)
print(solution(A1))
print(A2)
print(solution(A2))
print(A3)
print(solution(A3))
