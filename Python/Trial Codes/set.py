
#Function that wraps between the max and min index defined by the user
def Wrap(value, minValue, maxValue):
    if value < minValue:
        return maxValue
    elif (value > maxValue):
        return minValue  
    return value

s = [1,2,3,4]

powerSet = [None] * pow(2, len(s))
currentIndex = 1
for i in range(0, len(s)):
    #Single values
    powerSet[currentIndex] = (s[i]) 
    currentIndex+=1
    print(currentIndex)

print(currentIndex)
#Generates the pairs
for i in range(0, len(s)):
    for x in range (i+1,len(s)):
        powerSet[currentIndex] = (s[i], s[x])
        currentIndex+=1

print(currentIndex)
#Generates the triplets
for i in range (0, len (s)-1):
    for x in range (i+1, len (s)):
        #print(s[i], s[x], s[x+1])
        for z in range(x + 1, len(s)):
            powerSet[currentIndex] = (s[i], s[x], s[z])
            currentIndex+=1

powerSet[currentIndex] = (s)
print(currentIndex)
print(powerSet)