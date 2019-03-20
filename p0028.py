import numpy as np
#Grann square of nine?

sides = np.arange(3, 1003, 2)
diffs = np.arange(2, 1002, 2)
bigCorners = np.power(sides, 2)
corners = np.array([ bigCorners, (bigCorners-diffs), (bigCorners-2*diffs), (bigCorners-3*diffs) ])

print(np.sum(corners)+1)