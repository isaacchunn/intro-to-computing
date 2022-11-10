//
//  Tutorial4Q3.c
//  SC1003LabTuts
//
//  Created by Isaac Chun on 23/10/22.
//

#include <stdio.h>
#include <string.h>

int main()
{   
    //Function prototype
    char * stringncpy (char * s1, char *s2, int n);

    char targetStr[40], sourceStr[40], *target, *p;
    int length;
    printf("Enter the string:\n");
    fgets(sourceStr,40,stdin);
    if((p=strchr(sourceStr,'\n')))
        *p ='\0';
    printf("Enter the number of characters: \n");
    scanf("%d", &length);
    target = stringncpy(targetStr,sourceStr,length);
    printf("stringncpy(): %s\n", target);
    return 0;
}

/******************************************************************************/
/*!
\brief
Copies the contents of s2 into s1 up to n letters.
\param s1 targetString to copy into
\param s2 sourceString to copy from
\param n how many letters to copy starting from 0?
\exception None
\return s1
*/
/******************************************************************************/
char * stringncpy (char * s1, char *s2, int n)
{
    //s2 is copied into s1.
    //We can do by indexing or pointer.

    //Array Notation
    // int i, j;
    // for (i =0; i < n; ++i)
    // {
    //     if(s2[i] == '\0')
    //         break;         
    //     s1[i] = s2[i];
    // }
    // s1[i] = '\0';
    // for (j = i; j < n; ++j)
    // {
    //     s1[j] = '\0';
    // }

    //Pointer Notation
    char * r1, * r2;
    r1 = s1;
    r2 = s2;
    int count = 0;
    while (count < n)
    {
        *r1++ = *r2++;
        //Increment count
        count++;
    }
    //At the end, we set at count to be '\0' to end the string
    *(r1 + count) = '\0';
    //Then we set the rest to empty spaces
    return s1;
}