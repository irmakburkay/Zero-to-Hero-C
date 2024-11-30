#ifndef hlayer
#define hlayer
#include "hmatrix.h"

typedef struct
{
    int row, col, unit;
    float (*act_func)(float);
    Matrix* weights;
    Matrix* biases;
} Layer;

Layer* layer_init(int, int, int, float (*)(float));
Matrix* layer_forward(Layer*, Matrix*);
void free_layer(Layer**);

#endif
