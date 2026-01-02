#include <math.h>

#include "hactivation.h"


float relu(float x)
{
    return x * (x > 0);
}

float d_relu(float x)
{
    return 1 * (x > 0);
}

float sigmoid(float x)
{
    return 1.0 / (1.0 + exp(-x));
}

float d_sigmoid(float x)
{
    float s = sigmoid(x);
    return s * (1.0 - s);
}

float tanh2(float x)
{
    return tanh((double)x);
}

float d_tanh2(float x)
{
    return 1 - pow(tanh2(x), 2);
}

float activation(float x, Activation act_func)
{
    switch (act_func)
    {
    case RELU:
        return relu(x);
    case SIGMOID:
        return sigmoid(x);
    case TANH:
        return tanh2(x);
    }
}

float d_activation(float x, Activation act_func)
{
    switch (act_func)
    {
    case RELU:
        return d_relu(x);
    case SIGMOID:
        return d_sigmoid(x);
    case TANH:
        return d_tanh2(x);
    }
}
