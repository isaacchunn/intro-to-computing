//
//  assignment.c
//  SC1003Assignment
//
//  Created by Isaac Chun on 22/10/22.
//

//NTU Hotel declared max rooms.
#define MAX 5
#define EMPTY 0
#define TAKEN 1
#define MAXNAMELENGTH 20

//Room struct
typedef struct
{
    //Room Identification Number
    int roomID;
    //Stores a marker that indicates whether the room is assigned or not.
    int status;
    // Name of customer who occupies the room
    char customerName[MAXNAMELENGTH];
} Room;

//Room ID must be unique.
//Each room structure will have a different number of roomID when it is created.
//You may assume that the name of a customer is not more than 20 characters long.
//In the program, it should display a menu to support the following functions.

/*
 NTU HOTEL ROOM RESERVATION PROGRAM:
 1: listOccupiedRooms()
 2: assignRoom()
 3: removeRoom()
 4: findCustomer()
 5: quit
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Function prototypes
//Assignment essentials
void listOccupiedRooms(Room room[], int size);
void assignRoom(Room room[], int  *size);
void removeRoom(Room room[], int * size);
void findCustomer(Room room[]);

//Helper functions
int compareStrings(char * str1, char * str2);
void convertLower(char * str);
void getInput(int * roomID);

int main()
{
    //Int storage.
    int choice = -1;
    //Declare an array of 5 structs.
    Room rooms[MAX];
    
    int i, size = 0;
    //Set all rooms status to be EMPTY at start without touching the rest.
    for (i = 0; i < MAX; ++i)
    {
        //I can do this because the room numbers are limited between 1 and MAX, so doing it in order makes sense
        rooms[i].roomID = i+1;
        //Set status to default empty
        rooms[i].status = EMPTY;
        //Initialize the first character to show it's an empty string.
        rooms[i].customerName[0] = '\0';
    }
    
    //Print the UI once at the top.
    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");

    do
    {
        //Take in user input
        printf("Enter your choice:\n");
        
        //NOT NEEDED -! Prevent char as an input.
        char input [MAXNAMELENGTH], *p;
        scanf("\n");
        fgets(input,MAXNAMELENGTH,stdin);
        if((p=strchr(input, '\n')))
            *p = '\0';
        //Convert char input to choice.
        choice = atoi(input);
        //Get rid of any \n lingering in the input buffer.
        //scanf("\n");
        //scanf("%d", &choice);
        //Handle inputs
        switch (choice)
        {
            case 1:
                listOccupiedRooms(rooms, size);
                break;
            case 2:
                assignRoom(rooms, &size);
                break;
            case 3:
                removeRoom(rooms, &size);
                break;
            case 4:
                findCustomer(rooms);
                break;
            default:
                break;
        }
    } while(choice != 5);
    return 0;
}

/******************************************************************************/
/*!
\brief
Lists all occupied rooms in the hotel.
\param rooms  array of room structs
\exception None
*/
/******************************************************************************/
void listOccupiedRooms(Room rooms[], int size)
{
    //Function call...
    printf("listOccupiedRooms():\n");
    
    //If hotel is empty, then we print it out.
    if(size == 0)
    {
        printf("The hotel is empty\n");
        //Return from the function.
        return;
    }
    //Else we can carry on to print who are staying in rooms.
    
    //We loop through the indices to find out the status of the rooms.
    int i;
    for (i = 0; i < MAX; ++i)
    {
        //If the current room isnt empty, then we print out the person's room ID and customer's name.
        if(rooms[i].status != EMPTY)
        {
            printf("roomID: %d\n", rooms[i].roomID);
            printf("customer name: %s\n", rooms[i].customerName);
        }
    }
}

/******************************************************************************/
/*!
\brief
Attempts to assign a room based off user inputs into the room struct array
\param rooms  array of room structs
\exception None
*/
/******************************************************************************/
void assignRoom(Room rooms[], int * size)
{
    //Function call...
    printf("assignRoom():\n");
    
    //Base check to check all rooms whether they are all taken.
    //>= to prevent any miscounting (but it shouldnt happen)
    if(*size >= MAX)
    {
        printf("The hotel is full\n");
        return;
    }
    
    int roomID;
    char customerName[MAXNAMELENGTH], *p;
    //Ask for user input on roomID.
    printf("Enter a roomID between 1 and %d:\n", MAX);
    //Store user input in roomID
    getInput(&roomID);
    
    //Else if it's in bounds then.
    //Do some error checking to see if theres already a customer in that inputID
    //While the requested room status is not empty, we continue asking the user for input.
    while(rooms[roomID - 1].status != EMPTY)
    {
        printf("Occupied! Enter another roomID\n");
        printf("Enter a roomID between 1 and %d:\n", MAX);
        //Store user input in roomID
        getInput(&roomID);
    }
    
    //Get input into customerName.
    printf("Enter customer name:\n");
    //Get rid of \n in input buffer.
    scanf("\n");
    fgets(customerName, MAXNAMELENGTH, stdin);
    if ((p=strchr(customerName,'\n')))
        *p = '\0';
    
    //We then assign since we have confirmed that that room is definitely empty.
    rooms[roomID - 1].status = TAKEN;
    //Already initialized, but I'll do it here regardless.
    rooms[roomID - 1].roomID = roomID;
    //Do str copy
    strcpy(rooms[roomID -1].customerName, customerName);
    //Then we plus the size of current hotel by 1
    *size+= 1;
    //Success message
    printf("The room has been assigned successfully\n");
    //printf("roomID = %d, customerName = %s\n", roomID, customerName);
}

/******************************************************************************/
/*!
\brief
Attempts to remove a room from the rooms struct array given a user input.
\param rooms  array of room structs
\exception None
*/
/******************************************************************************/
void removeRoom(Room rooms[], int * size)
{
    //Function call.
    printf("removeRoom():\n");
    
    //Base check to see if there the rooms are empty and checks if it's empty.
    //Just in case size goes below 0, which shouldn't happen.
    if (*size <= 0)
    {
        //All rooms in the hotel are empty
        printf("All the rooms are empty\n");
        return;
    }

    int roomID;
    //Ask for user input on roomID.
    printf("Enter a roomID between 1 and %d:\n", MAX);
    //Store user input in roomID
    getInput(&roomID);
    
    //We check if the target room id is taken. If so, we can remove it, else we force the user to choose
    //something else.
    while(rooms[roomID-1].status != TAKEN)
    {
        //Selected room is empty
        printf("Empty! Enter another roomID for removal\n");
        //Attempt to get input again.
        printf("Enter a roomID between 1 and %d:\n", MAX);
        //Store user input in roomID
        getInput(&roomID);
    }
    
    //Else we can safely remove.
    rooms[roomID -1].status = EMPTY;
    //Might need to touch charname later.
    rooms[roomID -1].customerName[0] = '\0';
    //Then we minus the size by 1
    *size-=1;
    //Removal was successful.
    printf("Removal is successful\n");
}

/******************************************************************************/
/*!
\brief
Finds a customer via user input's name in the rooms struct array.
\param rooms  array of room structs
\exception None
*/
/******************************************************************************/
void findCustomer(Room rooms[])
{
    //Function call...
    printf("findCustomer():\n");
    
    //Variable declarations
    char customerName[MAXNAMELENGTH], *p;
    int i;
    //Get input into customerName.
    printf("Enter customer name:\n");
    //Get rid of \n in input buffer.
    scanf("\n");
    fgets(customerName, MAXNAMELENGTH, stdin);
    if ((p=strchr(customerName,'\n')))
        *p = '\0';
    
    //Loop through all the roomIDs that are taken and attempt to match.
    for (i = 0; i < MAX; ++i)
    {
        //Check if they are taken.
        if(rooms[i].status == TAKEN)
        {
            //Then we do some comparisons to find
            int result = compareStrings(rooms[i].customerName, customerName);
            if(result == 0)
            {
                //if it is found
                //Display room information of the corresponding customer.
                printf("The target customer name is found\n");
                //We have found matching customers name that is not case sensitive.
                printf("roomID: %d\n", rooms[i].roomID);
                printf("customer name: %s\n", rooms[i].customerName);
                return;
            }
        }
    }
    //If does not exist, then should print, the target customer name is not found.
    printf("The target customer name is not found\n");
}

/******************************************************************************/
/*!
\brief
Helper function to get input of roomID and stores into Room ID;
\param roomID address of roomID to store the variable
\exception None
*/
/******************************************************************************/
void getInput(int * roomID)
{
    //Do some additional error checking for IDs.
    //atoi returns 0 if a valid conversion cannot be performed, which is what we want.
    //Set a reasonable 30 char limit, for extreme cases.
    char input[30], *p;
    //Get rid of any \n in the input buffer
    scanf("\n");
    fgets(input, MAXNAMELENGTH, stdin);
    if ((p=strchr(input,'\n')))
        *p = '\0';
    //Convert the string input to roomID input.
    *roomID = atoi(input);
    //Ensure that bounds are met.
    while (*roomID < 1 || *roomID > MAX)
    {
        printf("Enter a roomID between 1 and %d:\n",MAX);
        //Store user input in roomID
        //scanf("%d", roomID);
        scanf("\n");
        fgets(input, MAXNAMELENGTH, stdin);
        if ((p=strchr(input,'\n')))
            *p = '\0';
        //Convert the string input to roomID input.
        *roomID = atoi(input);
    }
}

/******************************************************************************/
/*!
\brief
Converts both strings to lower case and compares it to check via  non case sensitive comparison.
\param str1 first string to compare
\param str2 second string to compare
\exception None
\return comparison result of comparing both string using strcmp.
*/
/******************************************************************************/
int compareStrings(char * str1, char * str2)
{
    //Convert str1 and str2 to lowercase after making a copy.
    //Initialize some char arrays
    char _str1[MAXNAMELENGTH];
    char _str2[MAXNAMELENGTH];
    //Copy both strings into the temporary char arrays
    strcpy(_str1, str1);
    strcpy(_str2, str2);
    //Convert both to lower case
    convertLower(_str1);
    convertLower(_str2);
    //Check strcmp
    return strcmp(_str1, _str2);
}

/******************************************************************************/
/*!
\brief
Takes in a string and converts all characters to lower case.
\param str string to convert to lowercase
\exception None
*/
/******************************************************************************/
void convertLower(char * str)
{
    while(*str != '\0')
    {
        *str = tolower(*str);
        str++;
    }
}
