//
//  matShifting.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//

#include <stdio.h>
#define M 10
void matShifting(int a[M][M], int b[M][M], int n);
int main()
{
     int a[M][M], b[M][M];
     int n,i,j;

     printf("Enter array (nxn) size (n<=10): \n");
     scanf("%d",&n);
     for (i=0; i<n; i++) {
     printf("Enter row %d: \n", i);
     for (j=0; j<n; j++)
     scanf("%d",&a[i][j]);
     }
     matShifting(a,b,n);
     printf("Array b: \n");
     for (i=0;i<n;i++) {
     for (j=0;j<n;j++)
     printf("%d ",b[i][j]);
     printf("\n");
     }
     return 0;
}

/******************************************************************************/
/*!
\brief
Shifts a matrix on it's columns
\param a input int 2d array
\param b output int 2d array
\param n size of matrix
\exception None
\return None
*/
/******************************************************************************/
void matShifting(int a[M][M], int b[M][M], int n)
{
    int i, j;
    //Loop through the columns
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            b[i][(j + 1) % n] = a[i][j];
        }
    }
}
