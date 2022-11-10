//
//  findLongShortStr.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//

#include <stdio.h>
#include <string.h>
#define N 20
void findLongShortStr(char str[N][81], char *longStr, char *shortStr, int size);
int main()
{
    char str[N][81], longStr[81], shortStr[81], *p;
    int i, size;
    char dummy;
    
    printf("Enter number (size) of strings: \n");
    scanf("%d", &size);
    scanf("%c", &dummy);
    for(i=0; i < size; i++)
    {
        printf("Enter string %d: \n", i+1);
        fgets(str[i], 81, stdin);
        if((p=strchr(str[i], '\n')))
            *p = '\0';
    }
    findLongShortStr(str, longStr, shortStr, size);
    printf("longest string: %s %d\n", longStr, strlen(longStr));
    printf("shortest string: %s %d\n", shortStr, strlen(shortStr));
    return 0;
}

/******************************************************************************/
/*!
\brief
Finds the longest and shortest str of a given array of strings
\param str 2d char string array
\param longStr  longStr
\param shortStr  shortStr
\param size  size of strings
\exception None
\return None
*/
/******************************************************************************/
void findLongShortStr(char str[][81], char *longStr, char* shortStr, int size)
{
     if (size == 0)
         return;
     
     int i;
     int shortLen, longLen;
     //Default inputs
     shortLen = longLen = (int)strlen(str[0]);
     strcpy(longStr, str[0]);
     strcpy(shortStr, str[0]);
     
     for (i = 0; i < size ; ++i)
     {
         int currentLen = (int)strlen(str[i]);
         //printf("%d", currentLen);
         //Comparison
         //Priority goes to max
         if(currentLen > longLen)
         {
             strcpy(longStr, str[i]);
             //Update long len
             longLen = currentLen;
         }
         else if(currentLen < shortLen)
         {
             strcpy(shortStr, str[i]);
             //Update short len
             shortLen = currentLen;
         }
     }
}
