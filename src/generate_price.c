#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../header/generate_price.h"

int Generate_Price(int min, int max) {
    return min + rand() % (max - min + 1);
}