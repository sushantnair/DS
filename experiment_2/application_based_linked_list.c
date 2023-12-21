#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void admission();
void cancellation();
void display();
int compare(char[], char[]);
struct Node 
{
    char name[100];
    struct Node *next;
};
struct Node *start = NULL;
void main()
{
    int ch;
    do
    {
        printf("\nEnter:\n'1' to apply for student admission.\n'2' to cancel the student's admission.\n'3' to display the list of admitted students.\n'4' to exit from the program.\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                admission();
            break;
            case 2:
                cancellation();
            break;
            case 3:
                display();
            break;
            case 4:
                printf("\nE\tX\tI\tT\tI\tN\tG\t.\t.\t.");
            break;
            default:
                printf("Please enter '1', '2' and '3' only. Try again!");
        }
    }while(ch!=4);
}
void admission()
{
    struct Node *temp;
    float marks;
    char cert;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the name of the student: ");
    scanf("%s", temp -> name);
    printf("\nEnter the marks obtained in Grade XII: ");
    scanf("%f", &marks);
    printf("\nDo you have necessary documents and certificates?: ");
    scanf("%s", &cert);
    temp -> next = NULL;
    if(marks < 35)
    {
        printf("\nWe would be glad to accept your ward, provided that\nhe should have secured at least 35 percent in his Class XII examinations.");
    }
    else
    {
        if(cert == 'N')
        {
            printf("\nWe would be glad to accept your ward, provided that\nall the necessary documents and certificates were present.");
        }
        else
        {
            if(start == NULL)
            {
                start = temp;
            }
            else
            {
                temp -> next = start;
                start = temp;
            }
        }    
    }
}
void cancellation()
{
    struct Node *temp;
    char adm_cancel[100];
    if(start==NULL)
    {
        printf("\nEmpty List!");
    }
    else
    {
        printf("\nEnter the name of the student whose admission you wish to cancel: ");
        scanf("%s", adm_cancel);
        while(temp!=NULL)
        {
            if(compare(temp -> name, adm_cancel) == 0)
            {
                printf("\nAdmission cancelled.");
                free(temp);
                //break;
            }
            else
                temp = temp -> next;
        }
    }
}
void display()
{
    struct Node *temp;
    temp = start;
    printf("\n");
    if(start==NULL)
    {
        printf("\nEmpty List!");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%s\t", temp -> name);
            temp = temp -> next;
        }
    }
}
int compare(char a[], char b[])
{
    int flag = 0, i = 0;
    while(a[i] != '\0' && b[i] != '\0')
    {
        if(a[i] != b[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0)
        return 0;
    else
        return 1;
}
