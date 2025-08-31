// Q6. Write a program in C to make such a pattern like a right angle triangle with a number, which will repeat a number in a row.

#include <stdio.h>

int main()
{
    int r;
    printf("Enter Rows: ");
    scanf("%d",&r);
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=i;j++)
            printf("%d",i);
        printf("\n");
    }
}
