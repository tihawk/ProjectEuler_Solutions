import numpy as np

digits = np.array([ 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 ])
hundredAnd = np.array([ 0, 13, 13, 15, 14, 14, 13, 15, 15, 14 ])
teens = np.array([ 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 ])
tens = np.array([ 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 ])

def decompose(a):
    res = 0
    numHundreds = a%1000 - a%100
    numHundredsDigit = round(numHundreds/100)
    res += hundredAnd[numHundredsDigit]
    if(a==100 or a==200 or a==300 or a==400 or a==500 or a==600 or a==700 or a==800 or a==900):
        res -= 3
    numTens = a%100
    if(numTens < 10):
        res += digits[numTens]
    elif(numTens > 9 and numTens<20):
        numTeens = numTens%10
        res += teens[numTeens]
    elif(numTens > 19):
        numTens = numTens - a%10
        numTensDigit = round(numTens/10)
        res += tens[numTensDigit]
        numDigit = a%10
        res += digits[numDigit]
    return int(res)
	
result = 0
for i in range(0, 999):
    result += decompose(i+1)

print(result+11)