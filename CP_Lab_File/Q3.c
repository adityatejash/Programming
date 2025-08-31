// Q3. Write a C program to convert decimal to binary numbers & vice versa.

#include <stdio.h>
#include <math.h>

int Decimal_to_Binary(int x)
{
    int A[64],i=0;
    printf("Decimal: %d --> Binary: ",x);
    if (x == 0)
        printf("0");
    while (x>0)
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
    int A[128],i=0,s=0;
    printf("Binary: %d --> Decimal: ",x);
    while (x>0)
    {
        A[i]=x%10;
        x/=10;
        if (A[i] == 1)
            s+=A[i]*pow(2,i);
        i++;
        
    }
    printf("%d",s);
}

int main()
{
    int n,i;
    printf("Enter\n1. for Decimal To Binary, or\n2. for Binary to Decimal: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            printf("Enter Decimal Number: ");
            scanf("%d",&i);
            Decimal_to_Binary(i);
            break;
        }
        case 2:
        {
            printf("Enter Binary Number (Only 0 and 1): ");
            scanf("%d",&i);
            Binary_to_Decimal(i); 
            break;  
        }
        default:
        {
            printf("ERROR!! Enter from above choices.");
        }
    }
    return 0;
}