#include <stdio.h>
#include <string.h>

void Read_File(FILE *p)
{
    char str[1000];
    while (fgets(str, sizeof(str), p))
    {
        printf("%s",str);
    }
}

void Write_File(FILE *p)
{
    char content[1000];
    int new_line = 0;
    while (fgets(content, sizeof(content), stdin))
    {
        if (content[0] == '\n')
        {
            new_line++;
            if (new_line == 2)
            {
                break;
            }
        }
        else
        {
            new_line = 0;
            fputs(content, p);
        }
    }
}

void choices()
{
    FILE *p = NULL;
    int n;
    char file_name[50];
    printf("Enter File Name (with file extention): ");
    scanf("%s",file_name);
    printf("Enter:\n1. Read File, or\n2. Write File, or\n3. Append File: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            p = fopen(file_name,"r");
            if (p != NULL)
            {   
                Read_File(p);
                fclose(p);
            }
            else 
            {
                printf("Error in opening file!!!\n");
            }
            getchar();
            break;
        }
        case 2:
        {
            p = fopen(file_name,"w");
            if (p != NULL)
            {   
                Write_File(p);
                fclose(p);
            }
            break;
        }
        case 3:
        {
            printf("3");
            //Append_File()
            break;
        }
    }
}
void main()
{
    int a;
    printf("Enter 0 to STOP or 1 for CASES........");
    scanf("%d",&a);
    while (a)
    {
        choices();
        printf("Enter 0 to STOP or 1 for CASES........");
        scanf("%d",&a);
    }
}