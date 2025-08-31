// Q18. Write C Program to Search an Element in an Array (Binary search)

#include <stdio.h>

int main()
{
    int a,b,t;
    printf("Enter Size of Array: ");
    scanf("%d",&a);
    int A[a];
    for (int i=0;i<a;i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    printf("Enter Number to search: ");
    scanf("%d",&b);
    int found=0;
    for (int i=0;i<a;i++)
    {
        if (b==A[i])
        { 
            printf("Element %d Found at Index %d.\n",b,i);
            found=1;
        }
    }
    if (!found)
        printf("Element %d NOT Found.",b);
}