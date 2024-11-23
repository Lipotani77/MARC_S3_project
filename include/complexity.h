#ifndef UNTITLED1_COMPLEXITY_H
#define UNTITLED1_COMPLEXITY_H

#include <time.h>
/* General Idea
 * we call the clock function at the beginning and at the end of the function
 then, we substract them and divide it by CLOCKS_PER_SEC to get the processor time
 * I will add it to the structure so it is easier to get it at the end (I guess)
 */


//•	The tree construction phase with time_tree
/* time_tree
 * t_tree tree_construction (a, b, c){
        clock_t time_tree;
        double time
        time_tree = clock()
        //description of the function
        time_tree = (clock() - time_tree;
        double time_taken = ((double)t)/CLOCKS_PER_SEC


  }
 */



//•	The search for a leaf with the minimum value among all the leaves in the tree with time leaf

//•	Calculating the path from the root to this leaf ; time_path?



/* The goal is to create a function that will take in parameter a starting time and an ending time and compute the time execution based on these two values.
 * e.g : When we will create the tree, we will put at the first line of the function making the tree a variable containing the start time.
 * The before before last line of the function will be a new variable with the end time, the penultimate line will be the call of the clock function to compute the time execution based on the 2 arguments which will be the start and end time.
 * Finally the last line of the tree making function will display the clock than only return the tree. */





#endif //UNTITLED1_COMPLEXITY_H