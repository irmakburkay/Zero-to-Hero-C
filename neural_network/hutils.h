#define SAFE_FREE(ptr)    \
    do                    \
    {                     \
        if (ptr)          \
        {                 \
            free(ptr);    \
            (ptr) = NULL; \
        }                 \
    } while (0)

#ifndef HUTILS
#define HUTILS

#include <stdlib.h>

void random_init();
float random_float();
float xavier_init(int input_size);

#endif
