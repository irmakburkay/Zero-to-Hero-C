#include <stdio.h>

#include "hutils.h"
#include "hlayer.h"


int main()
{
    random_init();
    
    int batch_size = 4;
    int input_size = 2;
    int perceptron_count = 1;
    float learning_rate = 0.1;
    int epochs = 1000;
    
    // XOR dataset
    float X[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    float y[4][1] = {{0}, {0}, {0}, {1}};

    Layer *l = layer_init(perceptron_count, input_size, SIGMOID);

    for (int e = 0; e < epochs; e++)
    {
        float total_loss = 0.0f;

        for (int i = 0; i < batch_size; i++)
        {
            layer_forward(l, X[i]);
            layer_backward(l, y[i], learning_rate, MSE);

            float layer_loss = 0.0f;
            for (int j = 0; j < l->p_count; j++)
                layer_loss += loss(y[i][j], *(l->outputs[j]), MSE);
            total_loss += layer_loss / l->p_count;
        }

        if (e % 100 == 0)
            printf("Epoch %d, loss: %f\n", e, total_loss);
    }

    printf("\nPreds:\n");
    for (int i = 0; i < batch_size; i++)
    {
        layer_forward(l, X[i]);
        layer_print_out(l);
    }

    layer_free(&l);
    return 0;
}
