#ifndef  NODE_H
#define NODE_H

#include <time.h>
#include "loc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "loc.h"

#define MAXI_DEPTH 5  // 5 movements possible per phase
#define MAXI_MOVES 9  // 9 movements available per phase

/**
 * @brief structure for the node of the N-ary tree
 * @param loc : coordinates and orientation on the map
 * @param value : the node's value => the square's cost
 * @param depth : the node's depth within the tree => at which number of moves over MAXI_DEPTH
 * @param sons : the node's sons => next moves from the current node
 * @param nbSons : the number of node's sons => the number of remaining moves
 * @return the new node
 */

typedef struct s_node
{
    t_localisation loc;
    int value;
    int depth;
    struct s_node **sons;
    int nb_sons; // Physical size of the array
} t_node;


t_node *create_node(t_localisation, int, int, int);




#endif //NODE_H