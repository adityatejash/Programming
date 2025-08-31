// Q2. Write a C program for printing prime numbers between a interval. 
#include <stdio.h>
int prime_number(int x)
{
    for (int i=2;i<x;i++)
    {
        if (x%i == 0)
            return 0;
        else if (i+1 == x)
            return x;
    }
}
int main()
{
    int a,b;
    printf("Enter Starting Number: ");
    scanf("%d",&a);
    printf("Enter Ending Number: ");
    scanf("%d",&b);
    printf("Prime Numbers between %d and %d: ",a,b);
    if (a<2)
        a=2;
    for (int i=a;i<=b;i++)
    {
    int c=prime_number(i);
    if (c!=0)
        printf("%d ",i);
    }
    return 0;
}