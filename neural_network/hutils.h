#define SHAPE(x, y) (int[]){x, y}

#ifndef hutils
#define hutils
#include "hmatrix.h"

void random_init();
float* random_number_generator(int);
float relu(float);
float sigmoid(float);
float d_sigmoid(float);
float tanh2(float);
float d_tanh(float);

#endif
