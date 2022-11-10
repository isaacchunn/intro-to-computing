//
//  reverseDigits.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//

#include <stdio.h>
int reverseDigits(int num);
int main()
{
    int num, result=999;
    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits(): %d\n", reverseDigits(num));
    return 0;
}

/******************************************************************************/
/*!
\brief
Reverses a number and returns the result
\param num number to reverse
\exception None
\return reversed Number
*/
/******************************************************************************/
int reverseDigits(int num)
{
    //12345
    //54321
    //Base case
    if(num ==0)
        return 0;
    
    int reversed = 0;
    int currentDigit;
    //int r;
    
    while (num > 0)
    {
        currentDigit = num % 10;
        reversed = (reversed * 10) + currentDigit;
        num /=10;
    }
    return reversed;
}
