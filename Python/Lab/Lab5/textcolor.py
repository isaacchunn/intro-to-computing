#Gets a color returns based on string input
def get_color(color):
    no_of_try = 1
    maxTries = 3
    while no_of_try <= maxTries:         
        color_str = input("Enter the value of the " + color + \
            " color for the message(0 to 255): ")

        #Try to cast it to int, else if uncastable the input is not an int at all.
        try :
            color_str = int(color_str)
        except:
            #If the input is not a digit
            print("Invalid input. Enter numbers only. You have {} tries left.".format(maxTries - no_of_try))
            no_of_try += 1
            continue

        if (0 <= int(color_str) and int(color_str) <=255):
            #The input is valid so we can return
            return int(color_str)
        else:
            #The input is out of range
            print("Invalid input. Your input is out of range (0-255). You have {} tries left.".format(maxTries -no_of_try))
            no_of_try +=1
    else:
        print("You have exceeded the try limit of {}. Your input will be deemed as 0.".format(maxTries))
        return 0