#ifndef HNETWORK
#define HNETWORK

#include "hlayer.h"


typedef struct 
{
    int l_count;
    Layer **ls;
} Network;

Network *network_init(LayerConfig *config, int l_count);
void network_forward(Network *net, float *inputs);
void network_backward(Network *net, float learning_rate, float *y_trues, Loss loss_func);
void network_print_out(Network *net);
void network_print_weights(Network* net);
void network_free(Network **net);

#endif
