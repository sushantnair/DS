#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void insert();
void delete();
void display();
void search();
void main()
{
    int ch;
    printf("\nCIRCULAR\tLINKED\tLIST\tIMPLEMENTATION\n");
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
            head = temp;
            temp -> next = head;
        }
        else
        {
            ptr = head;
            while(ptr -> next != head)
            {
                ptr = ptr -> next;
            }
            temp -> next = head;
            ptr -> next = temp;
            head = temp;
        }
        printf("\nInsertion Successful!");
    }
    else if(pos == 2)
    {
        if(head == NULL)
        {
            head = temp;
            temp -> next = head;
            printf("\nInsertion Successful!");
        }
        else
        {
            ptr = head;
            while(ptr -> next != head)
            {
                ptr = ptr -> next;
            }
            ptr -> next = temp;
            temp -> next = head;
            printf("\nInsertion Successful!");
        }
    }
    else if(pos == 3)
    {
        printf("\nEnter the location for insertion: ");
        scanf("%d", &locn);
        ptr = head;
        for(int i = 0; i < locn; i++)
        {
            ptr = ptr -> next;
            if(ptr == head)
            {
                printf("\nInsertion Unsuccessful.");
                return;
            }
        }
        temp -> next = ptr -> next;
        ptr -> next = temp;
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
        if(head -> next == head)
        {
            printf("\nThe deleted node is %d.", head -> data);
            free(head);
        }
        else
        {
            ptr = head;
            while(ptr -> next != head)
            {
                ptr = ptr -> next;
            }
            ptr -> next = head -> next;
            printf("\nThe deleted node is %d.", head -> data);
            free(head);
            head = ptr -> next;
        }
    }
    else if(pos == 2)
    {
        if(head -> next == head)
        {
            printf("\nThe node deleted is %d.", head -> data);
            head = NULL;
            free(head);
        }
        else
        {
            ptr = head;
            while(ptr -> next != head)
            {
                ptr1 = ptr;
                ptr = ptr -> next;
            }
            ptr1 -> next = ptr -> next;
            printf("\nThe node deleted is %d.", ptr -> data);
            free(ptr);
        }
    }
    else if(pos == 3)
    {
        printf("\nEnter the location of deletion: ");
        scanf("%d", &locn);
        ptr = head;
        for(int i = 0; i < locn; i++)
        {
            ptr1 = ptr;
            ptr = ptr -> next;
            if(ptr == head)
            {
                printf("\nDeletion Unsuccessful.");
                return;
            }
        }
        printf("\nThe node deleted is %d.", ptr -> data);
        ptr1 -> next =  ptr -> next;
        free(ptr);
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
        if(head -> data == item)
        {
            printf("item found at location %d ",i+1);  
            flag=0;
        }
        else
        {
            while (ptr -> next != head)  
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
        while(ptr -> next != head)
        {
            printf("%d\n", ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d\n", ptr -> data);
    }
}
