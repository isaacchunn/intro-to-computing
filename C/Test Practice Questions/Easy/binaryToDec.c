//
//  binaryToDec.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <math.h>
int main()
{
    int binary;
    int result = 0, digit;
    printf("Enter a binary number:\n");
    scanf("%d", &binary);
    int exponent =0;
    //Process the result
    while (binary > 0)
    {
        digit = binary % 10;
        result += digit * pow(2,exponent);
        binary /= 10;
        exponent++;
    }
    printf("The equivalent decimal number: %d\n",result);
    return 0;
}
