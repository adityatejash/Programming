// Q8. Write a program in C to print Floyd's Triangle.

#include <stdio.h>

int main()
{
    int r;
    printf("Enter number of rows: ");
    scanf("%d",&r);
    for (int i=1;i<=r;i++)
    {   
        int s=i%2;
        for (int j=1;j<=i;j++)
        {
            printf("%d ",s);
            s=1-s;
        }
        printf("\n");
    }
}