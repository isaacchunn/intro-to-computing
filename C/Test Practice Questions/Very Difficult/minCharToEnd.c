//
//  minCharToEnd.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>
void minCharToEnd(char *str);
int main()
{
     char str[80];

     printf("Enter a string: \n");
     scanf("%s",str);
     minCharToEnd(str);
     printf("minCharToEnd(): %s",str);
     return 0;
}
void minCharToEnd(char *str)
{
    //Indexing method i laze use pointers and write neat already
    int len = (int)strlen(str);
    int i, k =0;
    char c = str[0];
    int index = 0;
    for (i =1; i < len;++i)
    {
        if (str[i] < c)
        {
            c = str[i];
            index = i;
        }
    }
    //Start writing from index...
    for (k = index; k < len -1; ++k)
    {
        str[k] = str[k+1];
    }
    str[k++] = c;
    //End string off
    str[k] = '\0';
}
