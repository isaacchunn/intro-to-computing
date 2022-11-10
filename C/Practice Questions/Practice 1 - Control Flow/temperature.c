//
//  temperature.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/2022
//

#include <stdio.h>
int main()
{
    float temp;
    float convert;
    printf("Enter the temperature in degree F:\n");
    scanf("%f", &temp);
    while(temp != -1)
    {
        convert = ((float)5/9) * (temp - 32);
        printf("Converted degree in C: %.2f\n", convert);
        printf("Enter the temperature in degree F:\n");
        scanf("%f", &temp);
    }
    return 0;
}
