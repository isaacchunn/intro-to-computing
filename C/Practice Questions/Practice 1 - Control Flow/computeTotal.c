
//
//  computeTotal.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>

int main()
{
    int lines, i,j, total =0;
    int c1, c2;
    printf("Enter number of lines:\n");
    scanf("%d", &lines);
    for (i = 1; i <= lines; ++i)
    {
        //Reset total
        total = 0;
        printf("Enter line %d:\n", i);
        //maybe when i think of a better way when its not 4:32am
        scanf ("%d", &c1);
        for (j =0; j < c1; ++j)
        {
            scanf("%d", &c2);
            total += c2;
        }
        printf("Total: %d\n", total);
    }
    return 0;
}
