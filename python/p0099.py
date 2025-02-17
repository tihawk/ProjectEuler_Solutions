import numpy as np

biggest = 0
data = np.genfromtxt('p099_base_exp.txt', delimiter=',')
values = data[:, 1]*np.log(data[:, 0])
biggest = np.argmax(values)

print(biggest+1)