#ifndef HPERCEPTRON
#define HPERCEPTRON

#include "hloss.h"
#include "hactivation.h"


typedef struct
{
    int input_size;
    Activation act_func;

    float *weights;
    float *input_gradients;
    float bias;
    float *inputs;
    float output;
} Perceptron;

Perceptron *perceptron_init(int input_size, Activation act_func);
void perceptron_forward(Perceptron *p, float *inputs);
void perceptron_backward(Perceptron *p, float learning_rate, float target_or_gradient, int is_last, Loss loss_func);
void perceptron_print_out(Perceptron *p);
void perceptron_free(Perceptron **p);

#endif
