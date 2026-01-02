#include <stdio.h>
#include <stdlib.h>

#include "hutils.h"
#include "hlayer.h"


Layer *layer_init(int p_count, int input_size, Activation act_func)
{
    Layer *l = (Layer*) malloc(sizeof(Layer));
    l->p_count = p_count;
    
    l->ps = (Perceptron**) malloc(sizeof(Perceptron*) * p_count);
    l->input_gradients = (float*) malloc(sizeof(float) * input_size);
    l->inputs = (float**) malloc(sizeof(float*) * p_count);
    l->outputs = (float*) malloc(sizeof(float) * p_count);

    for (int i = 0; i < p_count; i++)
    {
        l->ps[i] = perceptron_init(input_size, act_func);
        l->inputs[i] = l->ps[i]->inputs;
    }
    return l;
}

void layer_forward(Layer *l, float *inputs)
{
    for (int i = 0; i < l->p_count; i++)
    {
        perceptron_forward(l->ps[i], inputs);
        l->outputs[i] = l->ps[i]->output;
    }
}

void layer_backward(Layer *l, float learning_rate, float *targets_or_gradients, int is_last, Loss loss_func)
{
    for (int i = 0; i < l->ps[0]->input_size; i++)
        l->input_gradients[i] = 0.0f;
        
    for (int i = 0; i < l->p_count; i++)
    {
        perceptron_backward(l->ps[i], learning_rate, targets_or_gradients[i], is_last, loss_func);
        for (int j = 0; j < l->ps[i]->input_size; j++)
            l->input_gradients[j] += l->ps[i]->input_gradients[j];
    }
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
        printf("%f", l->outputs[i]);
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
    SAFE_FREE((*l)->input_gradients);  
    SAFE_FREE((*l)->inputs);    
    SAFE_FREE((*l)->outputs);          
    SAFE_FREE(*l);
}
