#ifndef UNTITLED1_COMPLEXITY_H
#define UNTITLED1_COMPLEXITY_H

#include <time.h>



/*
 * The goal is to create a function that will take in parameter a starting time and an ending time and compute the time execution based on these two values.
 * e.g : When we will create the tree, we will put at the first line of the function making the tree a variable containing the start time.
 * The before before last line of the function will be a new variable with the end time, the penultimate line will be the call of the clock function to compute the time execution based on the 2 arguments which will be the start and end time.
 */

/**
 * @param start // Starting time of the function computed by clock()
 * @param end // Ending time of the function computed by clock()
 * @return total_time // the elapsed time of the function
 */
double exec_time(clock_t start, clock_t end);

#endif //UNTITLED1_COMPLEXITY_H