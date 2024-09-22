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