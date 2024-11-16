/*
A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
A balanced bracket sequence is a string consisting of only brackets, 
such that every opening bracket has its closing bracket.
Formally you can define a balanced bracket sequence with: 
the empty string is a balanced bracket sequence. 
if ‘’s’’ is a balanced bracket sequence, then so is (s), {s} and [s]. 
if ‘’s’’ and t are balanced bracket sequences, then so is st.

Given a string of brackets, determine whether the string of brackets 
is a balanced bracket sequence. If a string is a balanced bracket sequence, 
print YES. Otherwise, print NO.

Input Format
A single-line string.

Output Format
If a string is a balanced bracket sequence, print YES. Otherwise, print NO.

Constraints
1 ≤ length of the string ≤ 2∗10^5

Sample Input 1 
{[()]}
Sample Output 1 
YES
Sample Input 2 
{[(])}
Sample Output 2 
NO
Sample Input 3 
{{[[(())]]}}
Sample Output 3 
YES


*/
#define MAX_LENGTH 200000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map(char key);

int main()
{
    char *single_line = (char *) malloc(sizeof(char *) * MAX_LENGTH + 1);
    scanf("%s", single_line);
    int len = strlen(single_line);

    if (len % 2 == 1)
    {
        printf("NO");
        free(single_line);
        return 0;
    }

    for (int i = 0; i < len / 2; i++)
    {
        char value = map(single_line[i]);
        if (single_line[len - i - 1] != value)
        {
            printf("NO");
            free(single_line);
            return 0;            
        }
    }
    printf("YES");
    free(single_line);
    return 0;
}

char map(char key)
{
    switch (key)
    {
    case '{':
        return '}';
    case '[':
        return ']';
    case '(':
        return ')';
    default:
        return '\0';
    }
}
