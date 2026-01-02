#include <stdio.h>
#include <stdlib.h>

#include "hutils.h"
#include "hperceptron.h"


Perceptron *perceptron_init(int input_size, Activation act_func)
{
    Perceptron *p = (Perceptron*) malloc(sizeof(Perceptron));
    p->input_size = input_size;
    p->act_func = act_func;
    
    p->weights = (float*) malloc(sizeof(float) * input_size);
    p->input_gradients = (float*) malloc(sizeof(float) * input_size);
    for (int i = 0; i < input_size; i++)
        p->weights[i] = xavier_init(input_size);
    p->bias = 0.0f;
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

    p->output = activation(sum, p->act_func);
}

void perceptron_backward(Perceptron *p, float learning_rate, float target_or_gradient, int is_last, Loss loss_func)
{
    float error = is_last ? d_loss(target_or_gradient, p->output, loss_func) : target_or_gradient;
    
    float pre_activation = p->bias;
    for (int i = 0; i < p->input_size; i++)
        pre_activation += p->weights[i] * p->inputs[i];
    
    float delta = error * d_activation(pre_activation, p->act_func);
    
    for (int i = 0; i < p->input_size; i++)
    {
        p->input_gradients[i] = delta * p->weights[i];
        p->weights[i] -= learning_rate * delta * p->inputs[i];
    }

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
    SAFE_FREE((*p)->input_gradients);
    SAFE_FREE((*p)->inputs);
    SAFE_FREE(*p);
}
