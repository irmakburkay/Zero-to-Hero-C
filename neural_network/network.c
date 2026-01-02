#include <stdio.h>
#include <stdlib.h>

#include "hutils.h"
#include "hnetwork.h"

Network *network_init(LayerConfig *config, int l_count)
{
    Network *net = (Network*) malloc(sizeof(Network));
    net->l_count = l_count;
    
    net->ls = (Layer**) malloc(sizeof(Layer*) * l_count);

    for (int i = 0; i < l_count; i++)
    {
        LayerConfig cfg = config[i];
        net->ls[i] = layer_init(cfg.p_count, cfg.input_size, cfg.act_func);
    }

    return net;
}

void network_forward(Network *net, float *inputs)
{
    for (int i = 0; i < net->l_count; i++)
    {
        if (i == 0)
            layer_forward(net->ls[i], inputs);
        else
            layer_forward(net->ls[i], net->ls[i - 1]->outputs);    
    }
}

void network_backward(Network *net, float learning_rate, float *y_trues, Loss loss_func)
{
    for (int i = net->l_count - 1; i >= 0; i--)
    {
        if (i == net->l_count - 1)
            layer_backward(net->ls[i], learning_rate, y_trues, 1, loss_func);
        else
            layer_backward(net->ls[i], learning_rate, net->ls[i + 1]->input_gradients, 0, loss_func);
    }
}

void network_print_out(Network *net)
{
    printf("[");
    for (int i = 0; i < net->ls[0]->ps[0]->input_size; i++)
    {
        printf("%f", net->ls[0]->ps[0]->inputs[i]);
        if (i != net->ls[0]->ps[0]->input_size - 1)
            printf(", ");
    }
    printf("] -> [");
    for (int i = 0; i < net->ls[net->l_count - 1]->p_count; i++)
    {
        printf("%f", net->ls[net->l_count - 1]->outputs[i]);
        if (i != net->ls[net->l_count - 1]->p_count - 1)
            printf(", ");
    }
    printf("]\n");
}

void network_print_weights(Network* net)
{
    for (int i = 0; i < net->l_count; i++)
    {
        printf("Layer%d\n", i);
        for (int j = 0; j < net->ls[i]->p_count; j++)
        {
            printf("P%d\t", j);
            for (int k = 0; k < net->ls[i]->ps[j]->input_size; k++)
            {
                printf("W%d->%f ", k, net->ls[i]->ps[j]->weights[k]);
            }
            printf("b->%f\n", net->ls[i]->ps[j]->bias);
        }
    }
}

void network_free(Network **net)
{
    if (!net || !(*net))
        return;

    for (int i = 0; i < (*net)->l_count; i++)
        layer_free(&((*net)->ls[i]));

    SAFE_FREE((*net)->ls);
    SAFE_FREE(*net);
}
