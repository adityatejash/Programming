// Q14. Write a program in C to find the number and sum of all integers between 100 and 200 which are divisible by 9.

#include <stdio.h>

int main()
{   
    int s=0;
    printf("Number divisible by 9 between 100 to 200 are: \n");
    for (int i=100;i<=200;i++)
    {
        if (i%9 == 0)
        {
            printf("%d ",i);
            s+=i;
        }
    }
    printf("\nSum: %d",s);
}