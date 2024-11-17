#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct n
{
    float data;
    int size;
    struct n* next;
} node;

node* init(float);
void print(node*);
void append(node*, float);
void pop(node*);
void destroy(node**);
void clear(node*);

int main()
{
    node *n = NULL;
    print(n);

    n = init(NAN);
    print(n);

    for (int i = 0; i < 5; i++)
    {
        append(n, i);
        print(n);
    }

    for (int i = 0; i < 6; i++)
    {
        pop(n);
        print(n);
    }
    
    for (int i = 0; i < 5; i++)
        append(n, i);
    print(n);
    clear(n);
    print(n);
    printf("Is n free? %s\n", n == NULL ? "Yes" : "NO");


    for (int i = 0; i < 5; i++)
        append(n, i);
    print(n);
    destroy(&n);
    print(n);

    printf("Is n free? %s\n", n == NULL ? "Yes" : "NO");

    return 0;
}


node* init(float data)
{
    node *n = (node*) malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    
    n->data = data;
    n->size = isnan(data) ? 0 : 1;
    n->next = NULL;
    return n;
}

void print(node* n)
{
    if (n == NULL)
    {
        printf("Not init\n");
        return;
    }

    if (isnan(n->data))
    {
        printf("Size 0: NULL\n");
        return;
    }
    
    printf("Size %d: Data: ", n->size);
    while (n != NULL)
    {
        printf("%d ", (int) n->data);
        n = n->next;
    }
    printf("\n");
}

void append(node* n, float data)
{
    if (n == NULL)
    {
        printf("Not init\n");
        return;
    }

    if (isnan(n->data))
    {
        n->data = data;
        n->size++;
        return;
    }

    n->size++;
    if (n->next == NULL)
        n->next = init(data);
    else
        append(n->next, data);
}

void pop(node* n)
{
    if (n == NULL)
    {
        printf("Not init\n");
        return;
    }

    if (isnan(n->data))
        return;

    if (n->next == NULL)
    {
        n->data = NAN;
        n->size = 0;
        return;
    }
    
    n->size--;
    if (n->next->next == NULL)
    {
        free(n->next);
        n->next = NULL;
    }
    else
        pop(n->next);
}

void destroy(node** n)
{
    node* tmp = *n;
    node* iter;

    while (tmp != NULL)
    {
        iter = tmp->next;
        free(tmp);
        tmp = iter;
    }

    *n = NULL;
}

void clear(node* n)
{
    destroy(&(n->next));
    n->data = NAN;
    n->size = 0;
    n->next = NULL;
}
