#Trying to self implement sorting based off knowledge learnt before
import random

#Function to generate a random int of x times and returns a list
def generateDataSet(number, minRange =0, maxRange = 100):
    dataSet = []
    for x in range(number):
        dataSet.append(random.randint(minRange,maxRange))
    
    return dataSet
#Trial bubble sort
#Time complexity: best (n), worst is n ^2 
#Iterations (if 5): 5 x 4, 5 x 3, 5 x 2, 5 x 1
def bubbleSort (dataSet, ascendingOrder = True):
    #We should be comparing based off min 
    #Double for loop, taking indexes instead of element
    totalIterations = 0 
    for x in range(0, len(dataSet) -1):
        swapped = False
        for y in range (x, len(dataSet) -1): #Starts from x to reduce repeated checking over variables we have already checked and should have replaced
            #print(dataSet[y], end = " ")
            totalIterations+=1
            doSwap = False
            if ascendingOrder:
                #Current is larger than next index
                doSwap = dataSet[x] > dataSet[y+1]
            else:
                #Current is smaller than next index
                doSwap = dataSet[x] < dataSet[y+1]
            
            #If we are doing a swap...
            if doSwap:
                #Set a temp varaiable for dataSet[x]
                tempVar = dataSet[x]
                #Updater dataSet[x]
                dataSet[x] = dataSet[y+1]
                #Update dataSet[y + 1] with the original value of dataSet[x]
                dataSet[y+1] = tempVar
                #Update swapped variable
                swapped= True

        #Additional optimisations
        if not swapped:
            print ("[BS] Iterations done: {}, Data set is sorted!".format(x+1))
            #This means the func can braek early if no iterations was done, or if in this iteration the list was already sorted to the highest degree.
            break

         #Total iterations checker
    print("[BS] Total iterations checked: {}".format(totalIterations))

#Merge Sort
def mergeSort(dataSet):
    #If current len is one then no further splitting is required
    if len(dataSet) <= 1:
        return dataSet

    #Get total length of list
    midPoint = len(dataSet) // 2
    #Seperate into the sets
    leftSet = dataSet [:midPoint]
    rightSet = dataSet [midPoint:]
    # print("Left Set:", leftSet)
    # print("Right Set:", rightSet)

    #Recursively call sort for the other lists until end condition is specified
    leftList = mergeSort(leftSet)
    #Right set as well
    rightList = mergeSort(rightSet)

    #Temporary resultList that is returned
    resultList = []
    #while the indexes havent reached the end of EITHER sets
    #print("Len: ",len(leftList), len(rightSet))
    while leftList and rightList:
        #print("L: ", l, "R:", r)
        if(leftList[0] < rightList[0]):
            resultList.append(leftList[0])
            leftList.pop(0)
        else:
            #Right hand side smaller
            resultList.append(rightList[0])
            rightList.pop(0)
    
    #Check which element still has items
    if leftList:
        resultList.extend(leftList)
    else:
        resultList.extend(rightList)

    return resultList

dataSet = [2,9,4,3,5,8,6]
dataSet = mergeSort(dataSet)
print(dataSet)
#dataSet = [54,93,26,17,77,31,44,55,20]s
# dataSetSize= 20
# dataSet = generateDataSet(dataSetSize)
# print ("Original Data Set:", dataSet)
# sameSet = dataSet
# bubbleSort(dataSet,True)
# print("[BS] Data Set:" ,dataSet)


