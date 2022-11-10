//
//  strIntersect.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
void strIntersect(char *str1, char *str2, char *str3);
int main()
{
 char str1[50],str2[50],str3[50];

 printf("Enter str1: \n");
 scanf("%s",str1);
 printf("Enter str2: \n");
 scanf("%s",str2);
 strIntersect(str1, str2, str3);
 if (*str3 == '\0')
 printf("strIntersect(): null string\n");
 else
 printf("strIntersect(): %s\n", str3);
 return 0;
}
void strIntersect(char *str1, char *str2, char *str3)
{
 /* Write your code here */
    //Seems like a n^2 implementation?
    //Since they didn't allow string.h, i wil loop to 50 and braek early
    int i,j;
    int k =0;
    //If they are not null character...
    //Not the most fancy though and tiem complexity is bad
    for (i = 0; str1[i] != '\0'; ++i)
    {
        //Just search in the other array too
        for(j=0; str2[j] != '\0'; ++j)
        {
            //Search and see if equal to know there's an intersect
            if(str1[i] == str2[j])
            {
                str3[k++] = str1[i];
                break; //can break cause it contains unique characters.
            }
        }
    }
    //End with '\0
    str3[k] = '\0';
}
