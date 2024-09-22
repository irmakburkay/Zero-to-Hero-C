/*
https://www.algoleague.com/problem/solve-this-first/detail
Eren is interested in collecting controllers of old video game consoles and found a thrift shop that sells 2 boxes of controllers, 
for Atari and for PlayStation 1. It's written on each box how many controllers it contains. 
To figure out what to pay, Eren needs to calculate how many controllers there are in the boxes in total. 
You are given two numbers, which are the numbers of controllers in boxes.

Input Format
First line contains 2 integers - a and b

Output Format
Print a + b in single line

Constraints
0 ≤ a, b ≤ 10^5

Sample Input 1 
98761 36837
Sample Output 1 
135598

Sample Input 2 
42670 30679
Sample Output 2 
73349
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 256

int main()
{
    char *input = malloc(MAX_STRING_SIZE);
    printf("input: ");
    fgets(input, MAX_STRING_SIZE, stdin);

    int first_num, second_num;

    char *token = strtok(input, " ");
    first_num = atoi(token);

    token = strtok(NULL, " ");
    second_num = atoi(token);

    printf("%d", first_num + second_num);

    return 0;
}