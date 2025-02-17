import numpy as np

field = np.genfromtxt('p081_matrix.txt', delimiter=',', dtype=np.int64)
m, n = np.shape(field)

for i in range(1, m):
    field[i, 0] += field[i-1, 0]
    
for j in range(1, n):
    field[0, j] += field[0, j-1]

for i in range(1, m):
    for j in range(1, n):
        field[i, j] += min(field[i-1, j], field[i, j-1])
        
print(field[m, n])