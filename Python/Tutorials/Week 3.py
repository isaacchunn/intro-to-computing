def discussion1():
    value = 6
    if value % 2 == 0:
        print("first", value)
    elif value % 3 == 0:
        print("second",value)

    while value <=9:
        value = value + 1
        if value == 8:
            continue
        else:
            pass
        print ("third", value)
    else:
        print ("fourth", value)

    print ("fifth", value)


def discussion2():
    count = 0
    while True:
        str = input("Enter a string(Enter #### to stop):")
        if str == "####":
            break

        for letter in str:
            if letter == 'a':
                count +=1
                break

    print(count, "strings with letter 'a'")

def discussion3():
    for x in range(1,21):
        if x % 5 == 0:
            if x % 3 == 0 :
                print("FizzBuzz")
            else:
                print("Buzz")
        elif x % 3 == 0:
            print("Fizz")
        else:
            print(x)


def discussion4():
    width = (int)(input("Please enter pattern width: "))
    #Top Half
    for rows in range (1, (width + 1)):
        for columns in range (0, rows):
            print ("*",end ="")
        print("\n") #New lines
    #Bottom Half
    for rows in range (width-1,0,-1):
        for columns in range (0,rows):
            print ("*",end ="")
        print("\n") #New lines


# X=1
# rows=int(input('Enter the odd number of rows: '))
# for line in range(1,(rows+1)//2):
#     print('*'*X)
#     X=X+2
# for line in range((rows+1)//2,rows+1):
#     print('*'*X)
#     X=X-2

discussion4()

