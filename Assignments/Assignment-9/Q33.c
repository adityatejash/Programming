// Q33. How can we sum the digits of a given number in single statement.
#include <stdio.h>
int main()
{
    int a,s=0;
    printf("Enter Number: ");
    scanf("%d",&a);
    int n=a;
    for(; n>0; s+=n%10, n/=10);
    printf("The sum of digits of number %d is %d.\n",a,s);
    return 0;
}