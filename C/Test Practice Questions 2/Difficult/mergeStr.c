//
//  mergeStr.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>
void mergeStr(char *a, char *b, char *c);
int main()
{
 char a[80],b[80];
 char c[80];
 printf("Enter the first string a: \n");
 scanf("%s",a);
 printf("Enter the second string b: \n");
 scanf("%s",b);
 mergeStr(a,b,c);
 printf("mergeStr(): %s", c);
 return 0;
}
void mergeStr(char *a, char *b, char *c)
{
 /* Write your code here */
    //Strcpy into c.
    //Then concat b.
    //And then sort.
    strcpy(c,a);
    strcat(c,b);
    int len = (int)strlen(c);
    
    int i,j;
    for (i =0; i < len; ++i)
    {
        for (j = i; j < len; ++j)
        {
            if(c[i] > c[j])
            {
                char temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
}
