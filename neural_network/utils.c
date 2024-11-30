#include "hutils.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>


void random_init()
{
    srand(time(NULL));
}

float* random_number_generator(int size)
{ 
    rand(); // first random number looks same always
    float* numbers = (float*)malloc(sizeof(float) * size);
    for (int i = 0; i < size; i++)
        numbers[i] = ((float)rand() / RAND_MAX) - 0.5; // [-0.5, 0.5]
    return numbers; 
}

float relu(float x)
{
    return x * (x > 0);
}

float d_relu(float x)
{
    return 1 * (x > 0);
}

float sigmoid(float x)
{
    return 1 / (1 + exp(-x));
}

float d_sigmoid(float x)
{
    return sigmoid(x) * (1 - sigmoid(x));
}

float tanh2(float x)
{
    return tanh((double) x);
}

float d_tanh(float x)
{
    return 1 - pow(tanh2(x), 2);
}
