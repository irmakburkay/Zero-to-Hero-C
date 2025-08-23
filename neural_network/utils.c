#include "hutils.h"
#include <stdlib.h>
#include <time.h>

void random_init()
{
    srand(time(NULL));
    rand(); // first random number looks same always
}

float random_float()
{
    return ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
}
