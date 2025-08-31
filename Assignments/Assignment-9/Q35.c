// Q35. Write a C program generate permutations.
#include <stdio.h>
int factorial(int n)
{
    int f=1;
    for (int i=n;i>=2;i--)
        f=f*i;
}
int main()
{
    int n,r;
    printf("Enter the value of 'n' and 'r' nPr: ");
    scanf("%d %d",&n,&r);
    printf("nPr for %dP%d is %d.",n,r,factorial(n)/factorial(n-r));
}