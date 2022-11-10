//
//  Tutorial5Q2.c
//  SC1003LabTuts
//
//  Created by Isaac Chun on 23/10/22.
//

#include <stdio.h>
#define INIT_VALUE 1000

typedef struct
{
    int id;             //Staff Identifier
    int totalLeave;     //The total number of days of leave allowed
    int leaveTaken;     //The number of days of leave tkaen so far
} leaveRecord;

int mayTakeLeave(leaveRecord list[], int id, int leave, int n);
void getInput(leaveRecord list[], int *n);
void printList(leaveRecord list[], int n);

int main()
{
    leaveRecord listRec[10];
    int len;
    int id, leave, canTake = INIT_VALUE;
    int choice;
    
    printf("Select one of the following options: \n");
    printf("1: getInput()\n");
    printf("2: printList()\n");
    printf("3: mayTakeLeave()\n");
    printf("4: exit()\n");
    do
    {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                getInput(listRec, &len);
                printList(listRec, len);
                break;
            case 2:
                printList(listRec, len);
                break;
            case 3:
                printf("Please input id, leave to be taken: \n");
                scanf("%d %d", &id, &leave);
                canTake = mayTakeLeave(listRec, id, leave, len);
                if (canTake == 1)
                    printf("The staff %d can take leave\n", id);
                else if (canTake == 0)
                    printf("The staff %d cannot take leave\n", id);
                else if (canTake == -1)
                    printf("The staff %d is not in the list\n", id);
                else
                    printf("Error!");
                break;
        }
    } while(choice < 4);
    
    return 0;
}

void printList(leaveRecord list[], int n)
{
    int p;
    
    printf("The staff list:\n");
    for (p =0; p < n; p++)
    {
        printf("id = %d, totalleave = %d, leave taken =%d \n", list[p].id, list[p].totalLeave, list[p].leaveTaken);
    }
}

void getInput(leaveRecord list[], int * n)
{
    int staffCount;
    int id, totalleave, leavetaken, i;
    printf("Enter the number of staff records:\n");
    scanf("%d", &staffCount);
    for (i =0; i < staffCount; ++i)
    {
        printf("Enter id, totalleave, leavetaken:\n");
        //Scan all the other inputs into the respective data
        scanf("%d %d %d", &id, &totalleave, &leavetaken);
        //Store the data into the list at respective index
        list[i].id = id;
        list[i].leaveTaken = leavetaken;
        list[i].totalLeave = totalleave;
    }
    //Update total length variable.
    *n = staffCount;
}

int mayTakeLeave(leaveRecord list[], int id, int leave, int n)
{
    //Loop through the list to find whether staff existsd=
    int i;
    for (i =0; i < n; ++i)
    {
        if(list[i].id == id)
        {
            //Then we found a match.
            //We check if this staff member of id can take leave.
            //Then may take leave.
            return (list[i].leaveTaken + leave <= list[i].totalLeave);
        }
    }
    //Else no staff is found.
    return -1;
}
