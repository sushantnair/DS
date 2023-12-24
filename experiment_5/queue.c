#include<stdio.h>
#include<stdlib.h>
struct qnode
{
    int qdata;
    struct qnode *next;
};
struct qnode *front, *rear;
int max_cap, cur_cap = 0;
void create();
void enqueue();
void dequeue();
void display();
void main()
{
    int ch;
    printf("\nQUEUE\tIMPLEMENTATION\tIN\tC");
    printf("\nEnter the maximum capacity of the queue: ");
    scanf("%d", &max_cap);
    printf("\nDuring the start, enter option '1' to create the queue.\nHenceforth during the operation, don't press '1' again.");
    do
    {
        printf("\nEnter\n'1' to create a queue.\n'2' to insert an element at the rear.\n'3' to delete an element from the front.\n'4' to display the queue in FIFO order.\n'5' to exit.\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                enqueue();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nE\tX\tI\tT\tI\tN\tG\t.\t.\t.");
                break;
            default:
                printf("\nPlease enter '1', '2', '3', '4' or '5' only and try again!");
        }
    }while(ch!=5);
}
void create()
{
    front = NULL;
    rear = NULL;
}
void enqueue()
{
    struct qnode *temp;
    temp = (struct qnode*)malloc(sizeof(struct qnode));
    printf("\nEnter data for the new node: ");
    scanf("%d", &temp -> qdata);
    temp -> next = NULL;
    if(cur_cap == max_cap)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        if(front == NULL)
        {
            front = temp;
            rear = temp;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else
        {
            rear -> next = temp;
            rear = temp;
            rear -> next = NULL;
        }
        cur_cap++;
    }
}
void dequeue()
{
    struct qnode *ptr;
    if(front == NULL)
    {
        printf("\nQueue Underflow!");
    }
    else
    {
        ptr = front;
        front = front -> next;
        printf("\nThe deleted element is %d.", ptr->qdata);
        free(ptr);
        cur_cap--;
    }
}
void display()
{
    struct qnode *ptr;
    if(front == NULL)
    {
        printf("\nQueue Underflow!");
    }
    else
    {
        ptr = front;
        while(ptr != NULL)
        {
            printf("\t%d", ptr->qdata);
            ptr = ptr -> next;
        }
    }
}
