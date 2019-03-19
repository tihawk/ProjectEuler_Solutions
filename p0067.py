import numpy as np

triangle = np.zeros((15, 15))
triangle = np.genfromtxt('p067_triangle.txt', delimiter=',', missing_values='', filling_values=0, dtype=np.int64)
m, n = np.shape(triangle)

for i in range(m-2, -1, -1):
    for j in range(n-1):
        if(triangle[i+1, j] > triangle[i+1, j+1]):
            triangle[i, j] += triangle[i+1, j]
        else:
            triangle[i, j] += triangle[i+1, j+1]
            
print(triangle[0, 0])