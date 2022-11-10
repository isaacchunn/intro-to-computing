#from sense_hat import SenseHat
from time import sleep

class Color:
    def __init__(self, red =0, green =0, blue=0, name ="Color"):
        self.name = name
        self.r = red
        self.g = green
        self.b  = blue
 
    def clampValue(value, smallest = 0, largest = 255):
        return max(smallest, min(value,largest))
    
    def clampColor(self, smallest, largest):
        self.r = self.clampValue(self.r,smallest,largest)
        self.g = self.clampValue(self.g,smallest,largest)
        self.b = self.clampValue(self.b,smallest,largest)
  
#Initialized dictionary
colorList = {}
colorList["red"] = (Color(255,0,0,"red"))
colorList["orange"] = (Color(255,127,0,"orange"))
colorList["yellow"] = (Color(255,255,0,"yellow"))
colorList["lightgreen"] = (Color(127,255,0,"lightgreen"))
colorList["green"] = (Color(0,255,0,"green"))
colorList["lightblue"] = (Color(0,255,255,"lightblue"))
colorList["blue"] = (Color(0,0,255,"blue"))
colorList["purple"] = (Color(127,0,255,"purple"))
colorList["pink"] = (Color(255,0,255,"pink"))
colorList["pink2"]= (Color(255,0,127,"pink2"))

#UI Functions
def printColorList():
    #Loop through the dictionary
    print("List of pre-allocated colors are:")
    counter = 1
    for keys, values in colorList.items():
        print("{}. {} ({},{},{})".format(counter,keys, values.r, values.g, values.b))
        counter +=1

#Color Functions
def FindColor(colorName = "Red"):
    try:
        return colorList[colorName.lower()]
    except KeyError: #catch KeyError, else return a color
        return Color(-255,-255,-255, "None")

        
#sense = SenseHat()

#Main Functions
def handleColorInput(tries , inputDetails):
    #Handle the respective inputs
    currentColor = 0
    currentTries = tries
    while (True):
        if(tries >= 3):
            return Color(255,255,255,"None"), tries

        #Print Color list for user to select
        printColorList()
        #Strip Inputs
        textColorInput = input(inputDetails)
        #Check if it's a alpha statement
        tryColor = FindColor(textColorInput)
        #Found a color related 
        if (tryColor.name != "None"):
            currentColor = tryColor
            print("You've selected {} color with rgb ({},{},{})".format(currentColor.name,currentColor.r,currentColor.g,currentColor.b))
            return (currentColor, currentTries) #Return a tuple of textColor and tries
            
        
        #We try to get the value as integers as we are acceptign two inputs
        textColorList = textColorInput.strip().replace("'","").split(",")
        
        #Set invalid flag to False
        invalid = False

        #If the user did not put 3 inputs seperated by comma
        if (len(textColorList) != 3):
            tries +=1
            print("Invalid - input was not in not in form colorR,colorG,colorB ({})".format(tries)) #Input was invalid
            invalid = True
            continue

        #If there are three inputs
        for value in textColorList:
            if not value.isdigit(): #Check if its not digits
                invalid = True
                tries +=1
                print("Invalid - use number only ({})".format(tries)) #Input was invalid
                break
            elif not int(value) in range (256): #And the range is correct.
                invalid = True
                tries +=1
                print("Invalid - value has to be between 0 and 255 ({})".format(tries)) #Input was invalid
                break
            
        if not invalid: #If not invalid
            #Assign color values
            currentColor = Color(int(textColorList[0]), int(textColorList[1]), int(textColorList[2]))
            print("You've selected color ({},{},{})".format(currentColor.r,currentColor.g,currentColor.b))
            return (currentColor, currentTries) #Return a tuple of textColor and tries

def codingExercise2B():
    tries = 0   

    textColor = 0
    backgroundColor = 0
    #Tuple of textColor for background and tries
    textColor , tries = handleColorInput(tries,"Enter textcolor in form e.g 255,255,255 or name (blue): ")
    if tries < 3: #Quick fix for now to test if tuple is working
       backgroundColor , tries = handleColorInput(tries, "Enter background textcolor in form e.g 255,255,255 or name (blue): ")
    else: #Exit condition
        print("You have have exceed the number of trials allowed. Bye!")
        return #Return for now and not do anything, print some error message here or allow relooping
 
    scrollSpeed = 0
    while (True):    
        #Handle scroll speed input
        scrollSpeed = (input("Enter the value of the display speed (fast, 0.05 to 1):"))

        #Check if the user input a sentence
        if scrollSpeed.isalpha():
            if(scrollSpeed.lower() == "fast"): #Account for some caps
                scrollSpeed = 0.05
                break    
        else:
            if (scrollSpeed >= 0.05 and scrollSpeed <= 1.00):
                break
            else:
                print("Invalid - value has to be between 0.05 and 1")
                continue

    
    #sense.show_message("I got depression", text_colour = (textColor.r,textColor.g,textColor.b), \
     #                             back_colour = (backgroundColor.r, backgroundColor.g, backgroundColor.b),
      #                            scroll_speed = scrollSpeed)


codingExercise2B()
# while(True):
#     for keys, color in colorList.items():
#         sleep(0.1)
#         sense.clear(color.r,color.g,color.b)


