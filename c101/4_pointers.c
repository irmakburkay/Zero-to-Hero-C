#include <stdio.h>
#include <stdlib.h>

void by_value(int);
void by_reference(int *);

int main()
{
    int *p;
    int a = 10;
    p = &a;
    printf("&a: %d\n", &a);
    printf("a: %d\n", a);
    printf("&p: %d\n", &p);
    printf("p: %d\n", p);   
    printf("*p: %d\n", *p);   

    int d[80], *p1;
    p1 = d;
    printf("d[4]==*(p1+4): %d\n", d[4]==*(p1+4));
    for (int i=0;i<5;i++)
    {
        printf("&d[%d]: %d\n", i, &d[i]);
        printf("(p1+%d): %d\n", i, (p1+i));
    }

    int *d_a = (int *) malloc (sizeof(int) * 10);
    d_a[3] = 10;
    printf("d_a[3]: %d\n", d_a[3]);
    
    int x = 50;
    printf("x: %d\n", x);
    by_value(x);
    printf("x: %d\n", x);
    by_reference(&x);
    printf("x: %d\n", x);
}

void by_value(int x)
{
    x *= 2;
}

void by_reference(int * x)
{
    *x *= 2;
}