#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *d_arr = (int *)malloc(sizeof(int) * 5);
    d_arr[2] = 10;
    printf("d_arr[2]: %d\n", *(d_arr + 2));
    // d_arr[2] == *(d_arr + 2)

    int a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    int *b = (int *)malloc(sizeof(int) * 5);
    b[3] = 8;
    b[0] = 2;
    *(b + 1) = 10;
    *(b + 2) = 11;
    b[4] = 14;
    for (int i = 0; i < 5; i++)
        printf("%d ", b[i]);
    printf("\n");
}