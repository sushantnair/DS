#include<stdio.h>
int add(int a, int b)
{
    printf("\nThe sum of %d and %d is: ", a, b);
    return (a+b);
}
int sub(int a, int b)
{
    printf("\nThe difference of %d and %d is: ", a, b);
    return (a-b);
}
int mul(int a, int b)
{
    printf("\nThe product of %d and %d is: ", a, b);
    return (a*b);
}
int d_v(int a, int b)
{
    printf("\nThe quotient of %d and %d is: ", a, b);
    return ((float)(a/b));
}
int (*fp[10])(int, int);
void main()
{
    fp[1] = add;
    fp[2] = sub;
    fp[3] = mul;
    fp[4] = d_v;
    int a, b, c;
    float result;
    do{
        printf("\nEnter the first number: ");
        scanf("%d", &a);
        printf("\nEnter the second number: ");
        scanf("%d", &b);
        printf("\nEnter '1' to add, '2' to subtract,\n'3' to multiply, '4' to divide,\n'5' to exit. Enter your choice: ");
        scanf("%d", &c); 
        result = fp[c](a, b);
        printf("%f", result);
    }while(c!=5);
}
