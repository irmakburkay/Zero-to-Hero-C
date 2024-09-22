#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello World!\n");
    printf("Pick a number between 0 and 100: ");
    int pick;
    scanf("%d", &pick);
    int r;
    int num_try = 0;
    while (r != pick)
    {
        r = rand() % 100;
        printf("%d\n", r);
        num_try++;
        if (r == pick)
        {    
            printf("Find %d at %d try.", r, num_try);
            break;
        }
        if (num_try == 1000000) 
        {
            printf("Cant find even 1.000.000 try.");
            break;
        }
    }
    return 0;
}