#include<stdio.h>
#include<stdlib.h>
int visit[20] = {0}, v[20] = {0};
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;
typedef struct Queue
{
    struct Node *rr;
    struct Node *fr;
}Q;
int dequeue(Q *q);
void enqueue(int ch, Q *q);
void display(Q *q);
void dfs(int t, int a[20][20], int n);
void bfs(int t, int a[20][20], int n, Q *q);
void main()
{
    int num_vert, i, j, num_edge, t, p, q, start;
    int a[20][20];
    printf("\nEnter the number of vertices: ");
    scanf("%d", &num_vert);
    for(i = 0; i < num_vert; i++)
    {
        visit[i] = 0;
        for(j = 0; j < num_vert; j++)
        {
            a[i][j] = 0;
        }
    }
    printf("\nEnter the number of edges: ");
    scanf("%d", &num_edge);
    printf("\nEnter '1' if the graph is undirected and '0' if the graph is directed: ");
    scanf("%d", &t);
    for(i = 0; i < num_edge; i++)
    {
        printf("\nEnter edge vertex (p,q): ");
        scanf("%d%d", &p, &q);
        a[p-1][q-1] = 1;
        if(t == 1)
            a[q-1][p-1] = 1;
    }
    for(i = 0; i < num_vert; i++)
    {
        for(j = 0; j < num_vert; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the element from which you want to start the BFS and DFS: ");
    scanf("%d", &start);
    Q q1;
    q1.fr = q1.rr = NULL;
    printf("\nBFS:\n");
    bfs(start, a, num_vert, &q1);
    printf("\nDFS:\n");
    dfs(start, a, num_vert);
}
void enqueue(int ch, Q *q)
{
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = ch;
    newnode->prev = NULL;
    newnode->next = NULL;
    if(q->fr == NULL)
    {
        q->fr = newnode;
        q->rr = newnode;
    }
    else
    {
        newnode->next = q->fr;
        q->fr->prev = newnode;
        q->fr = newnode;
    }
}
int dequeue(Q *q)
{
    Node *temp;
    if(q->rr != NULL)
    {
        temp = q->rr;
        int d = temp->data;
        q->rr = temp->prev;
        if(q->rr != NULL)
            q->rr->next = NULL;
        else
            q->fr = NULL;
        return d;
    }
    return 0;
}
void display(Q *q)
{
    Node *temp;
    temp = q->fr;
    while(temp != NULL)
    {
        printf(" %c", temp->data);
        temp = temp->next;
    }
}
void bfs(int t, int a[20][20], int num_vert, Q *q)
{
    int i, j;
    printf("%d->", t);
    int temp;
    enqueue(t, q);
    v[t-1] = 1;
    while(q->fr != NULL){
        temp = dequeue(q);
        for(i = 0; i < num_vert; i++){
            if(a[temp-1][i] == 1 && v[i] == 0){
                enqueue(i+1, q);
                printf("%d->", i+1);
                v[i] = 1;
            }
        }
    }
}
void dfs(int t, int a[20][20], int num_vert)
{
    int i, j;
    printf("%d->", t);
    visit[t-1] = 1;
    for(i = 0; i < num_vert; i++){
        if(a[t-1][i] == 1 && visit[i] == 0){
            dfs(i+1, a, num_vert);
        }
    }
}
