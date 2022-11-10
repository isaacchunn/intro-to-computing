from sense_hat import SenseHat
from time import sleep
import random

#Constants
MIN_WIDTH = 0
MAX_WIDTH = 7

#Sensitivity
leftXBounds = (1,179)
rightXBounds= (359, 180)
topYBounds = (1,179)
bottomYBounds = (359,180)

#Marble Class..
class Marble():
    def __init__(self,color = (255,0,0), x= 2,y = 2) -> None:
        self.x = x
        self.y = y
        self.color = color

    #Increments according to xand y if needed
    def moveMarble(self, xIncrement, yIncrement):
        self.x += xIncrement
        self.y += yIncrement
    
    def setPosition(self,x,y):
        self.x = x
        self.y = y
        
def updateMarble(board,marble):
    board[marble.y][marble.x] = marble.color

def updateBoard(board,marble):
    updateMarble(board,marble)
    sense.set_pixels(sum(board,[]))

#Update board turning sensitivities
def updateSensitivities(sensitivity, minRange = 1 , maxRange = 179):
    global leftXBounds
    global rightXBounds
    global topYBounds
    global bottomYBounds
    senseConstant = abs(sensitivity - minRange) * maxRange
    #Configure sensitivities
    leftXBounds = (1 + senseConstant, 179 - senseConstant)
    rightXBounds = (359 - senseConstant, 180 + senseConstant)
    topYBounds = (1 + senseConstant, 179 - senseConstant)
    bottomYBounds = (359 - senseConstant, 180 + senseConstant)
    
#Update colors in board
def updateAllColorsInBoard(board, checkedColor, resultColor):
    for x in range (0, len(board)):
        for y in range (0, len(board)):
            if board[y][x] == checkedColor:
                board[y][x] = resultColor

#Checks against the wall
def check_wall(board, x,y,new_x,new_y, wallColor):
    #Both new postioons are not wallColor
    if board[new_y][new_x] != wallColor:
        return new_x, new_y
    elif board[new_y][x] != wallColor: 
        return x, new_y
    elif board[y][new_x]!= wallColor:
        return new_x , y
    else:
        return x,y
    
# This function checks the pitch value and the x coordinate  
# to determine whether to move the marble in the x-direction.
# Similarly, it checks the roll value and y coordinate to
# determine whether to move the marble in the y-direction.
def move_marble(board, marble, pitch, roll, wallColor, backgroundColor):
    currentX = marble.x
    currentY = marble.y
    if leftXBounds[0] < pitch < leftXBounds[1] and currentX - 1 >= MIN_WIDTH:
        currentX -= 1   #Move Left
    elif rightXBounds[0] > pitch > rightXBounds[1] and currentX + 1 <= MAX_WIDTH :
        currentX += 1  #Move right

    if topYBounds[0] < roll < topYBounds[1] and currentY + 1 <= MAX_WIDTH:
        currentY += 1  #Move up
    elif bottomYBounds[0] > roll > bottomYBounds[1] and currentY - 1 >= MIN_WIDTH:
        currentY -= 1   #Move down

    #Set some colors
    board[marble.y][marble.x] = backgroundColor
    
    currentX, currentY = check_wall(board,marble.x,marble.y ,currentX,currentY, wallColor)
    marble.setPosition(currentX,currentY)

#Function that randomly generates the target that doesnt coincide with the wall.
def generateTarget(board, marble, wallColor):
    #Test against image wallColor for accurate images that are set, so all the pixels that have color that are not background and markercolor
    nonWallList = []
    for x in range (0, len(board)):
        for y in range (0, len(board)):
            if(board[y][x] != wallColor and marble.x != x and marble.y != y):
                nonWallList.append((x,y))
        
    resultX,resultY = random.choice(nonWallList)
    return resultX,resultY
 
#Initialize sense hat
sense = SenseHat()
r = (255,0,0)
o = (255,127,0)
y = (255,255,0)
lg = (127,255,0)
g = (0,255,0)
lb = (0,255,255)
b = (0,0,255)
p = (127,0,255)
pink = (255,0,255)
pink2 = (255,0,127)
o = (0,0,0)
w = (255,255,255)

#Initialized dictionary
colorList = {r,o,y,lg,g,lb,b,p,pink,pink2,w}

board = [[r,r,r,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [b,b,b,b,b,r,b,r],
         [b,r,r,b,r,r,b,r],
         [b,b,b,b,b,b,b,b],
         [b,r,b,r,r,b,b,b],
         [b,b,b,r,b,b,b,r],
         [r,r,b,b,b,r,r,r]]
         
backgroundColor = b
wallColor = r
targetColor = g

#Initialize a marble of white oclor and of positions of X and Y 2
marble = Marble(w,2,2)
updateMarble(board,marble)

#Generate a target...
targetPosition = generateTarget(board, marble, wallColor)
board[targetPosition[1]][targetPosition[0]] = targetColor

#Update backgroundColors
updateAllColorsInBoard(board, b, backgroundColor)

board_1D = sum(board,[])
#print (board_1D)
sense.set_pixels(board_1D)

#Whether we allow infinite game play or not
infiniteGamePlay = True

#Marble and loop speed
loopSpeed = 0.05

#Update sensitivities
updateSensitivities(0.95)
print(leftXBounds,rightXBounds,topYBounds,bottomYBounds)
    
#--------------------------
#Main Loop
while True:
    pitch = sense.get_orientation()['pitch']
    roll = sense.get_orientation()['roll']
    #print ("Pitch {}, Roll {}".format(round(pitch,0),round(roll,0)))
    #Updates marble position
    move_marble(board,marble,pitch,roll,wallColor,backgroundColor)
    #Then update the board based off marble
    updateBoard(board,marble)

    #Collision checking with target
    if(marble.x == targetPosition[0] and marble.y == targetPosition[1]):
        generate = True
        #Marble spawns
        if(infiniteGamePlay):
            if(generate):
                targetPosition = generateTarget(board,marble,wallColor)
                board[targetPosition[1]][targetPosition[0]] = targetColor
                generate = False
        else:
            sense.show_message("I got it...", text_colour = r)
            break
    
    sleep (loopSpeed)
    
#while(True):
    #for color in colorList:
        #sleep(0.1)
        #sense.clear(color[0],color[1],color[2])
#------------------------------------------