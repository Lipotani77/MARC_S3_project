#include "../include/complexity.h"
#include <time.h>


double exec_time(clock_t start, clock_t end){
    double total_time; // We choose double type to have as much precision as we can.

    /* since clock_t  a long  integer type, we cast the values in double to not loose precision by performing the computations
    * We divide by CLOCkS_PER_SEC because clock() give us the CPU time consumed by the function (the number of ticks it took). By doing this, get the time in second.
    */
    total_time = (1000.0*(double)(end - start))/CLOCKS_PER_SEC; //Total time in milliseconds
    return total_time;
}


