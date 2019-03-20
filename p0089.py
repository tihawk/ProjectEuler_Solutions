import numpy as np

data = np.genfromtxt('p089_roman.txt', delimiter='\n', dtype=str)
n0 = 0
n1 = 0
for i in range(len(data)):
    n0 += len(data[i])
    data[i] = data[i].replace("VIIII", "IX")
    data[i] = data[i].replace("IIII", "IV")
    data[i] = data[i].replace("LXXXX", "XC")
    data[i] = data[i].replace("XXXX", "XL")
    data[i] = data[i].replace("DCCCC", "CM")
    data[i] = data[i].replace("CCCC", "CD")
    n1 += len(data[i])

print(n0 - n1)