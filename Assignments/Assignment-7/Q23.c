// Q23. Write code to remove duplicates in a sorted array.

#include <stdio.h>
int main()
{
    int A[] = {1,2,3,3,4,4,5,6,7,7}; //Sorted Array (increasing order)
    printf("Array before removing duplicates is: ");
    for (int i=0;i<10;i++)
        printf("%d ",A[i]);
    for (int i=0;i<10;i++)
    {
        for (int j=i+1;j<10;j++)
        {
            if (A[i] == A[j])
                A[j]=0;
        }
    }
    printf("\nArray after removing duplicates is: ");
    for (int i=0;i<10;i++)
    {
        if (A[i] != 0)
            printf("%d ",A[i]);
    }
}