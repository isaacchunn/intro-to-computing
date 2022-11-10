//
//  pattern2.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//
#include<stdio.h>
int main()
{
    int num;
    printf("Enter the height:\n");
    scanf("%d", &num);
    printf("The pattern is:\n");
    int i,j;
    for (i = 0; i < num; ++i)
    {
        int midPoint = (i*2) + 1;
        //Print spaces
        for(j =0; j < (num - i) - 1; ++j)
        {
            putchar(' ');
        }
        //Print data
        //printf("MidPoint = %d\n", midPoint);
        for (j = i + 1; j <= midPoint; ++j)
        {
            printf("%d",j % 10);
        }
        for (j = midPoint -1; j >= i+1; --j)
        {
            printf("%d",j % 10);
        }
        printf("\n");
    }
     return 0;
}
