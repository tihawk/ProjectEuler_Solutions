#Things to consider:
#1. Number n to be risen to power m can produce a number of m digits only if 0<m<9, since 10^m has m+1 digits
#2. 21 is the maximal power at which a number under 10 produces more than m-1 digits when risen to power m

count = 0
for i in range(1, 22):
    for j in range(10):
        num = j**i
        numStr = str(num)
        if(len(numStr)==i and num!=0):
            count += 1
            
print(count)