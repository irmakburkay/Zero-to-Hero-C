#ifndef HACTIVATION
#define HACTIVATION


typedef enum
{
    RELU,
    SIGMOID,
    TANH
} Activation;

float relu(float x);
float d_relu(float x);
float sigmoid(float x);
float d_sigmoid(float x);
float tanh2(float x);
float d_tanh2(float x);
float activation(float x, Activation activation);
float d_activation(float x, Activation activation);

#endif
