// Q29. Write a C program to convert a decimal number into a binary number.
#include <stdio.h>
int main()
{
    int n,length=0;
    printf("Enter Decimal Number: ");
    scanf("%d",&n);
    int original_number=n,binary=0,reversed_binary=0;
    while(n > 0)
    {
        int remainder=n%2;
        reversed_binary = reversed_binary * 10 + remainder;
        n/=2;
    }
    while (reversed_binary > 0)
    {   
        int remainder = reversed_binary%10;
        binary = binary * 10 + remainder;
        reversed_binary/=10;
    }
    printf("Decimal: %d --> Binary: %d\n",original_number,binary);
} 