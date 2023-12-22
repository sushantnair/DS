#include<stdio.h>
int st[100], n, e, ch, top;
void create(void);
void push(void);
void pop(void);
void peep(void);
void display(void);
void main()
{
    printf("Enter the number of elements in the stack which is less than or equal to 100: ");
    scanf("%d", &n);
    do
    {
        printf("\nEnter:\n\t'1' to create (use this option only once in the beginning).\n\t'2' to push an element.\n\t'3' to pop an element.\n\t'4' to peep an element.\n\t'5' to display the stack.\n\t'6' to exit from the program.\n\tEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                create();
            break;
            case 2:
                push();
            break;
            case 3:
                pop();
            break;
            case 4:
                peep();
            break;
            case 5:
                display();
            break;
            case 6:
                printf("\nE\tX\tI\tT\tI\tN\tG\t.\t.\t.");
            break;
            default:
                printf("\nEnter either '1', '2', '3', '4', '5' or '6' only and try again!");
        }
    }while(ch!=6);
}
void create()
{
    top = -1;
    printf("\nStack has been created. Now choose another option and don't choose\noption '1' again during the remainder course of the program.");
}
void push()
{
    if(top >= n-1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        printf("\nEnter element to push into stack: ");
        scanf("%d", &e);
        top++;
        st[top] = e;
        printf("\nPush successful.");
    }
}
void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nThe element popped is %d.", st[top]);
        top--;
    }
}
void peep()
{
    if(top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nThe element at top position of stack is %d.", st[top]);
    }
}
void display()
{
    if(top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        for(int i = top; i >= 0; i--)
        {
            printf("\nThe element at position %d is %d.", (i+1), st[i]);
        }
    }
}
