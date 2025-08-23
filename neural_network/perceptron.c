#include "hperceptron.h"
#include "hutils.h"
#include <stdlib.h>


Perceptron *perceptron_init(int input_size, Activation act_func)
{
    Perceptron *p = (Perceptron *)malloc(sizeof(Perceptron));
    p->input_size = input_size;
    p->weights = (float *)malloc(sizeof(float) * input_size);
    for (int i = 0; i < input_size; i++)
        p->weights[i] = random_float();
    p->bias = random_float();
    p->act_func = act_func;
    p->last_inputs = (float *)malloc(sizeof(float) * input_size);
    p->last_output = 0.0f;

    return p;
}

float perceptron_forward(Perceptron *p, float *inputs)
{

    float sum = p->bias;

    for (int i = 0; i < p->input_size; i++)
        p->last_inputs[i] = inputs[i];
    
    for (int i = 0; i < p->input_size; i++)
        sum += p->weights[i] * inputs[i];

    p->last_output = activation(sum, p->act_func);
    return p->last_output;

}

void perceptron_backward(Perceptron *p, float y_true, float learning_rate, Loss loss_func)
{
    float error = d_loss(p->last_output, y_true, loss_func);
    float delta = error * d_activation(p->last_output, p->act_func);
    for (int i = 0; i < p->input_size; i++)
        p->weights[i] -= learning_rate * delta * p->last_inputs[i];

    p->bias -= learning_rate * delta;
}

void perceptron_free(Perceptron **p)
{
    if (!p || !(*p))
        return;
    SAFE_FREE((*p)->weights);
    SAFE_FREE((*p)->last_inputs);
    SAFE_FREE(*p);
}
