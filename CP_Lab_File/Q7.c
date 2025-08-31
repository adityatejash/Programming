// Q7 Write a program in C to make a pyramid pattern with numbers increased by 1.

#include <stdio.h>

int main()
{
    int r;
    printf("Enter Rows: ");
    scanf("%d",&r);
    int a=r*(r+1)/2;
    int A[a];
    for (int i=0;i<a;i++)
        A[i]=i+1;
    int t=0;
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<=i;j++)
        {
            printf("%d ",A[t]);
            t++;
        }
        printf("\n");
    }
}