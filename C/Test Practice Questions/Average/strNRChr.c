//
//  strNRChr.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//

#include <stdio.h>
#include <string.h>
char *strNRChr(char *str, int n, char ch);
int main()
{
     char str[80], ch, dummy;
     char *temp=NULL;
     int n;
     printf("Enter a string: \n");
     scanf("%s",str);
     scanf("%c",&dummy);
     printf("Enter a char: \n");
     scanf("%c",&ch);
     printf("Enter the occurrence: \n");
     scanf("%d", &n);
     temp = strNRChr(str, n, ch);
     if (temp!=NULL)
     printf("strNRChr(): %s\n", temp);
     else
     printf("strNRChr(): null string\n");
     return 0;
}

/******************************************************************************/
/*!
\brief
Locates the last nth occurence of ch
\param str input str
\param n size of str
\param ch  character to check for
\exception None
\return input str
*/
/******************************************************************************/
char * strNRChr(char * str, int n, char ch)
{
    char * r, * w;
      w = str;
      r = str + (int)strlen(str) - 1;
      int count =0;
      while (r != str)
      {
          if (*r == ch)
          {
              count++;
              if (count == n)
                  break;
          }
          //Decrement to find last n
          r--;
      }
      //printf("\ncount= %d", count);
      
      if(count == 0)
          return '\0';
      
      //Starting from where r is, we append back.
      while(*r != '\0')
      {
          *(w++) = *(r++);
      }
      *w = '\0';
      return str;
   
}
