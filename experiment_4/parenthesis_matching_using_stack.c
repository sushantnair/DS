#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct stack
{
    char st[MAX];
    int top;
}st_v;
void push(char elem)
{
    if(st_v.top == (MAX - 1))
        printf("\nStack Overflow!");
    else
    {
        st_v.top = st_v.top + 1;
        st_v.st[st_v.top] = elem; 
    }
}
void pop()
{
    if(st_v.top == -1)
        printf("\nStack Underflow!");
    else
        st_v.top = st_v.top - 1;
}
void main()
{
    char stk[MAX], ch;
    int i = 0;
    st_v.top = -1;
    printf("\nPARENTHESIS\tMATCHING\tALGORITHM");
    do
    {
        printf("\nNote: The expression must be a maximum of 100 characters including whitespace ");
        printf("\nEnter the expression: ");
        scanf("%s", stk);
        for(i = 0; i < strlen(stk); i++)
        {
            if(stk[i] == '(' || stk[i] == '[' || stk[i] == '{')
            {
                push(stk[i]);
                continue;
            }
            else if(stk[i] == ')' || stk[i] == ']' || stk[i] == '}')
            {
                if(stk[i] == ')')
                {
                    if(st_v.st[st_v.top] == '(')
                    {
                        pop();
                    }
                    else
                    {
                        printf("\nThe expression is unbalanced.");
                        break;
                    }
                }
                if(stk[i] == ']')
                {
                    if(st_v.st[st_v.top] == '[')
                    {
                        pop();
                    }
                    else
                    {
                        printf("\nThe expression is unbalanced.");
                        break;
                    }
                }
                if(stk[i] == '}')
                {
                    if(st_v.st[st_v.top] == '{')
                    {
                        pop();
                    }
                    else
                    {
                        printf("The expression is unbalanced.");
                        break;
                    }
                }
            }
        }
        if(st_v.top == -1)
            printf("\nThe expression is balanced.");
        printf("\nDo you want to try for another expression?\nIn that case, enter 'Y', otherwise enter\nany other character: ");
        scanf("%s", &ch);
    }while(ch=='Y');
}
