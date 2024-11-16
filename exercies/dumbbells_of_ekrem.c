/*
Ekrem has N dumbbells with varying weights. 
Since he is so strong, he wants to lift more than one dumbbell at a time. 
He selects some L and R. Then, he lifts all the range of Lth and Rth dumbbells. 
But the problem is Ekrem's math is not good and he wants to calculate the total weight each time. 
Could you help him?

Note: The numbers left and right are not zero-indexed.

Input Format
The first line contains two integers N and Q — the number of total dumbbells and the number of queries.

The second line consists of N numbers, split with a single space — the weight of each dumbbell.

Each of the next Q lines contains two integers L and R.

Output Format
Print Q lines. On each line, you should print the total weight in the range of L and R.

Constraints
1 ≤ N, Q ≤ 2*10^5
1 ≤ Li ≤ Ri ≤ N
1 ≤ dumbbell weights ≤ 1000

Sample Input 1 
5 3
5 4 2 7 1
2 3
1 1
1 5
Sample Output 1 
6
5
19


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *dumbell_weights = (int *) malloc(sizeof(int) * n);
    if (dumbell_weights == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        scanf("%d", dumbell_weights+i);

    int *total_weights = (int *) malloc(sizeof(int) * q);
    if (total_weights == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        int sum = 0;
        for (int j = l - 1; j < r; j++)
            sum += dumbell_weights[j];
        total_weights[i] = sum;
    }
    
    free(dumbell_weights);

    for (int i = 0; i < q; i++)
    {
        printf("%d\n", total_weights[i]);
    }

    free(total_weights);
    return 0;
}
