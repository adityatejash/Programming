// Q10.  Write a program in C to display a pattern like a diamond.

#include <stdio.h>

void printPascalsTriangle(int rows) 
{
    int arr[rows][rows]; 

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            if (j == 0 || j == i) 
                arr[i][j] = 1;
            else 
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]; 
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int space = 0; space < rows - i - 1; space++) 
            printf(" ");
        for (int j = 0; j <= i; j++) 
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);
    if (n <= 0)
        printf("Number of rows must be a positive integer.\n");
    else
        printPascalsTriangle(n);
    return 0;
}
