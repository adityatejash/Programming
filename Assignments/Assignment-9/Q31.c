// Q31. Write your own sqrt function in C.
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("The Root of %d is %.3f.\n",n,pow(n,0.5));
}
