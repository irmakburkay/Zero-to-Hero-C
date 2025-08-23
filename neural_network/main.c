#include "hutils.h"
#include "hperceptron.h"
#include <stdio.h>

int main()
{
    random_init();
    
    float learning_rate = 0.1;
    int epochs = 1000;
    
    // AND dataset
    float X[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    float y[4] = {0, 0, 0, 1};

    Perceptron *p = perceptron_init(2, SIGMOID);

    for (int e = 0; e < epochs; e++)
    {
        float total_loss = 0.0f;
        for (int i = 0; i < 4; i++)
        {
            float pred = perceptron_forward(p, X[i]);
            perceptron_backward(p, y[i], learning_rate, MSE);
            total_loss += loss(y[i], pred, MSE);
        }
        if (e % 100 == 0)
            printf("Epoch %d, loss: %f\n", e, total_loss);
    }

    printf("\nPreds:\n");
    for (int i = 0; i < 4; i++)
    {
        float pred = perceptron_forward(p, X[i]);
        printf("[%d, %d] -> %f\n", (int)X[i][0], (int)X[i][1], pred);
    }

    perceptron_free(&p);
    return 0;
}
