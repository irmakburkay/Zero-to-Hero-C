#include "hutils.h"
#include "hmatrix.h"
#include "hlayer.h"
#include "hnetwork.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    random_init();

    // XOR dataset
    BatchMatrix* X = batchMatrix_init(4, 2, 1);
    BatchMatrix* y = batchMatrix_init(4, 1, 1);
    X->matrix[1]->data[0][0] = 1;
    X->matrix[2]->data[1][0] = 1;
    X->matrix[3]->data[0][0] = 1;
    X->matrix[3]->data[1][0] = 1;
    y->matrix[1]->data[0][0] = 1;
    y->matrix[2]->data[0][0] = 1;

    Network* network = network_init(2);

    network->layers = (Layer**)malloc(sizeof(Layer*) * 2);
    network->layers[0] = layer_init(2, 1, 2, relu);
    network->layers[1] = layer_init(2, 1, 1, sigmoid);

    BatchMatrix* outputs = network_forward(network, X);
    batchMatrix_print(outputs);

    free_batchMatrix(&outputs);
    free_batchMatrix(&X);
    free_batchMatrix(&y);
    free_network(&network);
    return 0;
}
