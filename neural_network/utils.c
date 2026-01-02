#include <time.h>
#include <math.h>

#include "hutils.h"


void random_init()
{
    srand(time(NULL));
    // Warm up the random number generator
    for (int i = 0; i < 10; i++) {
        rand();
    }
}

float random_float()
{
    return ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
}

float xavier_init(int input_size)
{
    float limit = sqrt(6.0f / (input_size + 1));
    return ((float)rand() / RAND_MAX) * 2.0f * limit - limit;
}
