/*
Once there was a programmer who was living in The Pit. 
While he was teaching an advanced data structure, 
he suddenly turned into Meme-Man, the greatest superhero of Kundura City. 
Meme-Man’s arch-nemesis Treap-Man created a giant staircase to attack the city. 
The only way to stop the giant staircase is to reach its top 
by climbing x or y stairs at a time. Meme-Man wonders how many 
different ways there are to do this. Help our hero by satisfying his curiosity.

Follow Up: Try to solve in O(N) time complexity.

Input Format
In the first line there is N, the number of stairs.

In the second line there are x and y.

Output Format
Print the number of ways Meme-Man can climb the giant staircase.

Constraints
1 ≤ N ≤ 21
x ≠ y

Sample Input 1 
2
1 2
Sample Output 1 
2
Explanation 1
There are three ways of climbing. Meme-Man can climb two step with one. Meme-Man can climb one step with two.


*/

#include <stdio.h>

int func(int, int, int);

int main()
{
    int stair_count, x, y;
    scanf("%d", &stair_count);
    scanf("%d %d", &x, &y);
    printf("%d", func(stair_count, x, y));
    return 0;
}

int func(int num, int x, int y)
{
    int ways = 0;
    if (num - x == 0)
        ways += 1;
    else if (num - x < 0)
        ways += 0;
    else
        ways += func(num - x, x, y);

    if (num - y == 0)
        ways += 1;
    else if (num - y < 0)
        ways += 0;
    else
        ways += func(num - y, x, y);

    return ways;
}
