#include<stdio.h>
void display(int a[], int);
void insertion(int a[], int);
void main()
{
    int n, a[100];
    printf("\nEnter the size of the array, which must not exceed 100: ");
    do{
        scanf("%d", &n);
        if(n>100)
            printf("\nThe array size must not exceed 100.\nEnter again: ");
    }while(n>100);
    for(int i = 0; i < n; i++){
        printf("\nEnter element %d: ", (i+1));
        scanf("%d", &a[i]);
    }
    printf("\nThe array before sorting is - \n");
    display(a, n);
    insertion(a, n);
    printf("\nThe array after sorting is - \n");
    display(a, n);
}
void display(int a[], int n){
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
void insertion(int a[], int n){
    int i, j, temp;
    for(i = 1; i < n; i++){
        temp = a[i];
        j = i - 1;
        while(j >= 0 && temp <= a[j]){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = temp;
    }
}
