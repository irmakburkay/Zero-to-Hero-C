#include "hutils.h"
#include "hmatrix.h"
#include <stdio.h>
#include <stdlib.h>


Matrix* matrix_init(int rows, int cols, int type) { // type == 0 with zero | else random
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (float**)malloc(sizeof(float*) * rows);
    for (int i = 0; i < rows; i++)
    {
        m->data[i] = (float*)malloc(sizeof(float) * cols);
        if (type == 0)
        {
            for (int j = 0; j < cols; j++)
                m->data[i][j] = 0;            
        }
        else
        {
            float* random_values = random_number_generator(cols);
            for (int j = 0; j < cols; j++)
                m->data[i][j] = random_values[j];
            free(random_values);
        }
    }
    return m;
}

Matrix* matrix_zero(int rows, int cols) {
    return matrix_init(rows, cols, 0);
}

Matrix* matrix_random(int rows, int cols) {
    return matrix_init(rows, cols, 1);
}

Matrix* matrix_cpy(Matrix* m) {
    Matrix* cpy = (Matrix*)malloc(sizeof(Matrix));
    cpy->rows = m->rows;
    cpy->cols = m->cols;
    cpy->data = (float**)malloc(sizeof(float*) * m->rows);
    for (int i = 0; i < m->rows; i++)
    {
        cpy->data[i] = (float*)malloc(sizeof(float) * m->cols);
        for (int j = 0; j < m->cols; j++)
            cpy->data[i][j] = m->data[i][j];
    }
    return cpy;
}

Matrix* matrix_map(Matrix* m, float (*func)(float))
{
    Matrix* result = matrix_zero(m->rows, m->cols);

    for (int i = 0; i < result->rows; i++)
    {
        for (int j = 0; j < result->cols; j++)
            result->data[i][j] = func(m->data[i][j]);
    }
    return result;
}

Matrix* matrix_sum(Matrix* m1, Matrix* m2)
{
    if (m1->cols != m2->cols || m1->rows != m2->rows)
    {
        printf("Unmatched dims! (%dx%d) and (%dx%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        exit(1);
    }

    Matrix* result = matrix_zero(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++)
    {
        for (int j = 0; j < m1->cols; j++)
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
    }

    return result;
}

Matrix* matrix_dot(Matrix* m1, Matrix* m2)
{
    if (m1->cols != m2->rows)
    {
        printf("Unmatched dims! (%dx%d) and (%dx%d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        exit(1);
    }

    Matrix* result = matrix_zero(m1->rows, m2->cols);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            for (int k = 0; k < m1->cols; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }

    return result;
}

Matrix* matrix_T(Matrix* m)
{
    Matrix* result = matrix_zero(m->cols, m->rows);
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
            result->data[j][i] = m->data[i][j];
    }
    return result;
}

void matrix_print(Matrix* m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
            printf("%f ", m->data[i][j]);
        printf("\n");
    }
    printf("\n");
}

void free_matrix(Matrix** m) {
    if (!m || !(*m)) return;
    if ((*m)->data)
    {
        for (int i = 0; i < (*m)->rows; i++) 
            free((*m)->data[i]);
        free((*m)->data);
    }
    free(*m);
    *m = NULL;
}

BatchMatrix* batchMatrix_init(int batch_size, int row, int col)
{
    BatchMatrix* bM = (BatchMatrix*)malloc(sizeof(BatchMatrix));
    bM->batch_size = batch_size;
    bM->rows = row;
    bM->cols = col;
    bM->matrix = (Matrix**)malloc(sizeof(Matrix*) * batch_size);
    for (int i = 0; i < batch_size; i++)
        bM->matrix[i] = matrix_zero(row, col);
    return bM;
}

void batchMatrix_print(BatchMatrix* bM)
{
    for (int i = 0; i < bM->batch_size; i++)
        matrix_print(bM->matrix[i]);
}

void free_batchMatrix(BatchMatrix** bM)
{
    if (!bM || !(*bM)) return;
    if ((*bM)->matrix)
    {
        for (int i = 0; i < (*bM)->batch_size; i++) {
            if ((*bM)->matrix[i] != NULL) {
                free_matrix(&(*bM)->matrix[i]);
            }
        }
        free((*bM)->matrix);
        (*bM)->matrix = NULL;
    }
    free(*bM);
    *bM = NULL;
}
