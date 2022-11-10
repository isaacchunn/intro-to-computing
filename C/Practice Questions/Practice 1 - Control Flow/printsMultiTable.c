int number, i , j;
    printf("Enter a number (between 1 and 9):\n");
    //Handle the inputs later...
    scanf("%d", &number);
    //Print the table
    printf("Multiplication Table:\n");
    
    //Print indexes
    putchar(' '); //Spacing for the table
    //Print most top, might combine later
    for (i =1; i <= number; ++i)
    {
        printf("%d ", i);
    }
    putchar('\n');
    //Now we do the real for loops
    for (i = 1; i <= number; ++i)
    {
        //Print the elem once
        printf("%d " ,i);
        for (j = 1; j <= i; ++j)
        {
            printf("%d ", i * j);
        }
        putchar('\n');
    }
    