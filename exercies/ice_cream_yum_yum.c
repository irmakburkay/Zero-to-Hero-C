/*
One day, Omar and Havva went to the ice cream shop. 
There are N different types of ice cream and the shop has Ai kilogram of each type. 
Omar wants to eat lots of ice cream, therefore he decided to eat all of the N−1 types of ice cream and leave one type to Havva.
Since he wants to eat lots of ice cream, could you print the maximum amount of ice cream that Omar can eat?


The first line contains one integer, N.
The next line contains N integers, Ai — the amount of ice cream of type i.

Output Format
Print a single integer — the maximum amount of ice cream Omar can eat.

Constraints
2 ≤ N ≤ 10^5
1 ≤ Ai ≤ 10^3

Sample Input 1 
8
10 3 8 9 7 5 5 5
Sample Output 1 
49

Sample Input 2 
2
5 10
Sample Output 2 
10
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int sum = 0;
    int lowest = a[0];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] < lowest)
            lowest = a[i];
    }
    int answer = sum - lowest;
    printf("%d", answer);
    
    return 0;
}