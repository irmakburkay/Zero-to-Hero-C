/*
Strange things are happening in inzva. The word machine 
that causes these strange things is destroying the words 
that are new to inzva. If identical letters are consecutive, 
this machine deletes consecutive and identical letters of a received word, 
leaving only one of the identical letters. In other words, 
identical characters will not be consecutive in the arranged word. 
Your task is to print the final version of the word 
that was changed by the machine.

Input Format
The first line contains one integer, N.

The second line contains N sized str.

Output Format
Print the rearranged str in one line.

Constraints
1 ≤ N ≤ 10^5

Sample Input 1 
9
SSSVEEEJJ
Sample Output 1 
SVEJ

Sample Input 2 
4
AAAA
Sample Output 2 
A


*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);

    char *str = (char *) malloc(sizeof(char) * n);
    if (str == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    scanf("%s", str);
    
    int sizeof_new_str = 4;
    char *new_str = (char *) malloc(sizeof(char) * (sizeof_new_str + 1)); // at least four char and null char
    if (new_str == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    new_str[0] = str[0];
    new_str[1] = '\0';
    int j = 1;
    for (int i=1; i<n; i++)
    {
        if (str[i] != new_str[j-1])
        {
            new_str[j++] = str[i];
            new_str[j] = '\0';
        }
        if (j == sizeof_new_str + 1)
        {
            sizeof_new_str *= 2;
            new_str = (char *) realloc(new_str, sizeof(char) * (sizeof_new_str + 1)); // dynamicly growing string
            if (new_str == NULL)
            {
                printf("Memory allocation failed!");
                exit(1);
            }
        }
    }

    free(str);

    new_str[j] = '\0';
    printf("%s", new_str);

    return 0;
}
