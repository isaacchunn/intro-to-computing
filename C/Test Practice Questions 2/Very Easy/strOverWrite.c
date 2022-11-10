//
//  strOverWrite.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>

int strOverWrite(char *s1, char *s2, int pos);
int main()
{
     char s1[40], s2[40], *p;
     int pos, total;
     printf("Enter string 1: \n");
     fgets(s1, 80, stdin);
     if ((p=strchr(s1,'\n')))
         *p = '\0';
     printf("Enter string 2: \n");
     fgets(s2, 80, stdin);
     if ((p=strchr(s2,'\n')))
         *p = '\0';
     printf("Enter position: \n");
     scanf("%d", &pos);
     total = strOverWrite(s1, s2, pos);
     printf("strOverWrite(): %s %d\n", s1, total);
     return 0;
}
int strOverWrite(char *s1, char *s2, int pos)
{
    //Make char pointers that point to respective strings
    char * p, * q;
    int count = 0;
    p = s1;
    q = s2;
    
    //Increment the pointer to point at that position instead
    p += pos;
    int s1len = strlen(s1);
    //While not the end of s2 and while not the end of s1
    while (*q != '\0' && pos + count < s1len)
    {
        count++;
        *(p++) = *(q++);
        //Increment count and q pointer
    }
    return count;
}
