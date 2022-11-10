//
//  printPattern3.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>

int main()
{
    //We can see that the rows start from i, and stops at (i*2)
    int i , j, height;
    printf("Enter the height:\n");
    scanf("%d", &height);
    printf("The pattern is:\n");
    for (i = 1; i <= height; ++i)
    {
        //Print first index
        printf("%d", i);
        for (j = i+1; j < (i * 2); ++j)
        {
            printf("%d",j%10);
        }
        putchar('\n');
    }
    return 0;
}
