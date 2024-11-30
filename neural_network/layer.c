#include "hutils.h"
#include "hlayer.h"
#include <stdlib.h>


Layer* layer_init(int row, int col, int unit, float (*act_func)(float))
{
    Layer* layer = (Layer*)malloc(sizeof(Layer));
    layer->row = row;
    layer->col = col;
    layer->unit = unit;
    layer->act_func = act_func;
    layer->weights = matrix_random(row, unit);
    layer->biases = matrix_zero(unit, col);
    return layer;
}

Matrix* layer_forward(Layer* layer, Matrix* inputs)
{
    Matrix* dot_result = matrix_dot(matrix_T(layer->weights), inputs);
    Matrix* sum_result = matrix_sum(dot_result, layer->biases);
    Matrix* result = matrix_map(sum_result, layer->act_func);

    free_matrix(&dot_result);
    free_matrix(&sum_result);

    return result;
}

void free_layer(Layer** l)
{
    if (!l || !(*l)) return;
    if ((*l)->biases) 
        free_matrix(&(*l)->biases);
    if ((*l)->weights)
        free_matrix(&(*l)->weights);
    free(*l);
    *l = NULL;
}
