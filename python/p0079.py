import numpy as np 

keylog = np.genfromtxt('p079_keylog.txt', delimiter='\n', dtype=int)

def toDigitArray(n):
    result = []
    reducable = n
    while True:
        result.append(reducable%10)
        reducable = reducable // 10
        if reducable < 1:
            break
    return reversed(result)

logins = np.zeros((len(keylog), 3), dtype=int)
for i, log in enumerate(keylog):
    logins[i] = np.array([*toDigitArray(log)])
    
averagePositions = np.zeros( (10, 2) )
for i in range(10):
    averagePositions[i] = np.array([i, np.mean( np.where( logins==i )[1] )])
    
numOrder = averagePositions[ np.argsort(averagePositions[:, 1]) ]

print(numOrder)