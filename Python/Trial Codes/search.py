#Searching (Linear, Binary)
#Hash tables are usually faster, O(1) as keys are checked
#Linear search 
#Best case: O(1)
#Worst case: O(n)
#Returns the index of item in list
def LinearSearch(dataSet, item):
    #For all items
    for x in range(0, len(dataSet)):
        #If a match is found
        if dataSet[x] == item:
            #Return that index
            return x
    #-1 means an item is not found
    return -1

#List must be sorted.
def BinarySearch(dataSet, item, iterations):

    if len(dataSet) <= 1:
    #Cannot befound
        return (-1,iterations)

    #Iterations counter
    iterations +=1

    #Find midpoint
    mid = len(dataSet) // 2
    index = 0
    #Check if mid is the value (best case first time)
    if dataSet[mid] == item:
        return (mid, iterations)
    
    #If larger, means we check left as item is smaller than current index
    if dataSet[mid] > item:
        #Find again on LHS
        index, iterations = BinarySearch(dataSet[:mid],item, iterations)
    else:
        #Find again on RHS
        index, iterations = BinarySearch(dataSet[mid:],item, iterations)

    return (index, iterations)

#Sample Data
dataSet = [1,5,6,7,8,2]
print("LinearSearch index:",LinearSearch(dataSet,2))
dataSet = [1,2,3,4,5,6,7,8,9,10]
binaryResult = BinarySearch(dataSet,10,0)
print("Binary Search Index: {}, Iterations: {}".format(binaryResult[0], binaryResult[1]))