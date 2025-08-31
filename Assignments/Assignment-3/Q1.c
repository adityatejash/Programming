// Q1.  Write a C program for printing prime factors of a number using functions.

#include <stdio.h>

int prime_number(int x)
{
    for (int i=2;i<x;i++)
    {
        if (x%i==0)
            return 0;
        else if (i+1==x)
            return x;
    }
}
int main()
{
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("Prime Factors: ");
    for (int i=2;i<=n;i++)
    {
        if (n%i==0 && prime_number(i))
            printf("%d ",i);
    }
    return 0;
}
