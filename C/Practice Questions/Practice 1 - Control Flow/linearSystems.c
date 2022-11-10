//
//  linearSystem.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>
#include <math.h>
int main()
{
    float a1, b1, c1, a2, b2 , c2;
    printf("Enter a1,b1,c1,a2,b2,c2:\n");
    scanf("%f%f%f%f%f%f",&a1,&b1,&c1,&a2,&b2,&c2);
    float x,y;
    
    float denom = (a1*b2) - (a2*b1);
    //Should use an epsilon value as this is dangerous but no time
    if (denom == 0.0f)
    {
        //We treat denom as 0
        printf("Denominator is zero!\n");
    }
    else
    {
        x = ((b2*c1) - (b1*c2))/ denom;
        y = ((a1*c2) - (a2*c1))/ denom;
        printf("x=%.2f,y=%.2f\n", x,y);
    }
        
    return 0;
}
