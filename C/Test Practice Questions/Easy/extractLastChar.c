//
//  extractLastChar.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//

#include <stdio.h>
#include <string.h>

void extractLastChar(char *str1, char * str2);

int main()
{
    char str1[80], str2[80], *p;

    printf("Enter a string: \n");
    fgets(str1, 80, stdin);
    if ((p=strchr(str1, '\n')))
        *p = '\0';
    extractLastChar(str1,str2);
    printf("extractFirstChar(): %s\n", str2);
    return 0;
}

/******************************************************************************/
/*!
\brief
Compares the contents of s1 and s2 to check if it's equal.
\param str1 input str
\param str2 output str
\exception None
\return None
*/
/******************************************************************************/
void extractLastChar(char * str1, char * str2)
{
    char * r, * w;
    r = str1;
    w = str2;
    while(*r != '\0')
    {
        //If r not space
        if (*r == ' ')
        {
            *w++ = *(r - 1);
        }
        r++;
    }
    *w++ = *(r - 1);
    *w = '\0';
}
