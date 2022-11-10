//
//  countChar.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>

int main()
{
    int digits = 0, letters = 0;
    
    char c;
    printf("Enter your characters (# to end):\n");
    scanf("%c", &c);
    while (c != '#')
    {
        //While not the terminating condition, we keep checking char by char
        //Check by ascii for digits
        if(48 <= c && c <= 57)
            digits++;
        else if (97 <= c && c <= 122)//seems like small letters are checked only?
            letters++;
        
        //keep scanning
        scanf("%c", &c);
    }
    printf("The number of digits: %d\n", digits);
    printf("The number of letters: %d\n", letters);
    
    return 0;
}
