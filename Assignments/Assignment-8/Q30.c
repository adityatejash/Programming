// Q30. Write a program to check, if a given year is a leap year or not.
#include <stdio.h>
int main()
{
    int n;
    printf("Enter Year: ");
    scanf("%d",&n);
    if ((n%400 == 0) || (n%4 == 0 && n%100 != 0))
        printf("Yes!! %d is a Leap Year.\n",n);
    else
        printf("No!! %d is NOT a Leap Year.\n",n);
}