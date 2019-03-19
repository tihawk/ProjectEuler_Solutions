#Note, don't need the 1000^1000 term
sum = 0
for i in range(1, 1000):
    sum += i**i
    
print(sum%10**10)