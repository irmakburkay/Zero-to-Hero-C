#include <stdio.h>
#include <math.h>

// read n, returns the matrix n*n 
// with ones in the middle and zeros wrapping them
void q1()
{
    printf("n: ");
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i==n/2 || j==n/2 || (n%2==0 && (i==n/2-1 || j==n/2-1)))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}

// scan n 
// return biggest prime number less than n
void q2()
{
    printf("n: ");
    int n;
    scanf("%d", &n);
    int prime_num = 2;
    for (int i=n-1; i>2; i--)
    {
        int is_prime = 1;
        for (int j=2; j<i; j++)
        {
            if (i%j==0)
            {
                is_prime = 0;
                break;
            }
        }
        if (is_prime == 1)
        {
            prime_num = i;
            break;
        }
    }
    printf("Prime num is: %d", prime_num);
}

// scan n 
// print ~log2(n)
// 2^x = 30
/*
2
4
8
16
32
*/
void q3()
{
    printf("n: ");
    int n;
    scanf("%d", &n);
    int logn = 1;
    while (pow(2, logn) < n)
    {
        logn++;
    }
    if (pow(2, logn) == n)
        printf("logn %d", logn);
    else
        printf("logn %d-%d", logn-1, logn);
}

// q4
// scan numbers until -1
// print mean
void q4()
{
    float sum = 0;
    int c = 0;
    int input;
    while (1)
    {
        printf("input: ");
        scanf("%d", &input);
        if (input == -1)
            break;
        sum += input;
        c++;
    }
    if (c != 0)
        printf("Mean: %f", sum/c);
}

int main()
{
    printf("Hello World!\n");
    printf("q1\n");
    q1();
    printf("q2\n");
    q2();
    printf("q3\n");
    q3();
    printf("q4\n");
    q4();
    return 0;
}