//
//  findSubString.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>
#define INIT_VALUE 999
int findSubstring(char *str, char *substr);
int main()
{
   char str[40], substr[40], *p;
   int result = INIT_VALUE;
   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';
   printf("Enter the substring: \n");
   fgets(substr, 80, stdin);
   if (p=strchr(substr,'\n')) *p = '\0';
   result = findSubstring(str, substr);
   if (result == 1)
      printf("findSubstring(): Is a substring\n");
   else if ( result == 0)
      printf("findSubstring(): Not a substring\n");
   else
      printf("findSubstring(): An error\n");
   return 0;
}
int findSubstring(char *str, char *substr)
{
   /* Write your code here */
    //Assume we have a substr at the start
       int subStringFound = 1;
       int strLen = strlen(str);
       int subStrLen = strlen(substr);
       int i, k;
       for (i =0; i < strLen; ++i)
       {
           //Check for bounds
           if (i + subStrLen > strLen)
               break;
            
           //Assume found
           subStringFound = 1;
           //Second for loop to check up to n spaces
           for (k = 0; k < subStrLen; ++k)
           {
               if (substr[k] != str[k + i])
               {
                   subStringFound = 0;
                   break;
               }
           }
           
           //IF is a subset, return 1
           if (subStringFound)
               return 1;
       }
       return 0;
}
