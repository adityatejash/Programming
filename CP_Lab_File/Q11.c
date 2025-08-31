// Q11. Write a program in C to check whether a number can be expressed as the sum of two prime numbers

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
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int a =n/2;
    for (int i=2;i<=a;i++) 
    {
        if (prime_number(i) && prime_number(n-i)) 
            printf("%d = %d + %d\n",n,i,n-i);
    }
    return 0;
}