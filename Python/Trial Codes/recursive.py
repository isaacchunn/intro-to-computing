#Recursive way to find maxNum

# num = 0
# def maxNum(dataSet):

#     global num
#     num +=1
#     #End condition
#     if len (dataSet) == 1:
#         return dataSet[0]
    
#     #Split the list and do some checking
#     leftNumber = dataSet[0]
#     dataSlice = dataSet[1:]
#     return max(leftNumber,maxNum(dataSlice))

# dataSet = [1,5,6,7,8,2]
# dataSet = [2,7,5]
# maxNo = maxNum(dataSet)
# print(maxNo)
# print(num)

sensitivity = 0.8
#e.g. range is 1 to 179
sense = (1+ abs(sensitivity - 1) * 179, 179 - abs(sensitivity - 1) * 179)
print(sense)