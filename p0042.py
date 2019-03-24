import numpy as np

words = np.genfromtxt('p042_words.txt', delimiter=',', dtype=str)
wordValues = np.zeros(len(words))

for i, word in enumerate(words):
    for j, letter in enumerate(sorted(word)):
        wordValues[i] += ord(letter) - 64
        
tris = []
for i in range(1, 21):
    tris.append(i*(i+1)/2)
    
count = 0
for value in wordValues:
    if value in tris:
        count += 1

print(count)