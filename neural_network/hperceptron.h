#ifndef HPERCEPTRON
#define HPERCEPTRON

#include "hloss.h"
#include "hactivation.h"


typedef struct
{
    int input_size;
    Activation activation;

    float *weights;
    float bias;
    float *inputs;
    float output;
} Perceptron;

Perceptron *perceptron_init(int input_size, Activation activation);
void perceptron_forward(Perceptron *p, float *inputs);
void perceptron_backward(Perceptron *p, float y_true, float learning_rate, Loss loss);
void perceptron_print_out(Perceptron *p);
void perceptron_free(Perceptron **p);

#endif
