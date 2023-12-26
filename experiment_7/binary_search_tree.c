#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;
struct Node *create_node(int);
void insert(int);
int search(int);
void inorder(struct Node*);
void preorder();
void postorder();
int get_data();
void main()
{
    int ch, data;
    do
    {
        printf("\nEnter:\n'1' to insert a new node.\n'2' to search for a node.\n'3' to get inorder representation.\n'4' to get preorder representation\n'5' to get postorder representation\n'6' to exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                data = get_data();
                insert(data);
                break;
            case 2:
                data = get_data();
                if(search(data) == 1)
                    printf("\nThe data %d has been found.", data);
                else
                    printf("\nThe data was not found.");
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                printf("\nE\tX\tI\tT\tI\tN\tG\t.\t.\t.");
                break;
            default:
            printf("\nPlease enter '1', '2', '3', '4', '5' or '6' only and try again!");
        }
    }while(ch!=6);
}
struct Node *create_node(int data)
{
    struct Node *new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node == NULL)
    {
        printf("\nMemory allocation was unsuccessful.");
        return NULL;
    }
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}
void insert(int data)
{
    struct Node *new_node;
    new_node = create_node(data);
    if(new_node != NULL)
    {
        if(root == NULL)
        {
            root = new_node;
            printf("\nThe node having data %d has been inserted.", data);
            return;
        }
        struct Node *temp = root;
        struct Node *prev = NULL;
        while(temp != NULL)
        {
            prev = temp;
            if(data > temp -> data)
                temp = temp -> right;
            else
                temp = temp -> left;
        }
        if(data > prev -> data)
            prev -> right = new_node;
        else
            prev -> left = new_node;
        printf("\nThe node having data %d has been inserted.", data);
    }
}
int search(int key)
{
    struct Node *temp = root;
    while(temp != NULL)
    {
        if(temp -> data == key)
            return 1;
        else if(key > temp -> data)
            temp = temp -> right;
        else
            temp = temp -> left;
    }
    return 0;
}
void inorder(struct Node *root)
{
    if(root == NULL)
        return;
    inorder(root -> left);
    printf("%d\t", root -> data);
    inorder(root -> right);
}
void preorder(struct Node *root)
{
    if(root == NULL)
        return;
    printf("%d\t", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}
void postorder(struct Node *root)
{
    if(root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%d\t", root -> data);
}
int get_data()
{
    int data;
    printf("\nEnter data for the node: ");
    scanf("%d", &data);
    return data;
}
