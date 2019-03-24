import numpy as np

cipher = np.genfromtxt('p059_cipher.txt', delimiter=',', dtype=int)
deciphered = np.zeros(len(cipher), dtype=int)
plain = np.zeros(len(cipher), dtype=str)
lowercaseRange = range(97, 123)
maybeIsKey = True

for i in lowercaseRange:
    for j in lowercaseRange:
        for k in lowercaseRange:
            key = np.array([i, j, k], dtype=int)
            
            for l, char in enumerate(cipher):
                deciphered[l] = char^key[l%3]
                if( deciphered[l] not in range(123) ):
                    maybeIsKey = False
                    break
                plain[l] = chr(deciphered[l])
                
            if maybeIsKey:
                print('\nkey: ' + ''.join([chr(key[0]), chr(key[1]), chr(key[2])]))
                print('sum: {}'.format(np.sum(deciphered)))
                print('text:\n' + ''.join(plain))
            maybeIsKey = True