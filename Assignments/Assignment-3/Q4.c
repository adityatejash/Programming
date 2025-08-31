// Q4. Write a C program to convert octal to binary & vice versa.
#include <stdio.h>
#include <math.h>
void Decimal_to_Binary(int x)
{   
    int A[64],i=0;
    while(x>0)
    {
        A[i]=x%2;
        x/=2;
        i++;
    }
    for (int j=i-1;j>=0;j--)
        printf("%d",A[j]);
}
int Binary_to_Decimal(int x)
{
    int A[64],i=0,s=0;
    while (x>0)
    {
        A[i]=x%10;
        x/=10;
        if (A[i]==1)
            s+=A[i]*pow(2,i);
        i++;
    }
    return s;
}
int main()
{
    int c,n;
    printf("Enter\n1.for Octal to Binary, or\n2. for Binary to Octal: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        {
            char A[16];
            int d;
            printf("Enter Octal Number: ");
            scanf("%s",A);
            sscanf(A,"%o",&n);
            printf("Octal: %s --> Binary: ",A);
            Decimal_to_Binary(n);
            break;
        }
        case 2:
        {
            char A[16];
            printf("Enter Binary Number (only 0 and 1): ");
            scanf("%d",&n);
            int d=Binary_to_Decimal(n);
            sprintf(A,"%o",d);
            printf("Binary: %d --> Octal: %s",n,A);
            break;
        }
    }
}
