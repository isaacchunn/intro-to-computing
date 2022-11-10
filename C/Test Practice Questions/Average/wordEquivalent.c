//
//  wordEquivalent.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//

#include <stdio.h>
#include <string.h>
void wordEquivalent(int num, char *str);
int main()
{
 int num;
 char str[40]="";

 printf("Enter the number: \n");
 scanf("%d", &num);
 wordEquivalent(num, str);
 printf("wordEquivalent(): %s", str);
 return 0;
}

/******************************************************************************/
/*!
\brief
Calculates the word equivalent of a given digit from back to front
\param num number to convert
\param str string
\exception None
\return None
*/
/******************************************************************************/
void wordEquivalent(int num, char * str)
{
    if (num > 99)
    {
        strcpy(str, "Input exceeds 99");
        return;
    }
    
    //is there a better way to print spaces?
    int currentDigit = 0, firstRun = 0;
    //Process each digit
    while (num > 0)
    {
        //Get the current right most digit
        currentDigit = num % 10;
        //Implement char str adding
        if (firstRun)
        {
            //If it's not the first run then theres more digits to print spaces for
            strcat(str, " ");
        }
        switch (currentDigit)
        {
            case 0:
                strcat(str, "zero");
                break;
            case 1:
                strcat(str, "one");
                break;
            case 2:
                strcat(str, "two");
                break;
            case 3:
                strcat(str, "three");
                break;
            case 4:
                strcat(str, "four");
                break;
            case 5:
                strcat(str, "five");
                break;
            case 6:
                strcat(str, "six");
                break;
            case 7:
                strcat(str, "seven");
                break;
            case 8:
                strcat(str, "eight");
                break;
            case 9:
                strcat(str, "nine");
                break;
        }
        //Decrease by num
        num /=10;
        //Set first run to not print extra spaces
        firstRun = 1;
    }
}
