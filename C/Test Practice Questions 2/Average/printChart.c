//
//  mergeArrays.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

 #include <stdio.h>
void printChart(int x, int y, int z);
int main()
{
    int x,y,z;
    printf("Enter 3 inputs: \n");
    scanf("%d %d %d", &x, &y, &z);
    printf("The bar chart is: \n");
    printChart(x,y,z);
    return 0;
}
void printChart(int x, int y, int z)
{
/* Write your code here */
    //We have to take into account the max height of all x y z
    //We find the max first
    int max, i, j;
    max = x;
    if (x > y)
    {
        if (x > z)
            max = x;
        else 
            max = z;
    }
    else // y > x
    {
        if (y > z)
            max = y;
        else 
            max = z;
    }
    for (i = 0; i < max; ++i)
    {
         //This are the number of rows
            //And it is in x y z format
            (max - i  <= x) ? putchar('*') : putchar(' ');
            (max - i  <= y) ? putchar('*') : putchar(' ');
            (max - i  <= z) ? putchar('*') : putchar(' ');
        putchar('\n');
    }
} 