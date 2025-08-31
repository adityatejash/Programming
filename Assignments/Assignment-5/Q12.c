// Q12. Write a C program to check whether a number is a Armstrong Number or not.

#include <stdio.h>
#include <math.h>

int length(int x)
{
    int len =0;
    while (x>0)
    {
        x=x/10;
        len++;
    }
    return len;
}

void Armstrong_Number(int x)
{
    int l=length(x);
    int A[l],s=0,a=x;
    while (a>0)
    {
        int r=a%10;
        s=s+round(pow(r,l));
        a/=10;
    }
    if (s==x)
        printf("Number %d is an Armstrong Number.\n",x);
    else
        printf("Number %d is NOT an Armstrong Number.\n",x);
}

int main()
{
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    Armstrong_Number(n);
    return 0;
}