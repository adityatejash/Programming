// Q13. Write C program to convert binary to hexadecimal & vice versa

#include <stdio.h>
#include <math.h>

int Binary_to_Decimal(int x)
{
    int A[32],i=0,s=0;
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

int Decimal_to_Binary(int x)
{
    int A[64],i=0;
    if (x==0)
        return 0;
    while (x>0)
    {
        A[i]=x%2;
        x/=2;
        i++;
    }
    for (int j=i-1;j>=0;j--)
        printf("%d",A[j]);
}

int main()
{
    int c,n;
    printf("Enter\n1. for Binary to Hexadecimal, or\n2. Hexadecimal to Binary: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        {
            printf("Enter Binary Number: ");
            scanf("%d",&n);
            int d=Binary_to_Decimal(n);
            printf("Binary: %d --> Hexadecimal: %X\n",d,d);
            break;
        }
        case 2:
        {
            char A[16],B[32];
            printf("Enter Hexadecimal Number: ");
            scanf("%s",&A);
            sscanf(A,"%X",&n);
            printf("Hexadecimal: %s --> Binary: ",A);
            Decimal_to_Binary(n);
            break;
        }
    }
}