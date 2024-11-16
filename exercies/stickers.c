/*
New stickers have arrived at inzva Sanctuary. But not enough stickers for every participant. 
So, Havva decides to ask a question to participants and give a sticker for the right answer. 
Havva gives the number N to participants and asks them to multiply all the digits except zeros. 
Then asks them to apply the same operation to the result, until only one digit left. 
The right answer is just that number.

Yasin really wants those stickers, can you help Yasin to get a sticker?

Input Format
The only line contains a single integer N.

Output Format
Print the one-digit result.

Constraints
1 ≤ N ≤ 10^18

Sample Input 1 
366
Sample Output 1 
8

Explanation 1
3⋅6⋅6 = 108
1⋅8 = 8
The answer is 8.


*/

#include <stdio.h>

unsigned long long operation(unsigned long long num)
{
    unsigned long long result = 1;
    while (num > 0)
    {
        unsigned long long mod = num % 10;
        if (mod > 1)
            result *= mod;
        num /= 10;
    }
    return result;
}

int main()
{
    unsigned long long num;
    scanf("%llu", &num);
    while (num >= 10)
        num = operation(num);
    printf("%d", num);
    return 0;
}