//
//  computeNetPay.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>

int main()
{
   //Basic pay is 6
    //over time pay in excess of 40 hours is 1.5 times basic pay.
    //Tax rate of first 1000 of gross pay, 20 % of next 500, and then 30% of the rest.
    
    //Just some placeholder cause i lazy #define
    int noWork;
    float basicPay = 6.0f;
    float grossPay = 0;
    float tax = 0;
    printf("Enter hours of work:\n");
    scanf("%d", &noWork);
    
    //First we check if the no of work is above 40 to know if we need to subtract or minus
    
    if (noWork > 40)
    {
        grossPay += 40 * basicPay;
        noWork -= 40;
        grossPay += noWork * (basicPay * 1.5f);
    }
    else
    {
        //less than 40
        grossPay += noWork * basicPay;
    }
    
    //Then we figure out taxes
    if (grossPay >= 1500.0f)
    {
        //We have to cut 30, 20 then 10
        //Take - 1500 to count how much to tax
        //This is the first 30 percent cut.
        grossPay -= (grossPay - 1500.0f) * 0.3f;
    }
    
    //Regardless, we have a 10% tax.
    tax += (grossPay * 0.1f);
    //Check if above 1000
    if (grossPay > 1000.0f)
    {
        //Cut 20
        tax += (grossPay * 0.2f);
        //Then we check for 30
        if (grossPay > 1500.0f)// means initial amount was already more so weh ave to cut more
        {
            tax += (grossPay * 0.3f);
        }
    }
    
    printf("Gross pay=%.2f\n", grossPay);
    printf("Tax=%.2f\n", tax);
    printf("Net pay=%.2f\n", grossPay - tax);
    return 0;
}
