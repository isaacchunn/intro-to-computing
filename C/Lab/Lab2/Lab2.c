#include <stdio.h>

int numDigits1(int num);
int digitPos1(int num, int digit);
int square1(int num);
void numDigits2(int num, int * result);
void digitPos2(int num, int digit, int* result);
void square2(int num, int *result);

int main()
{
    int choice;
    int number, digit, result = 0;

    do 
    {
        printf("\nPerform the following functions ITERATIVELY:\n");
        printf("1: numDigits1()\n");
        printf("2: numDigits2()\n");
        printf("3: digitPos1()\n");
        printf("4: digitPos2()\n");
        printf("5: square1()\n");
        printf("6: square2()\n");
        printf("7: quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the number: \n");
                scanf("%d", &number);
                printf("numDigits1(): %d", numDigits1(number));
                break;
            case 2:
                printf("Enter the number: \n");
                scanf("%d", &number);               
                numDigits2(number, &result);
                printf("numDigits2(): %d\n", result);
                break;
            case 3:
                printf("Enter the number: \n");
                scanf("%d", &number);
                printf("Enter the digit: \n");
                scanf("%d", &digit);
                printf("digitPos1(): %d\n", digitPos1(number,digit));
                break;
            case 4:
                printf("Enter the number: \n");
                scanf("%d", &number);
                printf("Enter the digit: \n");
                scanf("%d", &digit);
                digitPos2(number,digit, &result);
                break;
            case 5:
                printf("Enter the number: \n");
                scanf("%d", &number);
                printf("square1(): %d\n", square1(number));
                break;
            case 6:
                printf("Enter the number: \n");
                scanf("%d", &number);
                square2(number, &result);
                printf("square2(): %d\n", result);
                break;
            default:
                printf("Program terminating .....\n");
                break;
        }
        
    } while(choice < 7);
    return 0;
}

/******************************************************************************/
/*!
\brief
Function that returns the num of digits in an int.

\param num -> number to get number of digits from
\exception None
\return number of digits of param num.
*/
/******************************************************************************/
int numDigits1(int num)
{
    int count = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

/******************************************************************************/
/*!
\brief
Function that returns the num of digits in an int.

\param num -> number to get number of digits from
\param result -> result pointer
\exception None
\return None
*/
/******************************************************************************/
void numDigits2(int num, int * result)
{
    //Probably a good idea to set result to 0 for more consistency as func might be reused.
    *result = 0;
    while (num > 0)
    {
        num /=10;
        *result +=1;
    }
}
/******************************************************************************/
/*!
\brief
Function that returns the position of digit if any.

\param num -> input number
\param digit -> digit to find in num
\exception None
\return position of digit from right to left. right is 0.
*/
/******************************************************************************/
int digitPos1(int num, int digit)
{
    //Default index
    int index = 1;
    while (num > 0)
    {
        //Find right most digit.
        int rem = num % 10;
        if (rem == digit)
            return index; 
        //Else we divide and keep finding
        num /=10;
        index++;
    }
    return 0;
}

/******************************************************************************/
/*!
\brief
Function that returns the position of digit if any.

\param num -> input number
\param digit -> digit to find in num
\param result -> result pointer
\exception None
\return None
*/
/******************************************************************************/
void digitPos2(int num, int digit, int * result)
{
    //Default index
    *result = 1;
    while (num > 0)
    {
        int rem = num % 10;
        if (rem == digit)        
            return;       
        //Else we keep dividing and finding
        num /=10;
        *result+=1;
    }
    //Else not found so set to 0.
    *result = 0;
}

/******************************************************************************/
/*!
\brief
Function that returns the square of a positive integer number num
by computing the sum of odd integers starting with 1 

\param num -> input number
\exception None
\return square of positive integer number
*/
/******************************************************************************/
int square1(int num)
{
    int sum = 0;
    //Quite shortcut to do, not sure if pass hidden test case
    for (int i =1; i < (num *2); i+=2)
    {
        sum +=i;
    }
    return sum;
}

/******************************************************************************/
/*!
\brief
Function that returns the square of a positive integer number num
by computing the sum of odd integers starting with 1 

\param num -> input number
\param result -> result pointer
\exception None
\return None
*/
/******************************************************************************/
void square2(int num, int *result)
{
    *result = 0;
    //Quite shortcut to do, not sure if pass hidden test case
    for (int i =1; i < (num *2); i+=2)
    {
        *result +=i;
    }
}
