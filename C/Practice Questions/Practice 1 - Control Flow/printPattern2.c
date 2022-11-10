//
//  printPattern2.c
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
    //We let 0 be A, 1 for B after the mod
    for (i = 0; i < height; ++i)
    {
        i % 2 == 0 ? putchar('A') : putchar('B');
        for (j = i + 1; j <= (i*2); ++j)
        {
            j % 2 == 0 ? putchar('A') : putchar('B');
        }
        putchar('\n');
    }
    return 0;
}
