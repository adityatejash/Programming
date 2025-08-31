// Q28. Write a C program to check for palindromes.
#include <stdio.h>
void check_palindrome(int number)
{
    int original_number = number;
    int reversed=0;
    while (number > 0)
    {
        int remainder = number%10;
        reversed = reversed * 10 + remainder;
        number/=10;
    }
    if (original_number == reversed)
        printf("Yes!! %d is a Palindrome.\n",original_number);
    else
        printf("No!! %d is NOT a Palindrome.\n",original_number);
}
int main()
{
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    check_palindrome(n);
    return 0;
}