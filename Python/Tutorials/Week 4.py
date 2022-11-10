from random import *

#Constant variable
LENGTH = 8

def checkPasswordStrength(password, minimumPasswordLength):
    #Check the password if it has any special digits like numbers, capital letters or whatever
    print ("The password you have input is {}".format(password))
    #Check if user has a mix of lower and upper case
    hasLowandHigh = not password.islower() and not password.isupper()
    #Check if the whole password is only numbers
    hasOnlyNumbers = password.isnumeric()
    #Check if the whole password is only characters
    hasOnlyCharacters = password.isalpha()
    #Check the length of the password
    passwordLength = len(password)

    #Boolean to check if the password has digits/characters
    hasDigits = False
    hasCharacters = False
    #Same for numbers and special characters
    hasNumbers = False
    hasSpecialCharacters = False
    #Check if we contain any numbers to help
    for char in password:
        #Loop through each char to check certain things

        if(char.isdigit()):
            hasDigits = True
        elif (char.isalpha()):
            hasCharacters = True

        asciiChar = ord(char)
        if (48 <= asciiChar <= 57):
            #Then it's a number
            hasNumbers = True
        elif (35 <=asciiChar <=47 or asciiChar <= 64):
            #Special char codes
            hasSpecialCharacters = True

    #Return some results
    if passwordLength < minimumPasswordLength: #If the password does not meet the required length
        print("Your password is not long enough. You need {} more characters to hit the required length of {}".format(minimumPasswordLength-passwordLength,minimumPasswordLength))
    elif hasOnlyNumbers or hasOnlyCharacters: #Password only has characters or numbers
        print("Bad. Try to have a combination of characters and numbers to improve your security.")
    elif hasDigits and hasCharacters: #Password has characters and numbers
        if hasLowandHigh: #Has high and low characters
            if (hasNumbers == True and hasSpecialCharacters == True): #Has numbers and special characters
                print( "Very Strong. This password is secure.")
            elif (hasNumbers ==  True and hasSpecialCharacters == False): #Has numbers but no special characters
                print("Strong. Try to incorporate special characters.")
            elif (hasNumbers == False or hasSpecialCharacters == True): #Has no numbers but special characters
                print("Strong. Try to incorporate special characters if you haven't. ")
            else:
                print("Bad. Your password lacks special characters and numbers.") #Else it does not have any numbers or special numbers
        else:
            print("Your password does not contain a mix of uppercase and lower case letters.") #The password does not have mix of upper and lower case letters
    else:
        print("Bad. Your password does not have a mix of digits and characters.") #Password does not have digits and characters

def discussion1(password, minimumPasswordLength):
    return checkPasswordStrength(password, minimumPasswordLength)

def discussion3():
    #Create a dictionary to store the relevant items.
    labGrades = {
        "FS1" : [12,34,56,78,90],
        "FS2" : [90,87,65,43,21]
    }

    print(labGrades["FS1"][0])  
    pass

#Number of students in calss one, number of students in class.
def discussion4(studentsClassOne, studentsClassTwo, minMarks, maxMarks):
    
    listGradesOne = []
    listGradesTwo = []

    #Populate both lists with random range of numbers
    listGradesOne = [randrange(minMarks,maxMarks) for students in range(studentsClassOne)]
    listGradesTwo = [randrange(minMarks,maxMarks) for students in range(studentsClassTwo)]

    #Contents of list
    print("Class One:\n", listGradesOne, "\nClass Two:\n", listGradesTwo, sep ="")

    #Average of both classes
    averageClassOne = float(sum(listGradesOne) / len(listGradesOne))
    averageClassTwo = float(sum(listGradesTwo) / len(listGradesTwo))

    #Highest of both 
    highestMarksOne = max(listGradesOne)
    highestMarkTwo =  max(listGradesTwo)

    #Print the relevant average class
    if (averageClassOne == averageClassTwo):
        print("Both classes have same average")
    elif (averageClassOne > averageClassTwo):
        print("Class One has the higher average of {}".format(highestMarksOne))
    else:
        print("Class Two has the higher average of {}".format(highestMarkTwo))

    #Print the relevant highest marks
    if (highestMarksOne == highestMarkTwo):
        print("Both classes have same average")
    elif (highestMarksOne > highestMarkTwo):
        print("Class One has the highest maximum score of {}".format(highestMarksOne))
    else:
        print("Class Two has the highest maximum score of {}".format(highestMarkTwo))

def discussion5(startRange, endRange):
    squareList = [(x**2) for x in range(startRange,endRange +1) if x **2 % 3 == 0]
    return squareList


#discussion1(input("Enter your password to check it's strength: "),LENGTH)
discussion3()
#discussion4(15,15,0,100)
#print(discussion5(1,100))