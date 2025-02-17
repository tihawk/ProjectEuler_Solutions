import numpy as np

names = np.genfromtxt("p022_names.txt", delimiter=',', dtype=str)
namesSorted = np.sort(names)

def nameToScore(name):
    listOfChars = list(name)
    score = 0
    for i, char in enumerate(listOfChars):
        score += ord(char) - 64
    return score

total = 0
for i, name in enumerate(namesSorted):
    nameScore = nameToScore(name)
    multied = (i+1)*nameScore
    total += multied
    
print(total)