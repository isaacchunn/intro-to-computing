//
//  sortCharSize.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
void sortCharStr(char *str);
int main()
{
 char str[80];

 printf("Enter a string: \n");
 scanf("%s",str);
 sortCharStr(str);
 printf("sortCharStr(): %s\n", str);
 return 0;
}
void sortCharStr(char *str)
{
    //Without string.h included, if want to use string.h then use strlen instead.
    char *p = str;
    int len = 0;
    while(*p != '\0')
    {
        len++;
        p++;
    }

    //Do bubble sort and return
    int i, j;
    for (i =0; i < len; ++i)
    {
        for (j = i; j < len; ++j)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}