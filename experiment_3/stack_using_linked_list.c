#include<stdio.h>
#include<stdlib.h>
int e, ch;
void create(void);
void push(void);
void pop(void);
void peep(void);
void display(void);
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
/*The stack is created in this line utself.
The create function is added just as a formality.
If the statement at line 14 is placed inside
the create function, then other methods cannot
access it.*/
void main()
{
    printf("\nAs this is Linked List implementation, there is no need to enter the total number of elements.");
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
    printf("\nStack has been created. Now choose another option and don't choose\noption '1' again during the remainder course of the program.");
}
void push()
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the element to push: ");
    scanf("%d", &temp -> data);
    temp -> next = NULL;
    if(top == NULL)
    {
        top = temp;
    }
    else
    {
        temp -> next = top;
        top = temp;
    }
    printf("\nPush successful.");
}
void pop()
{
    struct Node *temp;
    if(top == NULL)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        temp = top;
        printf("\nThe element popped is %d.", temp -> data);
        top = top -> next;
        free(temp);
        printf("\nPop successful.");
    }
}
void peep()
{
    if(top == NULL)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nThe element at top position is %d.", top -> data);
    }
}
void display()
{
    struct Node *temp;
    if(top == NULL)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        int i = 0;
        temp = top;
        while(temp!=NULL)
        {
            printf("\nThe element at position %d is %d.", (i+1), temp -> data);
            temp = temp -> next;
            i++;
        }
    }
}
