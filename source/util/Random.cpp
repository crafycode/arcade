#include "Random.h"
#include <stdlib.h>

int getRandom(int lower, int upper)
{
    int num = (rand() %
               (upper - lower + 1)) +
              lower;
    return num;
}