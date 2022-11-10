//
//  Tutorial4Q4.c
//  SC1003LabTuts
//
//  Created by Isaac Chun on 23/10/22.
//

#include <stdio.h>
#include <string.h>
#define INIT_VALUE 999

int main()
{   
    //Function prototype
    int stringcmp(char *s1, char*s2);
    char source[80], target[80], *p;
    int result = INIT_VALUE;
    printf("Enter a source string: \n");
    fgets(source, 80, stdin);
    if ((p=strchr(source, '\n')))
        *p = '\0';
    printf("Enter a target string: \n");
    fgets(target, 80, stdin);
    if ((p=strchr(target, '\n')))
        *p = '\0';
    
    result = stringcmp(source, target);
    if(result ==1)
        printf("stringcmp(): greater than");
    else if (result == 0)
        printf("stringcmp(): equal");
    else if(result == -1)
        printf("stringcmp(): less than");
    else
        printf("stringcmp(): error");
    return 0;
}
/******************************************************************************/
/*!
\brief
Compares the contents of s1 and s2 to check if it's equal.
\param s1 string1
\param s2 string2
\exception None
\return 1 (s1 > s2), 0 (s1 == s2), -1 (s1 < s2)
*/
/******************************************************************************/
int stringcmp(char *s1, char*s2)
{
    //If any of the letters are greater than one another, it is automatically greater.
    //If any of the letters are smaller, it is also automatically smaller.
    //If the letters are equal, then we continue traversing.
    //Use pointers and create pointer variables
    char * s1P, * s2P;
    s1P = s1;
    s2P = s2;
    //Do a while loop to check for termination and end case character

    //while s1p is not the end character
    while (*s1P != '\0')
    {
        //Termination conditions
        if(*s2P == '\0')
            return 1; //Length of s1P is longer and s2p reach termination first.
        //We can keep incrementing s1P and s2P;
        if(*s1P > *s2P) //Current character of s1P is larger so s1P is larger
            return 1;
        if(*s1P < *s2P) //Current character of s1P is smaller so s1P is smaller.
            return -1;  

        s1P++;
        s2P++;
    }

    //In the event that nothing is returned, that means that s2P still has letters, \
    // hence we do a final check before we truly return 0
    //This means that s2P still has letters and that s1P was a shorter length than s2P
    if(*s2P != '\0') 
    {
      return -1;
    }
    //Else the strings are equal! yay.
    return 0;
}