#ifndef HLAYER
#define HLAYER

#include "hperceptron.h"


typedef struct
{
    int p_count;
    Perceptron **ps;

    float **weights;
    float **biases;
    float **inputs;
    float **outputs;
} Layer;

Layer *layer_init(int p_count, int input_size, Activation activation);
void layer_forward(Layer *l, float *inputs);
void layer_backward(Layer *l, float *y_trues, float learning_rate, Loss loss);
void layer_print_out(Layer *l);
void layer_free(Layer **l);

#endif
