#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;
void insert();
void delete();
void display();
void search();
void main()
{
    int ch;
    printf("\nDOUBLY\tLINKED\tLIST\tIMPLEMENTATION\n");
    do
    {
        printf("\nEnter:\n'1' to insert a node.\n'2' to delete a node.\n'3' to display the list.\n'4' to search for a node.\n'5' to exit.\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                insert();
            break;
            case 2:
                delete();
            break;
            case 3:
                display();
            break;
            case 4:
                search();
            break;
            case 5:
                printf("\nE\tX\tI\tT\tI\tN\tG\t.\t.\t.");
            break;
            default:
                printf("\nPlease enter '1', '2', '3', '4' or '5' only and try again!");
        }
    }while(ch!=5);
}
void insert()
{
    struct Node *temp, *ptr;
    temp = (struct Node*)malloc(sizeof(struct Node));
    int pos, locn;
    printf("\nEnter the data for the new node: ");
    scanf("%d", &temp -> data);
    temp -> next = NULL;
    temp -> prev = NULL;
    printf("\nEnter:\n'1' to insert at beginning.\n'2' to insert at end.\n'3' to insert in between.\nEnter your choice: ");
    scanf("%d", &pos);
    if(temp == NULL)
    {
        printf("\nMemory allocation has been unsuccessful.");
    }
    else if(pos == 1)
    {
        if(head == NULL)
        {
            temp -> next = NULL;
            temp -> prev = NULL;
            head = temp;
        }
        else
        {
            temp -> prev = NULL;
            temp -> next = head;
            head -> prev = temp;
            head = temp;
        }
        printf("\nInsertion Successful!");
    }
    else if(pos == 2)
    {
        if(head == NULL)
        {
            temp -> prev = NULL;
            temp -> next = NULL;
            head = temp;
        }
        else
        {
            ptr = head;
            while(ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
            ptr -> next = temp;
            temp -> prev = ptr;
            temp -> next = NULL;
        }
        printf("\nInsertion Successful!");
    }
    else if(pos == 3)
    {
        printf("\nEnter the location for insertion: ");
        scanf("%d", &locn);
        ptr = head;
        for(int i = 0; i < locn; i++)
        {
            ptr = ptr -> next;
            if(ptr == NULL)
            {
                printf("\nInsertion Unsuccessful.");
                return;
            }
        }
        temp -> next = ptr -> next;
        temp -> prev = ptr;
        ptr -> next = temp;
        ptr -> next -> prev = temp;
        printf("\nInsertion Successful!");
    }
}
void delete()
{
    struct Node *ptr, *ptr1;
    int pos, locn;
    printf("\nEnter:\n'1' to delete at beginning.\n'2' to delete at end.\n'3' to delete in between.\nEnter your choice: ");
    scanf("%d", &pos);
    if(head == NULL)
    {
        printf("\nUnderflow!");
    }
    if(pos == 1)
    {
        if(head -> next == NULL)
        {
            printf("\nThe deleted node is %d.", head -> data);
            free(head);
        }
        else
        {
            ptr = head;
            head = head -> next;
            head -> prev = NULL;
            printf("\nThe deleted node is %d.", ptr -> data);
            free(ptr);
        }
    }
    else if(pos == 2)
    {
        if(head -> next == NULL)
        {
            printf("\nThe deleted node is %d.", head -> data);
            free(head);
        }
        else
        {
            ptr = head;
            while(ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
            ptr -> prev = NULL;
            ptr -> next = NULL;
            printf("\nThe deleted node is %d.", ptr -> data);
            free(ptr);
        }
    }
    else if(pos == 3)
    {
        int deldata;
        printf("\nEnter the data after which the node should be deleted: ");
        scanf("%d", &deldata);
        ptr = head;
        while(ptr -> data != deldata)
            ptr = ptr -> next;
        if(ptr -> next == NULL)
            printf("\nDeletion Unsuccessful.");
        else if(ptr -> next -> next == NULL)
            ptr -> next = NULL;
        else
        {
            ptr1 = ptr -> next;
            ptr -> next = ptr1 -> next;
            ptr1 -> next -> prev = ptr;
            printf("\nThe deleted node is %d.", ptr1 -> data);
            free(ptr1);
        }
    }
}
void search()
{
    struct Node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nUnderflow!");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
                break;
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
}
void display()
{
    struct Node *ptr;
    ptr = head;
    if(head == NULL)
    {
        printf("\nUnderflow!");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d\n", ptr -> data);
            ptr = ptr -> next;
        }
    }
}
