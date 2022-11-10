#include <stdio.h>
#include <math.h>

//Enum to run functions via switch
enum QUESTION
{
    QUESTION1 = 0,
    QUESTION2,
    QUESTION3,
    QUESTION4
};

//Function definitions

void question1();
void question2();
void question3();
void question4();
int factorial(int n);

int main()
{
    //Do questions
    enum QUESTION questionToRun = QUESTION2;
    switch (questionToRun)
    {
        case QUESTION1:
            question1();
            break;
        case QUESTION2:
            question2();
            break;
        case QUESTION3:
            question3();
            break;
        case QUESTION4:
            question4();
            break;
        default:
            break;
    };
    return 0;
}


/******************************************************************************/
/*!
\brief
Function for question 1.

\param None
\exception None
\return None
*/
/******************************************************************************/
void question1()
{
    /*Write a C program that prints the ID and grade of each student in a class. The input contains the student ID's and their marks.
    /The range of the marks is from 0 to 100. The relationships of the marks and grades are given below.
    Grade   Mark
    A       100-75
    B       74-65
    C       64-55
    D       54-45
    F       44-0

    Use the sentinel value -1 for student ID to indicate the end of user input.
    Write the program using the switch statement.
    */

    //Initialize initial variables
    int studentID, mark;
    //Prompt user to make inputs...
    printf("Enter Student ID: \n");
    //Scan user input to a studentID
    scanf("%d", &studentID);
    //Declare the loop in which it runs.
    while (studentID != -1) //Loop conditions
    {
        //Prompt user to make inputs to marks...
        printf("Enter Mark: \n");
        //Scan user input to marks
        scanf("%d", &mark);

        //Do some comparisons in float cause the cases cant cover the mid points
        float markFloat = (float)mark/10;
        //Switch the marks but divided by 10 so less cases

        //GNU GCC Compiler capable switch, using CodeBlocks.
        switch (mark)
        {
            case 75 ... 100:
                printf("Grade = A\n");
                break;
            case 65 ... 74:
                printf("Grade = B\n");
                break;
            case 55 ... 64:
                printf("Grade = C\n");
                break;
            case 45 ... 54:
                printf("Grade = D\n");
                break;
            default:
                printf("Grade = F\n");
                break;
        }

        //Still not very elegant solution, why must I do this in switch...
//        switch (mark / 10)
//        {
//            case 10:
//            case 9:
//            case 8:
//            case 7:
//                if (markFloat >= 7.5f)
//                    printf("Grade = A\n");
//                else
//                    printf("Grade = B\n");
//                break;
//            case 6:
//                if (markFloat >= 6.5f)
//                    printf("Grade = B\n");
//                else
//                    printf("Grade = C\n");
//                break;
//            case 5:
//                if (markFloat >= 5.5f)
//                    printf("Grade = C\n");
//                else
//                    printf("Grade = D\n");
//                break;
//            case 4:
//                if (markFloat >= 4.5f)
//                    printf("Grade = D\n");
//                else
//                    printf("Grade = F\n");
//                break;
//            default:
//                printf("Grade = F\n");
//                break;
//        }
        //Re acquire inputs.
        printf("Enter Student ID: \n");
        scanf("%d", &studentID);
    }
}
/******************************************************************************/
/*!
\brief
Function for question 2.

\param None
\exception None
\return None
*/
/******************************************************************************/
void question2()
{
    /*Write a C program that reads in several lines of non-negative integer numbers, computes the average for each line and prints out the average.
    The value -1 in each line of user input is used to indicate the end of input for that line.
    */
   //We need for loops.
   //Read the number of lines input first.
   int lines;
   printf("Enter number of lines:\n");
   scanf("%d", &lines);
   for (int i = 0; i < lines; ++i)
   {
        //Keep track of index.
        int index = 0;
        int currentInt = 0;
        //Get user input on lines
        printf ("Enter line %d (end with -1): \n", i+1);
        float sum = 0;
        //Adding this here allows the while loop to not run I suppose.
        scanf("%d", &currentInt);
        //While and split into arr.
        while (currentInt != -1)
        { 
            //If the currentIndex is not at the end condition
            //Increment sum based off the int
            sum += currentInt;
            //Increment index
            index++;
            //Rescan the next element in the input buffer.
            scanf("%d", &currentInt);
        }
        //We have finished inputting data into the array.
        //Loop through the for loop but excluding last element.
        float average = sum / (index);
        printf("Average = %.2f\n", average);
   }
}
/******************************************************************************/
/*!
\brief
Function for question 3.

\param None
\exception None
\return None
*/
/******************************************************************************/
void question3()
{
    //Is there a better way though?
    //Initialize the height
    int numberHeight = 0;
    //Triangle pattern
    printf("Enter the height:\n");
    scanf ("%d", &numberHeight);
    printf("Pattern:\n");
    //Loop through all the available rows.
    for (int i = 1; i < numberHeight +1; ++i)
    {
        //Set x be limited by current i, and print based on mod. Do the columns.
        for (int x = 0; x < i; ++x)
        {
            printf("%d", i % 3 == 0 ? 3 : i % 3);
        }
        //New line for entries.
        printf("\n");
    }
}
/******************************************************************************/
/*!
\brief
Function for question 4.

\param None
\exception None
\return None
*/
/******************************************************************************/
void question4()
{
    //Write a C progrma that computers the values of e^x according to the formula...
    //A power of 0 returns 1.
    float result = 1;
    float x;
    printf("Enter x:\n");
    //Store the input of x
    scanf("%f", &x);
    for (int i =1; i <= 10; ++i)
    {
        //Append results to calculations
        result += ((float)(pow(x,i)) / factorial(i));
    }
    //Print final result
    printf("Result = %.2f\n", result);

}

/******************************************************************************/
/*!
\brief
Helper function to calculate factorials.

\param n factorial exponent
\exception None
\return n factorial.
*/
/******************************************************************************/
int factorial (int n)
{
    int fact =1;
    for (int i =1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}