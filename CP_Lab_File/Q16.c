// Q16. Write C Program to Find the Largest Element in an Array.

#include <stdio.h>

int main()
{
    int n;
    printf("Enter Size of an Array: ");
    scanf("%d",&n);
    int A[n];
    for (int i=0;i<n;i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    int t;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (A[i] < A[j])
            {
                t=A[i];
                A[i]=A[j];
                A[j]=t;
            }
        }
    }
    printf("The Largest Element in Array is %d.",A[0]);
}