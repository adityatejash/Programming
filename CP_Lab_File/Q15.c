// Q15. Write a program to find out the second largest factor of a number. Eg. Input->100, Output-> 50.

#include <stdio.h>

int main()
{
    int n,index=0;
    printf("Enter Number: ");
    scanf("%d",&n);
    int A[n/2];
    for (int i=1;i<=n;i++)
    {
        if (n%i == 0)
        {
            A[index]=i;
            index++;
        }   
    }
    printf("Second largest Factor of %d is %d.",n,A[index-2]);
}