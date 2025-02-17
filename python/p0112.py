import numpy as np

bouncy = 0
notBouncy = 0
ratio = 0.
total = 0

def func(a):
    global bouncy
    global notBouncy
    global ratio
    aStr = str(a)
    aArr = np.array([*aStr])
    aArrSort = np.sort(aArr)
    aArrFlip = np.flip(aArr)
    if( np.array_equal(aArr, aArrSort) or np.array_equal(aArrFlip, aArrSort) ):
        notBouncy += 1
    else:
        bouncy += 1
    ratio = bouncy/total
        
while(ratio != 0.99):
    total += 1
    func(total)
else:
    print(total)