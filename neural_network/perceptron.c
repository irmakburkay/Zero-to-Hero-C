#include <stdio.h>
#include <stdlib.h>

#include "hutils.h"
#include "hperceptron.h"


Perceptron *perceptron_init(int input_size, Activation activation)
{
    Perceptron *p = (Perceptron*) malloc(sizeof(Perceptron));
    p->input_size = input_size;
    p->activation = activation;
    
    p->weights = (float*) malloc(sizeof(float) * input_size);
    for (int i = 0; i < input_size; i++)
        p->weights[i] = random_float();
    p->bias = random_float();
    p->inputs = (float*) malloc(sizeof(float) * input_size);
    p->output = 0.0f;

    return p;
}

void perceptron_forward(Perceptron *p, float *inputs)
{
    float sum = p->bias;

    for (int i = 0; i < p->input_size; i++)
        p->inputs[i] = inputs[i];
    
    for (int i = 0; i < p->input_size; i++)
        sum += p->weights[i] * inputs[i];

    p->output = activation(sum, p->activation);
}

void perceptron_backward(Perceptron *p, float y_true, float learning_rate, Loss loss)
{
    float error = d_loss(p->output, y_true, loss);
    float delta = error * d_activation(p->output, p->activation);
    for (int i = 0; i < p->input_size; i++)
        p->weights[i] -= learning_rate * delta * p->inputs[i];

    p->bias -= learning_rate * delta;
}

void perceptron_print_out(Perceptron *p)
{
    printf("[");
    for (int i = 0; i < p->input_size; i++)
    {
        printf("%f", p->inputs[i]);
        if (i != p->input_size - 1)
            printf(", ");
    }
    printf("] -> [%f]", p->output);
}

void perceptron_free(Perceptron **p)
{
    if (!p || !(*p))
        return;
    SAFE_FREE((*p)->weights);
    SAFE_FREE((*p)->inputs);
    SAFE_FREE(*p);
}
