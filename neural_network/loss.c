#include "hloss.h"


float mse(float y_true, float y_pred)
{
    float diff = y_true - y_pred;
    return 0.5f * diff * diff;
}

float d_mse(float y_true, float y_pred)
{
    return y_true - y_pred;
}

float loss(float y_true, float y_pred, Loss loss_func)
{
    switch (loss_func)
    {
        case MSE:
        return mse(y_true, y_pred);
    }
}

float d_loss(float y_true, float y_pred, Loss loss_func)
{
    switch (loss_func)
    {
        case MSE:
        return d_mse(y_true, y_pred);
    }
}
