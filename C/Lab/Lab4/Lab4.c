//
//  Lab4.c
//  SC1003LabTuts
//
//  Created by Isaac Chun on 23/10/22.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10
#define INIT_VALUE 999

void question1(void);
void question2(void);
void question3(void);

//Upon reversing we can tell if it can be read the same way or not
void reverseStr(char * str);

enum QUESTIONS
{
    QUESTION1 = 0,
    QUESTION2,
    QUESTION3,
    MAX_QUESTIONS
};


int main()
{
    enum QUESTIONS questions = QUESTION3;
    switch (questions)
    {
        case QUESTION1:
            question1();
            break;
        case QUESTION2:
            question2();
            break;
        case QUESTION3:
            question3();
            break;
        default:
            break;
    }
    return 0;
}

void question1(void)
{
    char *sweepSpace1(char * str);
    char *sweepSpace2(char * str);
    
    char str[80], str2[80], *p;
    printf("Enter the string: \n");
    fgets(str,80,stdin);
    if((p=strchr(str,'\n')))
        *p='\0';
    strcpy(str2, str);
    printf("sweepSpace1(): %s\n", sweepSpace1(str));
    printf("sweepSpace2(): %s\n", sweepSpace2(str2));
}

void question2(void)
{
    //Name ptr is the array of strings, size is the number of names stored in the array and target is the target string.
    //If found, fucntion return index location, or -1
    int findTarget(char* target, char namePtr[][80], int size);
    //Reads a number of names from the user.
    //name ptr is the array of strings to store the input names, size is a pointer parameter which passes the number of names to the caller.
    void readNames(char nameptr[][80], int *size);
    void printNames(char nameptr[][80], int size);
    
    char nameptr[SIZE][80], t[40], *p;
    int size = 0, result = INIT_VALUE;
    int choice;
    
    printf("Select one of the following options: \n");
    printf("1: readNames()\n");
    printf("2: findTarget()\n");
    printf("3: printNames()\n");
    printf("4: exit()\n");
    
    do
    {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                readNames(nameptr, &size);
                break;
            case 2:
                printf("Enter target name: \n");
                scanf("\n");
                fgets(t, 80, stdin);
                if((p=strchr(t,'\n')))
                    *p = '\0';
                result = findTarget(t, nameptr, size);
                printf("findTarget(): %d\n", result);
                break;
            case 3:
                printNames(nameptr, size);
                break;
        }
    } while(choice < 4);
    
}
void question3(void)
{
    int palindrome(char * str);
    
    char str[80], *p;
    int result = INIT_VALUE;
    
    printf("Enter a string: \n");
    fgets(str,80, stdin);
    if((p=strchr(str, '\n')))
        *p = '\0';
    result = palindrome(str);
    if (result ==1)
        printf("palindrome(): A palindrome\n");
    else if (result == 0)
        printf("palindrome(): Not a palindrome\n");
    else
        printf("An error\n");
    
}

/******************************************************************************/
/*!
\brief
Takes in a str and removes all whitespaces in the str using array notation
\param str string to remove whitespaces from
\exception None
*/
/******************************************************************************/
char * sweepSpace1(char * str)
{
    //Use strlen function to get length of str
    int len = (int)strlen(str);
    
    //Loop through all the characters, finds a whitespace and moves everything forward by 1
    int i, j = 0;
    for (i =0; i < len; ++i)
    {
        //If not is space str[i].
        if(!isspace(str[i]))
        {
            str[j++] = str[i];
        }
    }
    return str;
}
/******************************************************************************/
/*!
\brief
Takes in a str and removes all whitespaces in the str using pointer notation
\param str string to remove whitespaces from
\exception None
*/
/******************************************************************************/
char *sweepSpace2(char * str)
{
    //Str is the first point of address
    //Set two pointers that traverse the str
    //Let me try...
    
    //i am a boy
    //r -> i
    //w -> i
    //Traverse w till the next space.
    //r -> a
    //w -> i, so keep writing from w onwards based on r.
    char * r, * w;
    //Set them to be at the start
    r = w = str;
    
    //While r is not th termination characters
    while(*r != '\0')
    {
        //While it's on a space
        while(isspace(*r))
        {
            //We keep increasing all the way to the next not found space
            r++;
        }
        //Once it has reached a non space
        //We start writing where the read pointer left off as the write pointer is still at the start of array.
        *w++ = *r++;
    }
    //After that we set it back
    *w = '\0';

    return str;
}

//Name ptr is the array of strings, size is the number of names stored in the array and target is the target string.
//If found, fucntion return index location, or -1
int findTarget(char* target, char nameptr[][80], int size)
{
    //Loop through nameptr and try to find a matching element
    int i;
    for (i = 0; i < size; ++i)
    {
        //If there is a match
        if(strcmp(target, nameptr[i]) == 0)
            return i;
    }
    //Default return statement
    return -1;
}
//Reads a number of names from the user.
//name ptr is the array of strings to store the input names, size is a pointer parameter which passes the number of names to the caller.
void readNames(char nameptr[][80], int *size)
{
    //Get inputs from user
    printf("Enter size:\n");
    scanf("%d", size);
    printf("Enter %d names:\n", *size);
    //Get it into strings.
    //I'll just use pointer notation.
    char names[80];
    //Remove the \n char in the input buffer
    scanf("\n");
    fgets(names, 80, stdin);
    //Process the array and place it in the namePtr;
    char *r; //Make read pointers
    //Set read pointer location
    r = names;

    //Seperate by spaces
    //Current index to update.
    int mainIndex, subIndex;
    //Initialize all to 0
    mainIndex = subIndex = 0;
    //While not end of string, we seperate it
    while (*r != '\0')
    {
        subIndex = 0;
        //While our current pointer is not a space
        while (!isspace(*r))
        {
            //Add current character to our index storage
            *(*(nameptr+mainIndex)+subIndex) = *r;
            //Then increase r
            r++;
            //Increase sub index to store next
            subIndex++;
        }
        //We also set the ending brace
        *(*(nameptr+mainIndex)+subIndex) = '\0';
        //Else we have encountered a next space, so we add one to get next index
        r++;
        //Increment mainIndex also
        mainIndex++;
    }
}

void printNames(char nameptr[][80], int size)
{
    int i;
    for(i =0; i < size; i++)
    {
        printf("%s ", nameptr[i]);
    }
    printf("\n");
}
int palindrome(char *str)
{
    //Check 0 first.
    //Else we return as an error which is not 0 or 1
    if(strlen(str) == 0)
        return -1;

    //It is easier to do it with str and char as we can just reverse and check.
    //Copy the current str to a new str
    char cstr[80];
    //Carry out the copying operation
    strcpy(cstr, str);
    //We then reverse the copy.
    reverseStr(cstr);
    //printf("Reversed: %s\n", cstr);
    //(We then do a comparison.
    if(strcmp(cstr, str) == 0)
        return 1;
    //By default, we return that it is not a palindrome.
    return 0;
}

void reverseStr(char * str)
{
    //Make two pointers of start and end
    char *start, *end;
    //Use str len
    start = str;
    end = start + strlen(str) - 1;
    
    //While start != end
    while (start < end)
    {
        //Do some post fix operations and keep swapping
        //Swap value of start and end and postfix
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    } 
}