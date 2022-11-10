//
//  octStrTodec.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
int octStrTodec(char *str);
int main()
{
     char str[20],*sp;
     int num;

     printf("Enter an octal number: \n");
     scanf("%s",str);
     num=octStrTodec(str);
     printf("octStrTodec(): %d\n",num);
     return 0;
}
int octStrTodec(char *str)
{
   /* Write your code here */
    int currentDigit = 0;
    //So I dont accidentaly touch the real array
    char * p = str;
    //Using int properties //Gets the first digit from the left
    currentDigit = *p - 48;
    
    int rep = 1;
    while (*(++p) != '\0')
    {
        currentDigit = currentDigit * 8 + *p - 48;
        rep++;
    }
    
    
    return currentDigit;
    
}
