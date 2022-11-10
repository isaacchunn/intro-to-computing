//
//  PigLatin.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <string.h>
void PigLatin(char *eword, char *PLword);
int main()
{
     char eword[80];
     char PLword[80];
     printf("Enter your English word: \n");
     scanf("%s", eword);
     PigLatin(eword, PLword);
     printf("PigLatin(): %s\n", PLword);
     return 0;
}
void PigLatin(char *eword, char *PLword)
{
    /* Write your code here */
    //Rule 1, check for the word with consonant letters...
    //Else we check if it starts with vowels. So the rules are determined based off the first letters.
    
    //ultimate brute force technique i laze
    int i, k , z = 0;
    int ewordLen = (int)strlen(eword);
    for (i = 0; i < ewordLen; ++i)
    {
        if(eword[i] == 'a' || eword[i] == 'e' || eword[i] == 'i' || eword[i] =='o' || eword[i] == 'u' || eword[i] == 'y' || eword[i] == '\0')
            break;
    }
    //These are all the vowels at the start
    for (k = i; k < ewordLen; ++k)
    {
        PLword[z++] = eword[k];
    }
    //Then cat the vowels
    for (k = 0; k < i; ++k)
    {
        PLword[z++] = eword[k];
    }
    
    PLword[z++] = 'a';
    PLword[z++] = 'y';
    PLword[z++] = '\0';
    
}
