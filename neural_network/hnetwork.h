#ifndef hnetwork
#define hnetwork
#include "hmatrix.h"
#include "hlayer.h"

typedef struct
{
    int layer_size;
    Layer** layers;
} Network;

Network* network_init(int);
BatchMatrix* network_forward(Network*, BatchMatrix*);
void free_network(Network**);

#endif