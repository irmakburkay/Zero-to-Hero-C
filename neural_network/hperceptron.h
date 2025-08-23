#ifndef HPERCEPTRON
#define HPERCEPTRON
#include "hactivation.h"
#include "hloss.h"


typedef struct
{
    int input_size;
    float *weights;
    float bias;
    Activation act_func;
    float *last_inputs;
    float last_output;
} Perceptron;

Perceptron *perceptron_init(int input_size, Activation act_func);
float perceptron_forward(Perceptron *p, float *inputs);
void perceptron_backward(Perceptron *p, float y_true, float learning_rate, Loss loss_func);
void perceptron_free(Perceptron **p);

#endif
