/*
Usain Bolt is a world famous athlete. 
In his whole career, he broke lots of new records. 
The points he got from the races he entered are given. 
The task is find how many times Usain Bolt broke his own record.

Input Format
The first line contains one integer N.

The second line contains N sized integer array.

Output Format
Print the number of broken records in one line.

Constraints
1 ≤ n ≤ 10^5
1 ≤ points ≤ 10^5

Sample Input 1 
5
3 7 2 6 8 
Sample Output 1 
2

Sample Input 2 
5
1 2 3 4 5
Sample Output 2 
4
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int biggest = -1;
    int count = -1;
    int read;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &read);
        if (read > biggest)
        {
            biggest = read;
            count++;
        }
    }
    printf("%d", count);
    return 0;    
}