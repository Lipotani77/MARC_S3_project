#ifndef  NODE_H
#define NODE_H

#include <time.h>
#include "loc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "loc.h"
#include "moves.h"

#define MAXI_DEPTH 5  // 5 movements possible per phase
#define MAXI_MOVES 9  // 9 movements available per phase

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

    int value; // the cost of the node
    t_localisation loc; // the position of the node
    t_move move; // the move that have been achieved to arrive to this node
    struct s_node *sons[MAXI_MOVES]; // the sons of the node
    int depth; // the depth of the node, to be initialized to 0, and should not exceed 5 or 4 as a phase has 5 or 4 moves
    int nb_children; // the number of children of the node, we will decrement it each time we are going more in depth it should be initialized to 9
} t_node, *p_node;

t_node *create_node(t_localisation, int, int, int);

void add_node(); //to be defined



#endif //NODE_H