//
//  countSubstring.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>
int countSubstring(char str[], char substr[]);
int main()
{
     char str[80], substr[80];
     int result;

     printf("Enter the string: \n");
     scanf("%s",str);
     printf("Enter the substring: \n");
     scanf("%s",substr);
     result = countSubstring(str, substr);
     printf("countSubstring(): %d\n", result);
     return 0;
}
int countSubstring(char str[], char substr[])
{
    int substringCount = 0;
    //Calculate both lengths of the arrays
    int strLen = (int)strlen(str);
    int subStrLen = (int)strlen(substr);
    //Calculate range checks
    int found = 1;
    int i, k;
    //Loop through all.
    for (i = 0; i < strLen; ++i)
    {
        //if the max range is more than strlen then we cannot find any more further substrs?
        if (i + subStrLen > strLen)
            break;
        
        found = 1;
        //Maybe do int to int checking
        for (k = 0; k < subStrLen; ++k)
        {
            if (str[k + i] != substr[k])
                found = 0;
        }
        if (found)
            substringCount++;
        
    }
    return substringCount;
}
