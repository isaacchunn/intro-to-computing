//
//  pattern6.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 2/11/22.
//

#include <stdio.h>
int main()
{
    int height;
    printf("Enter the height:\n");
    scanf("%d", &height);
    printf("The pattern is:\n");
    
    int i, j, endPoint;
    
    for(i = 0; i < height; ++i)
    {
        endPoint = height - i;
        for (j = 0; j < endPoint - 1; ++j)
        {
            putchar('*');
        }
        for (j = endPoint - 1; j < height; ++j)
        {
            putchar('=');
        }
        
        putchar('\n');
    }
     return 0;
}

