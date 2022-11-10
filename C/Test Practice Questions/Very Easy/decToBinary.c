//
//  decToBinary.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <math.h>
int main()
{
    //32 bit integer? might be too much though
    int binaryNum[32];
    int i =0, j = 0;
    printf("Enter a decimal number:\n");
    int dec;
    scanf("%d", &dec);
    while (dec > 0)
    {
        binaryNum[i++] = dec %2;
        dec /=2;
    }
    
    printf("The equivalent binary number: ");
    for (j = i-1; j >= 0; j--)
    {
        printf("%d", binaryNum[j]);
    }
    
    return 0;
}

