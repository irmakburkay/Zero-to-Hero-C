#ifndef hmatrix
#define hmatrix

typedef struct {
    int rows;
    int cols;
    float** data;
} Matrix;

Matrix* matrix_init(int, int, int);
Matrix* matrix_zero(int, int);
Matrix* matrix_random(int, int);
Matrix* matrix_cpy(Matrix*);
Matrix* matrix_map(Matrix*, float (*)(float));
Matrix* matrix_sum(Matrix*, Matrix*);
Matrix* matrix_dot(Matrix*, Matrix*);
Matrix* matrix_T(Matrix*);
void matrix_print(Matrix*);
void free_matrix(Matrix**);

typedef struct {
    int batch_size;
    int rows;
    int cols;
    Matrix** matrix;
} BatchMatrix;

BatchMatrix* batchMatrix_init(int, int, int);
void batchMatrix_print(BatchMatrix*);
void free_batchMatrix(BatchMatrix**);

#endif