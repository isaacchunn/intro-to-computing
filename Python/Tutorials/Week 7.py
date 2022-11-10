#Base reverser function provided by NTULearn

def reverser(a_str):
   if len(a_str) == 1:	# base case
      return a_str
   else:				# recursive step
      new_str = reverser(a_str[1:])+ a_str[0]
      return new_str        


#Based on the reverser() function that we already know,
#develop a function called reverseAndRepeat(a_str, num) that reverses the a_str string and 
# repeats each character in a_str for num times.  For example,
#myStr = "ABC"
#str1 = reverseAndRepeat(myStr,2)
#str1 == #CCBBAA
def reverseAndRepeat(a_str, num):
   reversedStr = reverser(a_str)
   returnStr = ""
   for char in reversedStr:
      returnStr += char * num
   return returnStr

def reverseAndRepeatRecursive(a_str, num):
   if len(a_str) == 1:        #base case
      return (a_str * num)
   else:
      new_str = reverseAndRepeatRecursive(a_str[1:], num) + a_str[0] * num
      return new_str
   
#Reverses the string and changes it to opp case
def reverseAndOppositeCase(a_str):
   reversedStr = reverser(a_str)
   returnStr = ""
   #For loop to check for case
   for char in reversedStr:
      #Check if lower case and upper case, and append to our returnb str
      if char.islower():
         returnStr += char.upper()
      else:
         returnStr += char.lower()
   return returnStr
#ABC
#BC
#C

#Recursive version of the reverse and opposite case function
def reverseAndOppositeCaseRecursive(a_str):
   if not a_str.isalpha():
      return
   if len (a_str) == 1:
      if a_str.islower():
         return a_str.upper()
      else:
         return a_str.lower()
   else:
      firstChar = a_str[0]
      if firstChar.islower():
         firstChar = firstChar.upper()
      else:
         firstChar = firstChar.lower()
      new_str = reverseAndOppositeCaseRecursive(a_str[1:]) + firstChar
      return new_str
         
#Returns a symetric string with a_str as it's prefix
def symmetricString(a_str):
   return a_str + reverser(a_str)

#Recursive version
def symmetricStringRecursive(a_str):
   if len (a_str) == 1:
      return a_str + a_str
   else:
      new_str = a_str[0] + symmetricStringRecursive(a_str[1:]) + a_str[0]
      return new_str

# myStr = "ABC"
# str0 = reverser(myStr)
# print(str0)             # CBA

# myStr = "ABC"
# str1 = reverseAndRepeat(myStr, 2)
# str2 = reverseAndRepeat(myStr, 3)
# print(str1)		# CCBBAA
# print(str2)		# CCCBBBAAA

myStr = "AbCdE"
reversedOppCaseStr = reverseAndOppositeCaseRecursive(myStr)
print("reversed and opposite case:", reversedOppCaseStr) #cba

myStr = "AbCdE"
symmetricStr = symmetricStringRecursive(myStr)
print("symmetric string: ", symmetricStr)                 #ABCCBAD