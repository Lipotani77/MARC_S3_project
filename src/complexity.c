//
// Created by lelia on 24/11/2024.
//

#include "../include/complexity.h"


double exec_time(clock_t start, clock_t end){
    double total_time; // We choose double type to have as much precision as we can.

    /* since clock_t  a long  integer type, we cast the values in double to not loose precision by performing the computations
    * We divide by CLOCkS_PER_SEC because clock() give us the CPU time consumed by the function (the number of ticks it took). By doing this, get the time in second.
    */
    total_time = ((double)(end - start))/CLOCKS_PER_SEC;
    return total_time;
}
