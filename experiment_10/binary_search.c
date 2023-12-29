#include<stdio.h>
int binary_search(int a[], int, int);
void display(int a[], int);
void main()
{
    int n, arr[100], i, search, pos;
    printf("Enter the size of array, which must be less than or equal to 100: ");
    do
    {
        scanf("%d", &n);
        if(n>100)
            printf("\nPlease try again! The array size must be less than or equal to 100.\nEnter again: ");
    }while(n>100);
    printf("\nEnter the array elements in ASCENDING order.");
    for(i = 0; i < n; i++)
    {
        printf("\nFor element %d, enter value: ", (i+1));
        scanf("%d", &arr[i]);
    }
    printf("\nThe array entered is displayed.\n");
    display(arr, n);
    printf("\nEnter the element to search: ");
    scanf("%d", &search);
    pos = binary_search(arr, n, search);
    if(pos != -1)
        printf("\nThe value is found at position %d.", pos);
    else
        printf("\nThe value is not found.");
}
int binary_search(int a[], int n, int search)
{
    int first = 0, last, middle;
    last = n;
    middle = (first + last)/2;
    while(first <= last)
    {
        if(a[middle] < search)
            first = middle+1;
        else if(a[middle] > search)
            last = middle-1;
        else
            return (middle+1);
        middle = (first+last)/2;
    }
    return -1;
}
void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
