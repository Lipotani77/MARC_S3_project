//
// Created by lelia on 24/11/2024.
//

#include "../include/complexity.h"
#include <time.h>


double exec_time(struct timeval start, struct timeval end){
    double total_time; // We choose double type to have as much precision as we can.

    /* since clock_t  a long  integer type, we cast the values in double to not loose precision by performing the computations
    * We divide by CLOCkS_PER_SEC because clock() give us the CPU time consumed by the function (the number of ticks it took). By doing this, get the time in second.
    */
    total_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1e6;
    return total_time;
}


