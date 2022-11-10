//
//  platform1D.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 9/10/22.
//

#include <stdio.h>
int platform1D(int ar[], int size);
int main()
{
   int i,b[50],size;
   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i<size; i++)
      scanf("%d",&b[i]);
   printf("platform1D(): %d\n", platform1D(b,size));
   return 0;
}
int platform1D(int ar[], int size)
{  
    int i;
    int platform = 1, maxPlatform =1;
    for (i = 1; i < size; ++i)
    {
        if (ar[i] != ar[i-1])
        {
            if(platform >= maxPlatform)
                maxPlatform = platform;
            //Reset platform
            platform = 1;
        }
        else
        {
            platform++;
        }
    }
    return maxPlatform;
}
