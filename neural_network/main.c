#include <stdio.h>

#include "hutils.h"
#include "hnetwork.h"


int main()
{

    /*----------------------CONFIGS---------------------*/
    // XOR dataset
    float X[4][2] = {{0.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}};
    float y[4][1] = {{0.0f}, {1.0f}, {1.0f}, {0.0f}};
    
    // Layer configs
    LayerConfig configs[] = 
    {
        {2, 2, SIGMOID},
        {2, 1, SIGMOID},
    };

    // Training configs
    float learning_rate = 0.5f; 
    int epochs = 10000; 
    Loss loss_func = MSE;
    /*--------------------------------------------------*/

    random_init();

    int layer_count = (int) (sizeof(configs) / sizeof(LayerConfig));
    int input_size = (int) (sizeof(X[0]) / sizeof(float));
    int num_sample = (int) (sizeof(X) / sizeof(float) / input_size);


    Network *net = network_init(configs, layer_count);

    for (int e = 0; e < epochs; e++)
    {
        float total_loss = 0.0f;

        for (int i = 0; i < num_sample; i++)
        {
            network_forward(net, X[i]);
            network_backward(net, learning_rate, y[i], loss_func);

            float layer_loss = 0.0f;
            for (int j = 0; j < net->ls[net->l_count - 1]->p_count; j++)
                layer_loss += loss(y[i][j], net->ls[net->l_count - 1]->outputs[j], loss_func);
            total_loss += layer_loss / net->ls[net->l_count - 1]->p_count;
        }

        if (e % 1000 == 0 || e == epochs - 1)
            printf("Epoch %d, loss: %f\n", e, total_loss);
    }


    for (int i = 0; i < net->l_count; i++)
    {
        printf("Layer%d\n", i);
        Layer *temp_l = net->ls[i];
        for (int j = 0; j < temp_l->p_count; j++)
        {
            printf("P%d\t", j);
            Perceptron *temp_p = temp_l->ps[j];
            for (int k = 0; k < temp_p->input_size; k++)
                printf("W%d->%f ", k, temp_p->weights[k]);
            printf("b->%f\n", temp_p->bias);
        }
    }

    printf("\nPreds:\n");
    for (int i = 0; i < num_sample; i++)
    {
        network_forward(net, X[i]);
        network_print_out(net);
    }

    network_free(&net);
    return 0;
}
