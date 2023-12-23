#include<stdio.h>
char stack[100];
int top = -1;
void push(char x)
{
        stack[++top] = x;
}
char pop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int priority(char elem)
{
    if(elem == '(')
        return 0;
    else if(elem == '+' || elem == '-')
        return 1;
    else if(elem == '*' || elem == '/')
        return 2;
    return 0;
}
int main()
{
    char stk[100], ch;
    char *e, x;
    printf("\nINFIX\tTO\tPOSTFIX\tALGORITHM");
    do
    {
        printf("\nNote: The maximum number of characters in the expression\nincluding whitespace, cannot be greater than 100.");
        printf("\nEnter the infix expression: ");
        scanf("%s", stk);
        printf("\n");
        e = stk;
        while(*e != '\0')
        {
            if(isalnum(*e))
                printf("%c", *e);
            else if(*e == '(')
                push(*e);
            else if(*e == ')')
            {
                while((x = pop()) != '(')
                    printf("%c", x);
            }
            else
            {
                while(priority(stack[top]) >= priority(*e))
                    printf("%c", pop());
                push(*e);
            }
            e++;
        }
        while(top != -1)
            printf("%c", pop());
        printf("\nDo you want to try for another expression?\nIn that case, enter 'Y', otherwise enter\nany other character: ");
        scanf("%s", &ch);
    }while(ch=='Y');
    return 0;
}
