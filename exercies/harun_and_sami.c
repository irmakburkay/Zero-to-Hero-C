/*
Harun and Sami are very good friends. They play a game for N rounds. 
In each round, Harun or Sami wins. In other words, 
a round never ends in a draw. To win the game, 
you need to win more rounds than your opponent.

Unfortunately, they only remember the result of the first K rounds. 
Also, both of them claim to have won the game. 
Therefore, you need to determine if anyone has definitely won the game 
or not by considering the first K rounds.

Input Format
The first line contains two integers N and K, separated by a space.

The next line contains a string with K characters. 
The letter H denotes that Harun won that round, 
and the letter S denotes that Sami won that round.

Output Format
If it is certain that Harun won the game, print "Harun".
If it is certain that Sami won the game, print "Sami".
If the winner cannot be determined from the results of the first K rounds, print "Cilek".

Constraints
1 ≤ K ≤ N ≤ 10^5

Sample Input 1 
7 5
HSHHH
Sample Output 1 
Harun

Sample Input 2 
7 5
HSHSH
Sample Output 2 
Cilek

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    int num_h = 0, num_s = 0;
    char *c = (char *) malloc(sizeof(char) * K);
    scanf("%s", c);
    for (int i = 0; i < K; i++)
    {
        if (c[i] == 'H')
            num_h++;
        else if (c[i] == 'S')
            num_s++;
    }
    if (num_h > (float)N / 2)
        printf("Harun");
    else if (num_s > (float)N / 2)
        printf("Sadi");
    else
        printf("Cilek");
    return 0;
}