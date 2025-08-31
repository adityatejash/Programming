// Q19. Write a C Program to find all pairs in array of integers whose sum is equal to given number. 
#include <stdio.h>
int main()
{
    int a;
    printf("Enter size of an array: ");
    scanf("%d",&a);
    int A[a];
    for (int i=0;i<a;i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    int n,c=0;
    printf("Enter Element Number: ");
    scanf("%d",&n);
    for (int i=0;i<a;i++)
    {
        for (int j=i+1;j<a;j++)
        {
            if (n == A[i]+A[j])
            {
                printf("The pair whose sum is %d are %d and %d.\n",n,A[i],A[j]);
                c++;
            }
        }
    }
    if (c == 0)
        printf("No pairs found.");
    return 0;
}