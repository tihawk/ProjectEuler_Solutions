def sumOfDigits(n):
    dSum = 0
    reducable = n
    while True:
        dSum += reducable%10
        reducable = reducable // 10
        if reducable < 1:
            break
    return dSum

biggestSum = 0
nums = range(100)
for i in nums:
    for j in nums:
        toCheck = pow(i, j)
        currentSum = sumOfDigits(toCheck)
        if currentSum > biggestSum:
            biggestSum = currentSum
            
print(biggestSum)