#include <stdio.h>

// q1
// put first 20 element of fibonacci to an array
void q1()
{
    int fib[20];
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2; i<20; i++)
        fib[i] = fib[i-1] + fib[i-2];
    for (int i=0; i<20; i++)
        printf("%d ", fib[i]);
}

int main()
{
    int d0[10];
    int d1[] = {1,2,3,4,5};
    int d2[5] = {1,2,3,4,5};
    int d3[2][3];
    int d4[2][3] = {{1,2,3},{4,5,6}};
    int a[] = {1,2,3};
    q1();
    return 0;
}