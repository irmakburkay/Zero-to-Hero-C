/*
Rose just staged a coup against Eve and took control of inzva, 
Kundura City's most dangerous neighborhood, also known as The Pit. 
Aliens attacked The Pit while algorithmists were cheering 
“inzva is our home, Rose is our mother!”. 
There are N flying saucers who are attacking the hood, 
so Rose needs the list of all binary strings of length N. 
Help Rose, because inzva is our family and family is everything.

Input Format
The only line contains an integer N, number of flying saucers.

Output Format
Print N binary strings in 2^N lines, in alphanumerical order.

Constraints
1 ≤ N ≤ 20

Sample Input 1 
3
Sample Output 1 
000
001
010
011
100
101
110
111

*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = n-1; j >= 0; j--)
        {
            int k = i >> j;
            // printf("n%d i%d j%d k%d", n,i,j,k);
            printf("%d", k & 1);
        }
        printf("\n");
    }
    return 0;
}