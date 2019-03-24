import numpy as np
from math import sqrt

def findPrimesUpTo(N):
    
    primes = []
    for n in range(2, N+1):
        isPrime = True
        for i in range( 2, round(sqrt(n)+1) ):
            if(n%i==0):
                isPrime = False
        if(isPrime):
            primes.append(n)
            
    return primes

print("Calculating primes...")
primes = findPrimesUpTo(10**4)
print("Have primes")

def getPrimeFactors(n):
    reducable = n
    primeFactors = []
    powers = []
    for p in primes:
        #check only for p < sqrt(n)
        if(p*p > reducable):
            break
        #check of p is a prime factor
        if(reducable%p == 0):
            primeFactors.append(p)
            #check if it occurs more than once
            counter = 0
            while(reducable%p == 0):
                counter += 1
                reducable //= p
            #add the power of the factor to a list
            powers.append(counter)
    #check if there's one more prime factor beyond sqrt(n)
    if(reducable>1):
        primeFactors.append(int(reducable))
        powers.append(1)
        
    return primeFactors, powers

""" 
source: https://www.geeksforgeeks.org/sum-proper-divisors-natural-numbers-array/

To find all divisors, we need to consider
all powers of a prime factor and multiply
it with all all powers of other prime factors.
(For example, if the number is 36, its prime
factors are 2 and 3 and all divisors are 1,
2, 3, 4, 6, 9, 12 and 18.

Consider a number N can be written 
as P1^Q1 * P2^Q2 * P3^Q3 (here only 3 
prime factors are considered but there can 
be more than that) then sum of its divisors 
will be written as:
 = P1^0 * P2^0 * P3^0 + 
   P1^0 * P2^0 * P3^1 + 
   P1^0 * P2^0 * P3^2 + 
   ................ + 
   P1^0 * P2^0 * P3^Q3 + 
   P1^0 * P2^1 * P3^0 + 
   P1^0 * P2^1 * P3^1 + 
   P1^0 * P2^1 * P3^2 + 
   ................ + 
   P1^0 * P2^1 * P3^Q3 +
   .
   .
   .
   P1^Q1 * P2^Q2 * P3^0 + 
   P1^Q1 * P2^Q2 * P3^1 + 
   P1^Q1 * P2^Q2 * P3^2 + 
   .......... + 
   P1^Q1 * P2^Q2 * P3^Q3

Above can be written as,
(((P1^(Q1+1)) - 1) / 
  (P1 - 1)) * (((P2^(Q2+1)) - 1) / 
  (P2 - 1)) * (((P3^(Q3 + 1)) - 1) / 
  (P3 - 1))
"""

#def getDivisorsSumSq(n):
#    
#    factors, powers = getPrimeFactors(n)
#    #print(factors, powers)
#    mult = 1
#    for i, factor in enumerate(factors):
#        mult *= ( pow(factor, 2*(powers[i]+1)) - 1 ) // (factor**2 - 1)
#        
#    return mult

def getDivisorsSum(n):
    
    factors, powers = getPrimeFactors(n)
    #print(factors, powers)
    mult = 1
    for i, factor in enumerate(factors):
        mult *= ( pow(factor, (powers[i]+1)) - 1 ) // (factor - 1)
        
    return mult

# [1] https://en.wikipedia.org/wiki/Aliquot_sequence
	
maxNum = 10**6

for a in range(10, maxNum):
    sequence = [a]
    chainLen = 1
    while True:
        sequence.append( getDivisorsSum(sequence[-1]) - sequence[-1] )
        if sequence[-1] == sequence[0]:
            print(a, chainLen)
            break
        elif sequence[-1] in sequence[:-1] or sequence[-1] == 1 or sequence[-1] > maxNum:
            #print("{} diverges ({})".format(a, sequence[-1]))
            break
        chainLen += 1