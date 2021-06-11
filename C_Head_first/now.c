#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "now.h"

char* now()
{
    time_t t;
    time (&t);
    return asctime(localtime (&t));
}