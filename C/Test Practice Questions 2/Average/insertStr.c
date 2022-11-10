//
//  insertStr.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>
char *insertStr(char *a, char *s);
int main()
{
     char a[40],s[40];
     printf("Enter the string a: \n");
     scanf("%s",a);
     printf("Enter the string s: \n");
     scanf("%s",s);
     insertStr(a,s);
     printf("insertStr(): %s",a);
     return 0;
}
char *insertStr(char *a, char *s)
{
    /* Write your code here */ 
    int aLen = (int)strlen(a);
    int totalLen = aLen + strlen(s);
    //So we know, that we should start writing at a + len.
    char * p = a + aLen;
    char * j = s;
    int x,y;
    //Append s into a, can use strcpy but i want to test my pointer knowledge...
    while (*j != '\0')
    {
        //Just append all
        (*p++) = *(j++);
    }
    //Then we bubble sort according to ASCII
    //Alphabetically means ascending order
    //Use some for loops
    for (x = 0; x < totalLen; ++x)
    {
        for (y = x; y < totalLen; ++y)
        {
            //Ascending order is >
            if (a[x] > a[y])
            {
                char temp = a[x];
                a[x] = a[y];
                a[y] = temp;
            }
        }
    }
    return a;
}
