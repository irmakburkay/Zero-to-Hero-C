#ifndef HLAYER
#define HLAYER

#include "hperceptron.h"


typedef struct {
    int input_size;
    int p_count;
    Activation act_func;
} LayerConfig;

typedef struct
{
    int p_count;
    Perceptron **ps;

    float *input_gradients;
    float **inputs;
    float *outputs;
} Layer;

Layer *layer_init(int p_count, int input_size, Activation act_func);
void layer_forward(Layer *l, float *inputs);
void layer_backward(Layer *l, float learning_rate, float *targets_or_gradients, int is_last, Loss loss_func);
void layer_print_out(Layer *l);
void layer_free(Layer **l);

#endif
