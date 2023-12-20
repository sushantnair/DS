#include<stdio.h>
#include<stdlib.h>
void create();
void insert();
void Delete();
void traverse();
void search();
int del_el, i, ser_el, flag;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL;
void main()
{
    int ch;
    do
    {
        printf("\nEnter:\n'1' to create a node.\n'2' to insert an element.\n'3' to delete a node.\n'4' to traverse through the linked list.\n'5' to search for an element.\n'6' to exit from the program.\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                create();
            break;
            case 2:
                insert();
            break;
            case 3:
                Delete();
            break;
            case 4:
                traverse();
            break;
            case 5:
                search();
            break;
            case 6:
                printf("\nE\tX\tI\tT\tI\tN\tG\t.\t.\t.");
            break;
            default:
                printf("\nOnly '1', '2', '3', '4', '5' and '6' are allowed as inputs. Try again!");
            break;
        }
    }while(ch!=6);
}
void create()
{
    struct Node *temp, *ptr;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the element for the new node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if(start==NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> next = temp;
    }
}
void insert()
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the element for the node to be inserted: ");
    scanf("%d", &temp -> data);
    temp -> next = NULL;
    if(start==NULL)
    {
        start = temp;
    }
    else
    {
        temp -> next = start;
        start = temp;
    }
}
void Delete()
{
    struct Node *temp, *ptr;
    printf("\nEnter the location of the element to be deleted: ");
    scanf("%d", &del_el);
    if(del_el==0)
    {
        ptr = start;
        start = start -> next;
        printf("\nThe node deleted is: %d", ptr->data);
        free(ptr);
    }
    else
    {
        ptr = start;
        for(i = 0; i < del_el; i++)
        {
            temp = ptr;
            ptr = ptr -> next;
        }
        temp -> next = ptr -> next;
        printf("\nThe node deleted is: %d", ptr->data);
        free(ptr);
    }
}
void traverse()
{
    struct Node *temp;
    if(start==NULL)
    {
        printf("\nEmpty List!");
    }
    else
    {
        temp = start;
        printf("\n");
        while(temp != NULL)
        {
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }
    }
}
void search()
{
    struct Node *temp;
    temp = start;
    if(start==NULL)
    {
        printf("\nEmpty List!");
    }
    else
    {
        printf("\nEnter the element to be searched: ");
        scanf("%d", &ser_el);
        while(temp!=NULL)
        {
            if(temp->data==ser_el)
            {
                printf("\nElement found at location %d.", (i+1));
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
            temp = temp -> next;
            i++;
        }
        if(flag==1)
            printf("\nThe search was successful.");
        else
            printf("\nThe search was unsuccessful.");
    }
}
