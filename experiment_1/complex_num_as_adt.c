#include<stdio.h>
typedef struct Complex
{
    int r;
    int i;
}complex;
complex add(complex a, complex b)
{
    complex result;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
}
complex sub(complex a, complex b)
{
    complex result;
    result.r = a.r - b.r;
    result.i = a.i - b.i;
    return result;
}
complex mul(complex a, complex b)
{
    complex result;
    result.r = a.r*b.r - a.i*b.i;
    result.i = a.i*b.r + a.r*b.i;
    return result;
}
void eq(complex a, complex b)
{
    if((a.r==b.r)&&(a.i==b.i))
        printf("\nThe complex numbers %d+i%d and %d+i%d are equal.", a.r, a.i, b.r, b.i);
    else
        printf("\nThe complex numbers %d+i%d and %d+i%d are not equal.", a.r, a.i, b.r, b.i);
}
void main()
{
    complex c1, c2, sum, diff, prod;
    printf("\nEnter the real part of the first complex number: ");
    scanf("%d", &c1.r);
    printf("\nEnter the imaginary part of the first complex number: ");
    scanf("%d", &c1.i);
    printf("\nEnter the real part of the second complex number: ");
    scanf("%d", &c2.r);
    printf("\nEnter the imaginary part of the second complex number: ");
    scanf("%d", &c2.i);
    sum = add(c1, c2);
    diff = sub(c1, c2);
    prod = mul(c1, c2);
    eq(c1, c2);
    printf("\nThe sum of %d+i%d and %d+i%d is %d+i%d", c1.r, c1.i, c2.r, c2.i, sum.r, sum.i);
    printf("\nThe difference of %d+i%d and %d+i%d is %d+i%d", c1.r, c1.i, c2.r, c2.i, diff.r, diff.i);
    printf("\nThe product of %d+i%d and %d+i%d is %d+i%d", c1.r, c1.i, c2.r, c2.i, prod.r, prod.i);
}
