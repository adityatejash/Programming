// Q9. Write a program in C to display a pattern like a diamond.

#include <stdio.h>

int main() 
{
    int rows;

    printf("Enter the number of rows (odd number): ");
    scanf("%d",&rows);
    int mid=(rows+1)/2; 
    for (int i=1;i<=mid;i++) 
    {
        for (int j=1;j<= mid-i;j++) 
            printf(" "); 
        for (int j= 1;j<=2*i-1;j++) 
            printf("*"); 
        printf("\n");
    }
    for (int i= mid-1;i>=1;i--) 
    {
        for (int j=1;j<=mid-i;j++)
            printf(" "); 
        for (int j=1;j<=2*i-1;j++)
            printf("*"); 
        printf("\n");
    }
    return 0;
}
