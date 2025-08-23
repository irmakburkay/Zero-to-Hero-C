#ifndef HLOSS
#define HLOSS


typedef enum
{
    MSE,
    RMSE
} Loss;

float mse(float y_true, float y_pred);
float d_mse(float y_true, float y_pred);
float loss(float y_true, float y_pred, Loss loss_func);
float d_loss(float y_true, float y_pred, Loss loss_func);

#endif