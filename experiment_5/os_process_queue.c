#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int priority;
	char process_name[50];
	struct node *next;
};
struct node *front = NULL;
void insert();
void Delete();
void display();
void main()
{
	int choice;
	printf("\nLibrary of Process States for OS:\nState Name\tPriority\nReady\t\t1\nWaiting\t\t2\nNew\t\t3\nRunning\t\t4\nTerminated\t5\n");
	do
	{
		printf("\nEnter: '1' to insert a process.\n'2' to delete a process.\n'3' to display the sequence of processes.\n'4' to exit from the program.\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				Delete();
				break;
			case 3:
				display();
				break;
			case 4:
			    printf("\nE\tX\tI\tT\tI\tN\tG\t.\t.\t.");
			    break;
			default :
				printf("\nWrong choice");
		}
	}while(choice!=4);
}
void insert()
{
	struct node *temp,*ptr;
	char process_state[50];
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the name of the process to be added in the queue : ");
	scanf("%s", temp->process_name);
    	printf("Enter its state : ");
    	scanf("%s", process_state);
    	fflush(stdin);
    	if(strcmp(process_state, "Ready") == 0){
    	    temp -> priority = 1;
    	    fflush(stdin);
    	}
    	else if(strcmp(process_state, "Waiting") == 0){
    	    temp -> priority = 2;
    	    fflush(stdin);
    	}
    	else if(strcmp(process_state, "New") == 0){
    	    temp -> priority = 3;
    	    fflush(stdin);
    	}
    	else if(strcmp(process_state, "Running") == 0){
    	    temp -> priority = 4;
    	    fflush(stdin);
    	}
    	else if(strcmp(process_state, "Terminated") == 0){
    	    temp -> priority = 5;
    	    fflush(stdin);
    	}
    	else
    	{
    	    printf("\nAn unidentified process state has been entered. Please try again.");
    	    exit(0);
    	}
	if( front == NULL || temp->priority < front->priority )
	{
		temp->next = front;
		front = temp;
	}
	else
	{
		ptr = front;
		while( ptr->next != NULL && ptr->next->priority <= temp->priority )
			ptr=ptr->next;
		temp->next = ptr->next;
		ptr->next = temp;
	}
}
void Delete()
{
	struct node *temp;
	if(front == NULL)
		printf("Queue Underflow\n");
	else
	{
		temp = front;
		printf("Deleted process is %s\n",temp->process_name);
		front = front->next;
		free(temp);
	}
}
void display()
{
	struct node *ptr;
	ptr = front;
	if(front == NULL)
		printf("Queue is empty\n");
	else
	{	
		printf("Queue is :\n");
		printf("Priority\tItem\n");
		while(ptr != NULL)
		{
			printf("%d\t\t%s\n",ptr->priority,ptr->process_name);
			ptr = ptr->next;
		}
	}
}
