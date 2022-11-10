//
//  pattern1.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//
#include<stdio.h>
int main()
{
    printf("Enter the height:\n");
    int num, i, j, midPoint;
    scanf("%d", &num);
    printf("The pattern is:\n");
    //For each row
    for (i = 0; i < num; ++i)
    {
        midPoint = (i * 2) + 1;
        //Print the appropriate spaces
        for (j = 0; j < (num - i) - 1; ++j)
        {
            putchar(' ');
        }
        //Then print for the left
        for (j = i + 1; j <= midPoint; ++j)
        {
            putchar('*');
        }
        //Then print for all the stars on the right starting from midPoin
        for(j = midPoint-1; j >= i+1; --j)
        {
            putchar('*');
        }
        //Print new line after all prints
        putchar('\n');
       }
     return 0;
}
