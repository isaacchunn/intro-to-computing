//
//  mergeArrays.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#define M 80
int mergeArrays(int a[M], int b[M], int c[M], int n1, int n2);
int main()
{
     int a[M],b[M],c[M],i,k=0,n1,n2;
     printf("Enter the size of array a: \n");
     scanf("%d", &n1);
     printf("Enter the size of array b: \n");
     scanf("%d", &n2);
     printf("Enter array a[%d]: \n", n1);
     for (i=0; i<n1; i++)
     scanf("%d",&a[i]);
     printf("Enter array b[%d]: \n", n2);
     for (i=0; i<n2; i++)
     scanf("%d",&b[i]);
     k=mergeArrays(a,b,c,n1,n2);
     printf("mergeArrays(): \n");
     for (i=0;i<k;i++)
     printf("%d ",c[i]);
     return 0;
}
int mergeArrays(int a[M], int b[M], int c[M], int n1, int n2)
{
    /* Write code here */
    //WE know that the ize of c is n1 + n2;
    int cSize = n1 + n2;
    //We do merging first and then we do a sort afterwards
    //We append into c starting from a and b
    //Seperate for loops?
    int i, j, temp;
    //Append a's elements into c first
    for (i = 0; i < n1; ++i)
        c[i] = a[i];
    //append b's elements into c now
    for (i = 0; i < n2; ++i)
        c[i + n1] = b[i];
    //Conduct bubble sorting O(n/2?)
    for (i = 0; i < cSize; ++i)
    {
        for (j = i; j < cSize; ++j)
        {
            //Sorting in ascending order
            if (c[i] > c[j])
            {
                //Do some swapping
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    return cSize;
} 
