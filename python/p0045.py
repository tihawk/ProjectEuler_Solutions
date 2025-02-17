import numpy as np
#Note, that all hexagonal numbers are also triangular numbers, hence triangulars can be omitted
def generate(n):
    pent = n*( 3*n - 1 )/2
    hexa = n*( 2*n - 1 )
	#tri = n*(n+1)/2
    return np.array([pent, hexa], dtype=object)
    
nums = 10**5
generated = np.zeros((nums, 2))
for i in range(nums):
    generated[i] = generate(i)
    
HexAndPents = np.intersect1d(generated[:, 0], generated[:, 1])
#allIntersects = np.intersect1d(hexAndPents, generated[:, 3])
print(HexAndPents[-1])