// Q25. Write C code to return a string from a function.
#include <stdio.h>
#include <string.h>
int function_string(char str[],int size)
{
    printf("Enter String: ");
    fgets(str,size,stdin);
}
int main()
{
    char str[100];
    function_string(str,sizeof(str));
    printf("Returned String is: %s",str);
}