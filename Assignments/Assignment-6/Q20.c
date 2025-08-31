// Q20. Write a C program for calculating the factorial of a number.

#include <stdio.h>
int main()
{
    int n,f=1;
    printf("Enter Number: ");
    scanf("%d",&n);
    for (int i=n;i>=2;i--)
        f=f*i;
    printf("Factorial of %d is %d.",n,f);
    return 0;
}