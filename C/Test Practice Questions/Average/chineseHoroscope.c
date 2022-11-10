//
//  chineseHoroscope.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 25/10/22.
//

#include <stdio.h>
int main()
{
    int userInput = 0, result;
    printf("Enter your birth year:\n");
    scanf("%d", &userInput);

    //Lets use a mod trick
    char * horoscopes[] = {"Monkey", "Rooster", "Dog", "Pig", "Rat", "Cow", "Tiger",
        "Rabbit", "Dragon", "Snake", "Horse", "Goat"};
    //Set p to be the start of horoscopes
    char ** p = horoscopes;
    
    //End condition
    while (userInput != -1)
    {
        //While the user input isvalid then we choose.
        result = userInput % 12;
        //Print out result
        printf("chineseHoroscope: %s\n", *(p + result));
        //Get next input
        printf("Enter your birth year:\n");
        scanf("%d", &userInput);
    }
     return 0;
}
