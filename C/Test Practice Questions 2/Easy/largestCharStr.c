//
//  largestCharStr.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>
#define N 20
void largeCharStr(char str[N][20], char a[N], int size);
int main()
{
     char str[N][20],dummy;
     char a[N],i,j;
     int size;

     printf("Enter number of strings: \n");
     scanf("%d", &size);
     scanf("%c", &dummy);
     for (i=0;i<size;i++){
     printf("Enter string %d: \n", i+1);
     scanf("%s",str[i]);
     }
     largeCharStr(str,a,size);
     printf("largeCharStr(): \n");
     for (i=0;i<size;i++) {
     printf("String %d: ",i+1);
     printf("%c\n",a[i]);
 }
 return 0;
}
void largeCharStr(char str[N][20], char a[N], int size)
{
    /* Write your code here */
    //Lets do a indexing approach that might be slower than pointers
    int i =0, j = 0;
    char largestChar;
    for (i = 0; i < size; ++i)
    {
        //Set largest to be the first
        largestChar = str[i][0];
        //Loop through string... in each index, starting from 1
        for (j = 1; j <= size; ++j)
        {
            //Break once we reach a '\0'
            if(str[i][j] == '\0')
                break;
            
            //Else we do size comparisons
            if (str[i][j] >= largestChar)
                largestChar = str[i][j];
        }
        
        //Then we append into a
        a[i] = largestChar;
    }
}
