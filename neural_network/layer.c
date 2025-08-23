#include <stdio.h>
#include <stdlib.h>

#include "hutils.h"
#include "hlayer.h"


Layer *layer_init(int p_count, int input_size, Activation activation)
{
    Layer *l = (Layer*) malloc(sizeof(Layer));
    l->p_count = p_count;
    
    l->ps = (Perceptron**) malloc(sizeof(Perceptron*) * p_count);
    l->weights = (float**) malloc(sizeof(float*) * p_count);
    l->biases = (float**) malloc(sizeof(float*) * p_count);
    l->inputs = (float**) malloc(sizeof(float*) * p_count);
    l->outputs = (float**) malloc(sizeof(float*) * p_count);

    for (int i = 0; i < p_count; i++)
    {
        l->ps[i] = perceptron_init(input_size, activation);
        l->weights[i] = l->ps[i]->weights;
        l->biases[i] = &(l->ps[i]->bias);
        l->inputs[i] = l->ps[i]->inputs;
        l->outputs[i] = &(l->ps[i]->output);
    }
    return l;
}

void layer_forward(Layer *l, float *inputs)
{
    for (int i = 0; i < l->p_count; i++)
        perceptron_forward(l->ps[i], inputs);
}

void layer_backward(Layer *l, float *y_trues, float learning_rate, Loss loss)
{
    for (int i = 0; i < l->p_count; i++)
        perceptron_backward(l->ps[i], y_trues[i], learning_rate, loss);
}

void layer_print_out(Layer *l)
{
    printf("[");
    for (int i = 0; i < l->ps[0]->input_size; i++)
    {
        printf("%f", l->ps[0]->inputs[i]);
        if (i != l->ps[0]->input_size - 1)
            printf(", ");
    }
    printf("] -> [");
    for (int i = 0; i < l->p_count; i++)
    {
        printf("%f", *(l->outputs[i]));
        if (i != l->p_count - 1)
            printf(", ");
    }
    printf("]\n");
}

void layer_free(Layer **l)
{
    if (!l || !(*l))
        return;

    for (int i = 0; i < (*l)->p_count; i++)
        perceptron_free(&((*l)->ps[i]));

    SAFE_FREE((*l)->ps);
    SAFE_FREE((*l)->weights);    
    SAFE_FREE((*l)->inputs);    
    SAFE_FREE(*l);
}
