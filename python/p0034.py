import numpy as num

digits = []
n = 0
factorialSum = 0
sumOfCurious = 0

for i in range (10, 2000000):
	n = i
	factorialSum = 0
	while (int(n) > 0):
		digits.append(int(n)%10)
		n /= 10
	#print(digits)
	
	for j in range (0, len(digits)):
		factorialSum += num.math.factorial(digits[j])
	#print(factorialSum)
	
	if ( factorialSum == i ):
		sumOfCurious += i
	digits.clear()
	
print(sumOfCurious)