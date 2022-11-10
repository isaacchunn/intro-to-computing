//
//  compressStr.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#define M 80
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void compressStr(char *str);
int main()
{
     char str[40];

     printf("Enter a sequence of characters: \n");
     scanf("%s", str);
     printf("compressStr(): ");
     compressStr(str);
     return 0;
}
void compressStr(char *str)
{
    /* Write your code here */
    //Use pointers to read
    char * p = str;
    //Set char to first element
    char c = *str;
    //Initial count 0 to account for frst
    int count = 1;
    //While not end of str
    while (*p != '\0')
    {
        //if the next element is also the same character then plus count
        if (*(p + 1) == c)
        {
            //If its the same character, we have to increment count.
            count ++;
        }
        else
        {
            //Then we print based off current.
            //Else, if count > 1, then we print the element and reset
            if (count > 1)
                printf("[%d%c]", count, c);
            else
                putchar(c);
            //Set to new char
            c = *(p + 1);
            //Reset count
            count = 1;
        }
        //Traverse through the p
        p++;
    }
}
