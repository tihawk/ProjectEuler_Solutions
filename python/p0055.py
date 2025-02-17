def reverseInt(a):
    return int( ''.join( reversed( str(a) ) ) )

def checkPalindrome(p):
    return ''.join( reversed( str(p) ) ) == str(p)

lychrelCount = 0
for i in range(10**4):
    isLychrel = True
    candidate = i + reverseInt(i)
    for j in range(50):
        if(checkPalindrome(candidate)==True):
            isLychrel = False
            break
        candidate = candidate + reverseInt(candidate)
    if isLychrel:
        lychrelCount += 1
        
print(lychrelCount)