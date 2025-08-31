// Q27. Write a C program to multiply two matrices.

#include <stdio.h>
int main()
{
    int r1,r2,c1,c2;
    printf("Enter Rows and Columns of First Matrix: ");
    scanf("%d %d",&r1,&c1);
    int A[r1][c1];
    // Insert Elements of First Matrix.
    for (int i=0;i<r1;i++)
    {
        for (int j=0;j<c1;j++)
        {
            printf("Enter Element %d%d: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    // Printing Element of First Matrix
    printf("Element of First Matrix %dx%d are: \n",r1,c1);
    for (int i=0;i<r1;i++)
    {
        for (int j=0;j<c1;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
    printf("Enter Rows and Columns of Second Matrix: ");
    scanf("%d %d",&r2,&c2);
    int B[r2][c2];
    // Insert Elements of Second Matrix.
    for (int i=0;i<r2;i++)
    {
        for (int j=0;j<c2;j++)
        {
            printf("Enter Element %d%d: ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    // Printing Element of First Matrix
    printf("Element of Second Matrix %dx%d are: \n",r2,c2);
    for (int i=0;i<r2;i++)
    {
        for (int j=0;j<c2;j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }
    int result[r1][c2];
    // Checking if Matrix multiplication is possible or not.
    if (c1 != r2)
    {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }
    else
    {
        // Matrix Multiplication
        for (int i=0;i<r1;i++)
        {
            for (int j=0;j<c1;j++)
            {
                result[i][j]=0;
                for (int k=0;k<c1;k++)
                    result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Printing resultant Matrix
    printf("Element of Resultant Matrix %dx%d are: \n",r1,c2);
    for(int i=0;i<r1;i++)
    {
        for (int j=0;j<c2;j++)
            printf("%d ",result[i][j]);
        printf("\n");
    }
    return 0;
}