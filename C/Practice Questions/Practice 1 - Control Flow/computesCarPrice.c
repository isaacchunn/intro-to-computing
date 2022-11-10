//
//  computesCarPrice.c
//  Codes here are indicative and not exhaustive. There will definitely be better codes out there.
//
//  Created by Isaac Chun on 8/10/22.
//

#include <stdio.h>

int main()
{
    float listPrice, tax = 0;
    int category;
    printf("Please enter the list price:\n");
    scanf("%f", &listPrice);
    printf("Please enter the category:\n");
    scanf("%d", &category);
    
    //ASsuming that the car dealer gives a discount,
    //And that taxes are computed based on the discounted price,
    listPrice  *= 0.9f; //10 percent discount
    
    //Do conditional for list price
    tax += listPrice > 100000 ? listPrice * 0.1f : 0;
    tax += listPrice * 0.03f; //gst 3% tax
    
    //Based off category, we switch
    switch(category)
    {
        case 1:
            tax += 70000;
            break;
        case 2:
            tax += 80000;
            break;
        case 3:
            tax += 23000;
            break;
        case 4:
            tax += 600;
            break;
    }
    
    //Display total price.
    printf("Total price is $%.2f\n", tax+listPrice);
    return 0;
}
