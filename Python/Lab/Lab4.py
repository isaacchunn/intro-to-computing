from sense_hat import SenseHat
from time import sleep
import random

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

    def returnTuple(self):
        return (self.r,self.g,self.b)
        
    def generateRandom(self, redLimit = (0,255), greenLimit = (0,255), blueLimit = (0,255)):
        self.r = random.randint(redLimit[0],redLimit[1])
        self.g = random.randint(greenLimit[0],greenLimit[1])
        self.b = random.randint(blueLimit[0],blueLimit[1])
  
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
colorList["empty"] = (Color(0,0,0,"empty"))

#Declare sense
sense = SenseHat()

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

def generateRandomColor(redLimit = (0,255), greenLimit = (0,255), blueLimit = (0,255)):
   color = Color()
   color.generateRandom(redLimit,greenLimit,blueLimit)
   return color
    
# def generateRandomColor():
#     return random.choice(list(colorList.values()))    

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


#Code for lab3
def Lab3():
    #sense = SenseHat()

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
 
    sense.show_message("I got depression", text_colour = textColor.returnTuple(), \
                                  back_colour = backgroundColor.returnTuple(),
                                scroll_speed = scrollSpeed)

#Function that wraps between the max and min index defined by the user
def Wrap(value, minValue, maxValue):
    if value < minValue:
        return maxValue
    elif (value > maxValue):
        return minValue  
    return value

#Wrapper function
def setImageColor(imageList, imagepixels, color):
    for indexes in imageList:
        imagepixels[indexes] = color    
        sense.set_pixels(imagepixels)

#Code for lab4
def Lab4():
    #Setup up tuples
    r = colorList["red"].returnTuple()
    y = colorList["yellow"].returnTuple()
    o = colorList["orange"].returnTuple()
    lg = colorList["lightgreen"].returnTuple()
    g = colorList["green"].returnTuple()
    lb = colorList["lightblue"].returnTuple()
    b = colorList["blue"].returnTuple()
    p = colorList["purple"].returnTuple()
    pink = colorList["pink"].returnTuple()
    pink2 = colorList["pink2"].returnTuple()
    o = colorList["empty"].returnTuple()
    
    MIN_INDEX = 0
    MAX_INDEX = 7
    
    run5a = False
    run5c = True

    #Board is 8X8 with origin top left 
    #0  1   2   3   4   5   6   7
    #1
    #2
    #3
    #4
    #5
    #6
    #7

    if(run5a):
        sense.clear()
        #Four Corners Code
        #Top Left
        sense.set_pixel(MIN_INDEX,MIN_INDEX, r)
        #Top Right
        sense.set_pixel(MIN_INDEX,MAX_INDEX, y)
        #Bottom Left
        sense.set_pixel(MAX_INDEX,MIN_INDEX, g)
        #Bottom Right
        sense.set_pixel(MAX_INDEX,MAX_INDEX, pink)
        while (True):
            sense.clear()
            for positions in range (4):
                #Generate positions
                xIndex = random.randint(MIN_INDEX,MAX_INDEX)
                yIndex = random.randint(MIN_INDEX,MAX_INDEX)
                randomColor = generateRandomColor().returnTuple()
                sense.set_pixel(xIndex,yIndex,generateRandomColor().returnTuple())
            sleep(1)
    

    if(run5c):
        image_pixels =[b, b, b, b, b, b, b, b,
                    b, b, b, y, b, b, b, b,
                    b, b, y, y, y, b, b, b,
                    b, y, b, y, b, y, b, b,
                    b, b, b, y, b, b, b, b,
                    b, b, b, y, b, b, b, b,
                    b, b, b, y, b, b, b, b, 
                    b, b, b, b, b, b, b, g]  
                    
        # image_pixels =[
        #                 o, o, o, o, o, o, o, o,
        #                 o, r, r, o, r, r, o, o,
        #                 r, r, r, r, r, r, r, o,
        #                 r, r, r, r, r, r, r, o,
        #                 o, r, r, r, r, r, o, o,
        #                 o, o, r, r, r, o, o, o,
        #                 o, o, o, r, o, o, o, o,
        #                 o, o, o, o, o, o, o, g,
        #                ]                    
                    
        sense.set_pixels(image_pixels)
        #Alternate between 2 colors 
        #Loop through all the elements and change (want to change between )

        #Test against a backgroundColor
        backgroundColor = b
        markerColor = g #Green marker for oreitnation of object
        #Colors to swap to in order red -> yellow
        colorSwap = (g,r)
        #Current color index
        currentColorIndex = 0
        #Current image colors can be more than one if iamge has multiple colors
        #Test against image backgroundColor for accurate images that are set, so all the pixels that have color that are not background and markercolor
        imageList = [i for i in range(0, len(image_pixels)) if (image_pixels[i] != backgroundColor and image_pixels[i] != markerColor)]
        #Delay between swaps
        delay = 1
        #Loop to swap between both

        #Random parts
        #Allow random orientations
        allowRandomOrientations = True
        #Allowed rotations
        rotations = [0,90,180,270]
        #Random Colors (Allowed?)
        allowRandomColors = False
        #Random Color Initilization
        randomColor = 0

        #To not repeat directions if neededd
        #Prev Rotation Index
        prevRotation = -1
        currentRotation = 0
        sense.set_rotation(currentRotation)
    
        
        gameScore = 0
        lost = False

        while(True):  
            if lost:
                setImageColor(imageList, image_pixels,colorSwap[1])
                sense.show_message("Your score is {}".format(gameScore), text_colour = r, back_colour = o, scroll_speed = 0.05)
                break
            
            #print("Acceleration ({},{},{})".format(accelX,accelY,accelZ))
            #Set color to be y
            setImageColor(imageList,image_pixels,y)
            
            #Change all the pixels with the colors
            if(allowRandomColors):
                randomColor = generateRandomColor().returnTuple()

            for indexes in imageList:
                if (allowRandomColors):
                    image_pixels[indexes] = randomColor
                else:
                    image_pixels[indexes] = colorSwap[currentColorIndex]
            
            #Set pixels.
            #sense.set_pixels(image_pixels)
            #Rotations
            if(allowRandomOrientations):
                while True:
                    #Current rotation = random from rotations
                    currentRotation = random.choice(rotations)
                    if(currentRotation != prevRotation):
                        #print("Current {} , Previous {}".format(currentRotation,prevRotation))
                        prevRotation = currentRotation
                        break
            
            sense.set_rotation(currentRotation)
            
            #currentColorIndex = Wrap(currentColorIndex+1, 0, len(colorSwap) - 1) #Wraps around the color indexes
            sleep(delay) #Delay between swaps
        
            acceleration = sense.get_accelerometer_raw()
            accelX = acceleration['x']
            accelY = acceleration['y']
            accelZ = acceleration['z']
            accelX = round(accelX)
            accelY = round(accelY)
            #rotation 0 == y1
            #rotation 90 == x-1
            #rotation 180 == y-1
            #rotation 270 == x1
            if (currentRotation == 0):
                if accelY == 1:
                    gameScore+=1
                    setImageColor(imageList,image_pixels,g)
                else:
                    #Set color to red and break
                    lost = True
                    continue
            elif (currentRotation == 90):
                if accelX == -1:
                    gameScore+=1
                    setImageColor(imageList,image_pixels,g)
                else:
                    #Set color to red and break
                    lost = True
                    continue
            elif (currentRotation == 180):
                if accelY == -1:
                    gameScore+=1
                    setImageColor(imageList,image_pixels,g)
                else:
                    #Set color to red and break
                    lost = True
                    continue
            elif (currentRotation == 270):
                if accelX == 1:
                    gameScore+=1
                    setImageColor(imageList,image_pixels,g)
                else:
                    #Set color to red and break
                    lost = True
                    continue
            

            #Handle the rotations and inputs
            if(not lost):
                print("Score:", gameScore)
            #Play the game
            delay = delay * 0.98
            sleep(0.3) #Delay between swaps
    

#Main Loop 
programToRun = "LAB4"
#Don't know how to switch so quick fix first, enum not supported on rasp emulator
if (programToRun == "RAINBOW"):
    while(True):
        for keys, color in colorList.items():
            sleep(0.1)
            #sense.clear(color.r,color.g,color.b)
elif (programToRun == "LAB3"):
    Lab3()
elif (programToRun == "LAB4"):
    Lab4()
else:
    ##Can do smth
    pass