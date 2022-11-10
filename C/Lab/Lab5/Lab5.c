//
//  Lab5.c
//  SC1003LabTuts
//
//  Created by Isaac Chun on 23/10/22.
//
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[20];
    int telno;
} PhoneBk;

void printPB(PhoneBk* pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char * target);

int main()
{
    PhoneBk s[MAX];
    char t[20], *p;
    int size = 0, choice;
    char dummyChar;
    
    printf("Select one of the following options: \n");
    printf("1: readin()\n");
    printf("2: search()\n");
    printf("3: printPB()\n");
    printf("4: exit()\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                scanf("%c", &dummyChar);
                size = readin(s);
                break;
            case 2:
                scanf("%c", &dummyChar);
                printf("Enter search name: \n");
                fgets(t,20,stdin);
                if((p=strchr(t,'\n')))
                   *p = '\0';
                search(s,size,t);
                break;
            case 3:
                printPB(s, size);
                break;
        }
    } while (choice < 4);
    
    return 0;
}

void printPB(PhoneBk* pb, int size)
{
    printf("The phonebook list:\n");
    if(size == 0)
    {
        printf("Empty phonebook\n");
        return;
    }
    int i;
    for (i =0; i < size; ++i)
    {
        printf("Name: %s\n", pb[i].name);
        printf("Telno: %d\n", pb[i].telno);
    }
}

int readin(PhoneBk *pb)
{
    int count = 0;
    while (1)
    {
        char name[20], *p;
        int tel;
        printf("Enter name:\n");
        scanf("\n");
        fgets(name, 20, stdin);
        if((p = strchr(name, '\n')))
            *p = '\0';
        
        if(strcmp(name, "#\0") == 0)
            break;
        
        //Else, we store numbers
        printf("Enter tel:\n");
        scanf("%d", &tel);
        
        //And finally we store in the phonebook
        strcpy(pb[count].name,name);
        pb[count].telno = tel;
        count++;
    }
    return count;
}

void search(PhoneBk *pb, int size, char * target)
{
    //Conduct search
    int i;
    for (i =0; i < size; ++i)
    {
        if(strcmp(pb[i].name, target) == 0)
        {
            printf("Name = %s, Tel = %d\n", pb[i].name, pb[i].telno);
            return;
        }
    }
    //Else we print name not found
    printf("Name not found!\n");
}