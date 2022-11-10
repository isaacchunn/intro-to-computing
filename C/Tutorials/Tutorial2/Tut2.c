#include <stdio.h>
#include <math.h>

//Sample code for Tut2 that passed APAS

void inputXY(double *x1, double *y1, double *x2, double *y2);
void outputResult(double dist);
double calDistance1(double x1, double y1, double x2, double y2);
void calDistance2(double x1, double y1, double x2, double y2, double *dist);

int main()
{
    double x1,y1,x2,y2,distance =-1;
    inputXY(&x1, &y1, &x2, &y2);            //Call by reference
    distance = calDistance1(x1,y1,x2,y2);   //Call by value
    printf("calDistance1(): ");
    outputResult(distance);
    calDistance2(x1,y1,x2,y2, &distance);   //Call by reference
    printf("calDistance2(): ");
    outputResult(distance);                 //Call by value
    return 0;
}

/******************************************************************************/
/*!
\brief
Function that finds the distance between two points

\param x1: x-coordinate of 1st point
\param y1: y-coordinate of 1st point
\param x2: x-coordinate of 2nd point
\param y2: y-coordinate of 2nd point
\exception None
\return abs distance between (x1,y1) and (x2,y2)
*/
/******************************************************************************/
double calDistance1(double  x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2-x1),2) + (pow((y2-y1),2)));
}

/******************************************************************************/
/*!
\brief
Function that finds the distance between two points

\param x1: x-coordinate of 1st point
\param y1: y-coordinate of 1st point
\param x2: x-coordinate of 2nd point
\param y2: y-coordinate of 2nd point
\exception None
\return None
*/
/******************************************************************************/
void calDistance2(double  x1, double y1, double x2, double y2, double *dist)
{
    *dist= sqrt(pow((x2-x1),2) + (pow((y2-y1),2)));
}


/******************************************************************************/
/*!
\brief
Function prints a double to the terminal.

\param dist : double value to print
\exception None
\return None
*/
/******************************************************************************/
void outputResult(double dist)
{
    printf("%.2lf\n", dist);
}

/******************************************************************************/
/*!
\brief
Function that reads user's inputs and stores it into x1,t1,x2,y2 respectively.

\param x1: reference to x-coordinate of 1st point
\param y1: reference to y-coordinate of 1st point
\param x2: refernece to x-coordinate of 2nd point
\param y2: reference to y-coordinate of 2nd point
\exception None
\return None
*/
/******************************************************************************/
void inputXY(double *x1, double * y1, double *x2, double *y2)
{
    printf("Input x1 y1 x2 y2:\n");
    //Read by space and store in the appropriate values.
    scanf("%lf %lf %lf %lf", x1,y1,x2,y2);
}
