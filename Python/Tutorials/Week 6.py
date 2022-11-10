#Tutorial 6
#Brief: 1A2B (Bulls and Cows) Game Design/Development

#2468, user guesses 1234, 2B (2,4 hits the target but positions are wrong)
import random

#Generates a list of answers, depending on inputs, default 4.
def generateAnswer(numbers = 4):
    ans = []
    for x in range(numbers):
        ans.append(random.randint(0,9))
    return ans

#Checks the answer and returns the amount of a and b, expects a list and a string
def checkAnswer (answer, guessedAnswer):
    #Initialize a and b to zero.
    a = 0
    b = 0

    #Make a duplicate list of answerList to manipulate
    ansList = list(answer)
    #List of ignored index
    ignoreIndex = []
    #Loop through the guessedAnswer
    #for guess in guessedAnswer:
    for x in range(0, len(guessedAnswer)):
        #Convert guess to int for checking.
        guessInt = int(guessedAnswer[x])
        #Check if this guess is inside the answers list
        if (guessInt in answer):
            #Just check by indexes
            if (guessInt == answer[x]):              
                #They are the same index and same.
                a+=1
                #Append this index to be ignored later
                ignoreIndex.append(x)
                #Remove this element in the ansList
                ansList.remove(guessInt)

    #Then we check again for the other cows as we have found the bulls.
    for x in range (0, len(guessedAnswer)):
        #Check if index should be ignore
        if ignoreIndex.count(x) > 0:
            #Then this index should be ignored.
            continue

        guessInt = int(guessedAnswer[x])
        #Check if the guessed ans 
        if ansList.count(guessInt) > 0:
            #Then there contains an element at wrong index
            b+=1
            #Remove this index to not repeat.
            ansList.remove(guessInt)
        
    #Return a tuple.
    return a,b

#Game function
def game():
    print ("Welcome to the 1A2B (Bulls & Cows) Game!")
    tries = 0
    #Handle playerInput difficulty
    while True:
        playerDifficulty = input("Choose how many digits you want to play (4 - 10): ")
        #Try to cast it to int, else if uncastable the input is not an int at all.
        try :
            playerDifficulty = int(playerDifficulty)
        except:
            #If the input is not a digit
            print("Invalid input. Enter numbers only.")
            continue
        if (4 <= playerDifficulty and playerDifficulty <= 10):
                break
        else:
            print("Invalid input. Only numbers between 4 and 10 are allowed.")

    #Print the difficutly to let player know what difficult they are playing.
    print("You have chosen to play the game with {} digits!".format(playerDifficulty))
    
    #We then generate the answer with the input difficulty.
    gameAnswer = generateAnswer(playerDifficulty)
    gameAnswerStr = ""
    #String inputs
    for x in gameAnswer:
        gameAnswerStr+=str(x)
    print("Answer:" ,gameAnswerStr)

    #Main Game Loop
    while True:
        playerInput = 0
        #Loop to check for correct input.
        while True:
            playerInput = input("Please input {} digits: ".format(playerDifficulty))
            #Check against the playerinput 
            #If len does ot meet the difficultyd
            if(len(playerInput) != playerDifficulty):
                print("Invalid input. You have not keyed in the correct number of digits.")
            elif (not playerInput.isdigit()):
                    print("Invalid input. Only digits input are accepted.")
            else: #Correct input
                break

        results = checkAnswer(gameAnswer,playerInput)
        #Results[0] == a
        #Results[1] == b

        #Increment tries.
        tries +=1
        #Then check if they won the game
        if (results[0] == playerDifficulty):
            print("Congrats! You won the game in {} tries! The correct answer was {}".format(tries,gameAnswerStr))
            break
        else:
            #Print current states
             print ("[{}] {} A (Bulls) {} B (Cows)".format(tries,results[0],results[1]))

#Game
game()