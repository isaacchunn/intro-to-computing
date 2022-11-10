#Week 5 Tutorial

#Dictionary format would be
#(tuple) = score

#Allows the user to input new records into this database.
def inputRecord(dataBase, groupName, studentID, studentScore):
    #Check if such a key exists in the 
    if (groupName,studentID) in dataBase:
        #If exists we update value of that score
        print("There already exists a record of student {} in {} with score of {}.".format(studentID,groupName, dataBase[(groupName,studentID)]))
        #Error handling 
        while True:
            userInput = str(input("Do you want to overwrite the score? [Y/N]"))
            if userInput.lower() == "n":
                #Then we break from the function
                print("You have chosen [N]. Returning to main menu...")
                return
            elif (userInput.lower() == "y"):
                #Then we allow the overwriting
                break
            else:
                print("Invald option. Use [Y/N] only")          
                continue
    #If not, it does not exist and we can proceed to add the value.
    dataBase[(groupName,studentID)] = studentScore
    print("You have successfully entered a record in group [{}] with Student ID [{}] and score [{}].".format(groupName,studentID,studentScore))

#Allows the user to remove concurrent records into the database
def removeRecord(dataBase,groupName, studentID):
    #Check if such a key exists in the database
    if(groupName, studentID) in dataBase:
        while True:
            userInput = str(input("Are you sure you want to delete the record of student [{}] in [{}] with score of [{}] [Y/N]?".format(studentID,groupName,dataBase[(groupName,studentID)])))
            if userInput.lower() == "n":
                #Then we break from the function
                print("You have chosen [N]. Returning to main menu...")
                return
            elif (userInput.lower() == "y"):
                #Then we allow the overwriting
                break           
            else:
                print("Invalid option. Use [Y/N] only.")
                continue
        
        #Delete the entry in the database
        del dataBase[(groupName,studentID)]
        print("The record of student in group {} with ID {} was deleted.".format(groupName,studentID))


#Should return the score
def query(dataBase, group, id):
    try:
        return dataBase[(group,id)]
    except KeyError:
        return -1

#Return a list of grades in the group
def listGrades(database, group):
    try:
        #setList = [(x, database[x]) for x in database if x[0] == group]
        gradesList = [(x[1],database[x]) for x in database if x[0] == group]    
        return gradesList
        #Get all the entries with the input name  
    except KeyError:
        print("There is no element of key {} in the database!!".format(group))

#Should return the highest grade
def maxGrade(database, group):
    try:
        #Return the max grade
        return max(database[x] for x in database if x[0] == group)
        #return max(listGrades(database,group))
    except KeyError:
        print("There is no element of key {} in the database!!".format(group))
        return -1

def getKeyNames(database):
    try:
        keyList = []
        for keys in database:
            if keyList.count(keys[0]) > 0:
                continue
            keyList.append(keys[0])

        return keyList
    except KeyError:
        print("Unable to get keyNames.")

def listAllGroupNames(database):
        #Can also print current group names to help user.
        namesList = getKeyNames(database)
        #Successfully retrieved key names
        count = 1
        if len(namesList) != 0:
            print ("\nAvailable groups in the database:")
            for names in namesList:
                print ("{}. {}".format(count,names))
                count +=1

#Function that prints UI on request.
def printUI():
    print("\n---Welcome to the grading system! Please enter your option:---")
    count = 1
    for options in uiOptions:
        print("{}. {}".format(count,options))
        count +=1

#Empty dictionary first as we are allowing input record later on.
labGrades = {}

#Tuple for ui options so it's easier to print later on.
uiOptions = ("Input Record",
             "Query a student",
             "List grades in a group",
             "Get max in a group",
             "List all group names",
             "Remove a Record",
             "Exit")


#Main program loop
while True:
    #Print the UI for the user to select their options
    printUI()
    #Let user input options
    option = input("Option: ")
    #Do some error handling 
    if (not option.isdigit()):
        print("Invalid option. Input must be numbers only and non negative.")
        continue
    elif (0 >= int(option) or int(option) > len(uiOptions)): #More dynamic approach
        print("Invalid option. Select an option only in the range of 1. to {}.".format(len(uiOptions)))
        continue

    #Cast option to int
    option = int(option)

    #These are the options that are reliant on database not being empty.
    if option > 1 and option < 7:
        #If there are no entries
        if(len(labGrades) == 0):
            print("There are no entries in the database.")
            continue

    #Else its all fine and we can proceed to invoke our functions.
    if (option == 1): #Insert 
        #Print the current dictionary at each stage...
        groupName = str(input("Please input the group name: "))
        studentID = int(input("Please input the student id: "))
        studentScore = int(input("Please input the score: "))
        inputRecord(labGrades,groupName,studentID,studentScore)
    elif (option == 2): #Query
        #Else we can continue to do our query
        groupName = str(input("Please input the group name: "))
        studentID = int(input("Please input the student id: "))
        studentScore = query(labGrades, groupName, studentID)
        if(studentScore == -1): #Invalid result
            print("Unable to return student score in Group {} and ID {} as the key does not exist.".format(groupName,studentID))
        else:
            print("The score of the student in Group [{}] with ID [{}] is [{}]".format(groupName,studentID,studentScore))
    elif (option == 3): #List grades in a group
        #Can also print current group names to help user.
        listAllGroupNames(labGrades)
        #Else we can try..
        groupName = str(input("Please input the group name: "))
        resultantList = listGrades(labGrades,groupName)    
        print("Scores in group [{}]: ".format(groupName))
        #Print the resultant List
        print ("{:<15}{:<15}".format("Student ID", "Score"))
        for pair in resultantList:
            print ("{:<15}{:<15}".format(pair[0], pair[0]))

    elif (option == 4): #Max in a group
        #Can also print current group names to help user.
        listAllGroupNames(labGrades)
        #Else we can try..
        groupName = str(input("Please input the group name: "))
        maxGrades = maxGrade(labGrades,groupName)
        #Max is valid.
        if(maxGrades != -1):
            print ("The max grade of group [{}] is {}".format(groupName,maxGrades))
        pass
    elif (option == 5): #List all group names
        listAllGroupNames(labGrades)
    elif (option == 6): #Remove record...
        groupName = str(input("Please input the group name: "))
        studentID = int(input("Please input the student id: "))
        removeRecord(labGrades, groupName,studentID)
    elif (option == 7):
        #Quit
        print("Thank you for using this program. Bye!")
        break
    else:
        pass