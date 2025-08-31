// Q21. Write a C program to generate fibonacci numbers and to find out if a given number is a fibonacci number or not.

#include <stdio.h>
int main()
{
    int n,c=0,t;
    printf("Enter Number of terms of Fibonacci Series: ");
    scanf("%d",&t);
    int A[t];
    A[0]=0,A[1]=1;
    for (int i=2;i<t;i++)
        A[i] = A[i-1]+A[i-2];
    printf("Fibonacci Series: ");
    for (int i=0;i<t;i++)
        printf("%d ",A[i]);
    printf("\nEnter Number to Search in fibonacci Series: ");
    scanf("%d",&n);
    for (int i=0;i<t;i++)
    {
        if (n == A[i])
        {
            printf("%d is a Fibonacci Number.",n);
            c++;
            break;
        }
    }
    if (c == 0)
        printf("%d is not a Fibonacci Number.",n);
    return 0;
}