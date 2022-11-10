//
//  Tutorial5Q1.c
//  SC1003LabTuts
//
//  Created by Isaac Chun on 23/10/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INIT_VALUE -1000

//Question 1
typedef struct 
{
    double radius;
    double x;
    double y;
} circle;

int intersect(circle, circle);
int contain(circle *, circle*);
int distance(circle*c1, circle*c2);
int distanceSquared(circle * c1, circle *c2);

int main()
{
    circle c1, c2;
    int choice, result = INIT_VALUE;

    printf("Select one of the following options: \n");
    printf("1:intersect()\n");
    printf("2:contain()\n");
    printf("3:exit()\n");
    
    do
    {
        result = -1;
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter circle 1 (radius x y): \n");
                scanf("%lf %lf %lf", &c1.radius, &c1.x, &c1.y);
                printf("Enter circle 2 (radius x y): \n");
                scanf("%lf %lf %lf", &c2.radius, &c2.x, &c2.y);
                result = intersect(c1, c2);
                if (result ==1)
                    printf("intersect(): intersect\n");
                else if (result == 0)
                    printf("intersect(): not intersect\n");
                else
                    printf("intersecy(): error\n");
                break;
            case 2:
                printf("Enter circle 1 (radius x y): \n");
                scanf("%lf %lf %lf", &c1.radius, &c1.x, &c1.y);
                printf("Enter circle 2 (radius x y): \n");
                scanf("%lf %lf %lf", &c2.radius, &c2.x, &c2.y);
                result = contain(&c1, &c2);
                if (result ==1)
                    printf("contain(): contain\n");
                else if (result == 0)
                    printf("contain(): not contain\n");
                else
                    printf("contain(): error\n");
                break;
        } 
    } while (choice < 3);  

    return 0;
}

/******************************************************************************/
/*!
\brief
Calculates whether two circles intersect and returns a result.
\param c1 circle struct 1
\param c2 circle struct 2
\exception None
\return 1 if intersect, 0 if not intersect.
*/
/******************************************************************************/
int intersect (circle c1, circle c2)
{
    //Calculate without the square roots as sqrt is generally expensive
    //Even if this program is just a one time program, and we dont need to find out the actual distance
    //We just need to know if it intersects, so the cheaper the calculation the better
    double resultX = (c2.x - c1.x) * (c2.x - c1.x);
    double resultY = (c2.y - c1.y) * (c2.y - c1.y);
    float radii = c1.radius + c2.radius;
    return radii * radii > resultX + resultY;

    //Square root implementation
    // double dist = sqrt(pow(c2.x - c1.x,2) + pow(c2.y - c1.y,2));
    // return (c1.radius + c2.radius) > dist;
}

/******************************************************************************/
/*!
\brief
Calculates whether two circles contain each other and returns a result.
\param c1 circle struct 1
\param c2 circle struct 2
\exception None
\return 1 if intersect, 0 if not intersect.
*/
/******************************************************************************/
int contain(circle *c1, circle *c2)
{
    //Circle c1 contains circle c2 when radius of c1 is larger than or equal to
    //Sum of radius of c2 and distance between centres of c1 and c2
    double dist = sqrt(pow(c2->x - c1->x,2) + pow(c2->y - c1->y,2));
    float sum = c2->radius + dist;
    return c1->radius >= sum;
}

/******************************************************************************/
/*!
\brief
Calculates the distance between two circles
\param c1 circle struct 1
\param c2 circle struct 2
\exception None
\return distance between c1 and c2
*/
/******************************************************************************/
int distance(circle*c1, circle*c2)
{
    double dist = sqrt(pow(c2->x - c1->x,2) + pow(c2->y - c1->y,2));
    return dist;
}
/******************************************************************************/
/*!
\brief
Calculates the squaredDistance between two circles
\param c1 circle struct 1
\param c2 circle struct 2
\exception None
\return squareddistance between c1 and c2
*/
/******************************************************************************/
int distanceSquared(circle * c1, circle *c2)
{
    double resultX = (c2->x - c1->x) * (c2->x - c1->x);
    double resultY = (c2->y - c1->y) * (c2->y - c1->y);
    return resultX + resultY;
}