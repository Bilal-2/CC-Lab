#include<stdio.h>
#include<conio.h>
#include<string.h>

char input[100];
int i = 0;

int call();
int optp();
int param();
int pp();

int main()
{
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\ncall->id(optparam)\noptparam->param|@\nparam->paramP'\nP'->,paramP'|@\n");
    printf("\nEnter the string to be checked:");
    gets(input);
    if(call() && input[i] == '\0') {

        printf("\nString is accepted\n");
    } 
    else {
        printf("\nString is not accepted\n");
    }
    getch();
}

int call()
{
    if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        if(input[i] == '(')
        {
            i++;
            if(optp())
            {
                if(input[i] == ')')
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int optp()
{
    if(input[i] == ')')
    {
        i++;
        return 1;
    }
    else if(param())
    {
        if(pp())
        {
            return 1;
        }
    }
    return 0;
}

int param()
{
    if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        if(pp())
        {
            return 1;
        }
    }
    return 0;
}

int pp()
{
    if(input[i] == ',')
    {
        i++;
        if(param())
        {
            if(pp())
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}
