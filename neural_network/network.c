#include "hnetwork.h"
#include <stdlib.h>


Network* network_init(int layer_size)
{
    Network* network = (Network*)malloc(sizeof(Network));
    network->layer_size = layer_size;
    network->layers = (Layer**)malloc(sizeof(Layer*) * layer_size);
    return network;
}

BatchMatrix* network_forward(Network* network, BatchMatrix* inputs)
{
    BatchMatrix* by = batchMatrix_init(inputs->batch_size, inputs->rows, inputs->cols);
    for (int i = 0; i < inputs->batch_size; i++)
    {
        Matrix* y = matrix_cpy(inputs->matrix[i]);
        Matrix* temp = NULL;
        for (int j = 0; j < network->layer_size; j++)
        {
            temp = layer_forward(network->layers[j], y);
            free_matrix(&y);
            y = temp;
        }
        by->matrix[i] = y;
    }
    return by;
}

void free_network(Network** n)
{
    if (!n || !(*n)) return;
    if ((*n)->layers)
    {
        for (int i = 0; i < (*n)->layer_size; i++) {
            if ((*n)->layers[i] != NULL) {
                free_layer(&(*n)->layers[i]);
            }
        }
        free((*n)->layers);
        (*n)->layers = NULL;
    }
    free(*n);
    *n = NULL;
}
