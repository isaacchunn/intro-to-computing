//
//  decTohexStr.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
void decTohexStr(char *str, int num);
int main()
{
     int num,i;
     char str[20];
     printf("Enter a decimal number: \n");
     scanf("%d",&num);
     decTohexStr(str,num);
     printf("decTohexStr(): %s\n",str);
     return 0;
}
void decTohexStr(char *str, int num)
{
 /* Write your code here */
    //Ascii values range from 48 - 57
    //WE have num, so we have to convert it to hex first.
    
    int hex = 0;
    int quotient, remainder;
    //Manual power using integers only
    int i = 0, j;
    while (num > 0)
    {
        //We need the remainders
        remainder = num % 16;
        //We need to display as letter ABCDEF
        if (remainder > 9)
        {
            str[i] = 65 + (remainder - 10);
        }
        else //below or equals 9, 0123456789
        {
            //48 is start of letters
            str[i] = 48 + remainder;
        }
        i++;
        num /=16;
    }
    
    //We know that there are i digits.
    //Reverse the string
    for (j =0; j < i / 2; ++j)
    {
        //swap using char
        char c = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = c;
    }
}
