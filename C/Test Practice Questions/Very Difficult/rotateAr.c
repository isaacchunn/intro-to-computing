//
//  rotateAr.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#define N 20
int main()
{
     int a[N],i,j,k,m;
     int size;
     /* Write your code here – for additional local variables */
     //Depending on size, there are size rows.
     printf("Enter array size: \n");
     scanf("%d",&size);
     printf("Enter %d data: \n", size);
     for (i=0; i<size; i++)
     scanf("%d", &a[i]);
     printf("Result: \n");
     /* Write your code here */
    
    for (i = 0; i < size; ++i)
    {
        //We print from back to front, and so we can use mod tricks
        for (j = 0; j < size; ++j)
        {
            printf("%d", a[(j+(size)-(i+1)) % size]);
        }
        putchar('\n');
    }
     return 0;
}
