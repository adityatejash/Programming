// Q22. Write C programs to check, if an integer is a power of 2 or not in a single line.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("%d is %s a power if 2.\n",n,(n>0 && (n & (n-1)) == 0 ) ? "" : "not" );
    return 0;
}