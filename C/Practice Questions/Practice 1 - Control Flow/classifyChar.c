//
//  classifyChar.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/2022
//

#include <stdio.h>
int main()
{
    //Using ascii table, we know that
    //Digits are from 49 - 57
    //small characters are 97 - 122
    //capitals are 65 - 90
    
    //We take in a character
    char c;
    printf("Enter a character:\n");
    scanf("%c", &c);
    //Do some detections
    
    //Check for digits
    if (49 <= c && c <= 57)
        printf("Digit\n");
    else if (65 <= c && c <= 90)
        printf("Upper case letter\n");
    else if (97 <= c && c <= 122)
        printf("Lower case letter\n");
    else
        printf("Other character\n");
    
    return 0;
}
