#include <math.h>

#include "hloss.h"


float mse(float y_true, float y_pred)
{
    float diff = y_true - y_pred;
    return diff * diff;
}

float d_mse(float y_true, float y_pred)
{
    return 2 * (y_pred - y_true);
}

float rmse(float y_true, float y_pred)
{
    return abs(y_true - y_pred);
}

float d_rmse(float y_true, float y_pred)
{
    if (y_true > y_pred)
        return -1;
    if (y_pred > y_true)
        return 1;
    return 0;
}

float loss(float y_true, float y_pred, Loss loss_func)
{
    switch (loss_func)
    {
        case MSE:
            return mse(y_true, y_pred);
        case RMSE:
            return rmse(y_true, y_pred);
    }
}

float d_loss(float y_true, float y_pred, Loss loss_func)
{
    switch (loss_func)
    {
        case MSE:
            return d_mse(y_true, y_pred);
        case RMSE:
            return d_rmse(y_true, y_pred);
    }
}
