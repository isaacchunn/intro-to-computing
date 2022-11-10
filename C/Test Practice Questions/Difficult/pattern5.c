//
//  pattern5.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>

int main()
{
    int height;
    printf("Enter the height:\n");
    scanf("%d", &height);
    printf("The pattern is:\n");
    //We know that the mid point is the height for pyramids.
    //Loop through all the rows first
    int i, j, print, spaces;
    for (i= 0; i < height; ++i)
    {
        print = (i*2) + 1;
        spaces = (height - i - 1);
        //We need to print spaces up to the midpoint - a certain value
        for (j = 0; j < spaces ; ++j)
        {
            putchar(' ');
        }
        //Check first char if its a plus or not
        //We can do some tricks with the mod.
        //According to line, we know that if mod 2 is 0, its a plus
        if (i % 2 == 0)
            putchar('+');
        //Then we print += as a trick
        for(j = 0; j < i; ++j)
            printf("=+");
        //Then we end it off with a = if needed
        if (i % 2 == 1)
            putchar('=');
        //new line..
        putchar('\n');
    }
    
    return 0;
}
