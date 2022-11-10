//
//  compareChar.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>
void compareChar(char *str1, char *str2, char *str3);
int main()
{
     char str1[80],str2[80],str3[80];

     printf("Enter the first string: \n");
     scanf("%s",str1);
     printf("Enter the second string: \n");
     scanf("%s",str2);
     compareChar(str1, str2, str3);
     printf("compareChar(): %s\n", str3);
     return 0;
}
void compareChar(char *str1, char *str2, char *str3)
{
    /* Write your code here */
    int i;
    int str1Len = (int)strlen(str1);
    int str2Len = (int)strlen(str2);
    int maxLen = str1Len > str2Len ? str1Len : str2Len;
    for (i = 0; i < maxLen - 1; ++i)
    {
        //If one bigger than the other,
        str3[i] = (str1[i] > str2[i]) ? str1[i] : str2[i];
    }
    str3[i] = '\0';
}