/*
Strange things are happening in inzva. 
The word machine that causes these strange things is destroying the words that are new to inzva. 
If identical letters are consecutive, this machine deletes consecutive and identical letters of a received word, 
leaving only one of the identical letters. 
In other words, identical characters will not be consecutive in the arranged word. 
Your task is to print the final version of the word that was changed by the machine.

nput Format
The first line contains one integer, N.

The second line contains N sized string.

Output Format
Print the rearranged string in one line.

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
    char *a = (char *) malloc(sizeof(char) * n);
    scanf("%s", a);
    char *r_a = (char *) malloc(sizeof(char) * (n + 1));
    r_a[0] = a[0];
    int r_i = 0;
    for (int i = 1; i < n; i++)
    {
        if (r_a[r_i] != a[i])
            r_a[++r_i] = a[i];
    }
    r_a[r_i + 1] = '\0';
    printf("%s", r_a);
    return 0;
}