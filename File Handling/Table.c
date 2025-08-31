// Table inserting in a file 
#include <stdio.h>

void main()
{
    FILE *p;
    int n;
    p = fopen("Table.txt","a");
    printf("Enter Number: ");
    scanf("%d",&n);
    int i=1;
    fprintf(p,"Table of %d is given below.\n",n);
    while (i<=10)
    {
        fprintf(p,"%d x %d = %d\n",n,i,n*i);
        i++;
    }
    fprintf(p,"\n");
    fclose(p);
}