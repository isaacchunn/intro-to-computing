//
//  remDuplicates.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//

#include <stdio.h>
#define N 20
int remDuplicates(int a[], int size);
int main()
{
    int a[N],i, size;
    
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data:\n", size);
    for(i=0;i<size;i++)
        scanf("%d", &a[i]);
    size = remDuplicates(a, size);
    printf("remDuplicates(): \n");
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

/******************************************************************************/
/*!
\brief
Remove all duplicates of a given int array
\param a int array input
\param size size of a
\exception None
\return number of duplicates removed from
*/
/******************************************************************************/
int remDuplicates(int a[], int size)
{
     int currentIndex = a[0];
     int i, y =0;
     a[y] = currentIndex;
     for (i = 1; i < size+1; ++i)
     {
         //If not
         if (a[i] != currentIndex)
         {
             a[++y] = a[i];
             currentIndex = a[i];
         }
     }
     return y;
}

