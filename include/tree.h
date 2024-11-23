#ifndef  TREE_H
#define TREE_H

#define MAXI_DEPTH 5  // 5 movements possible per phase
#define MAXI_MOVES 9  // 9 movements available per phase

#include "node.h"
#include "queue.h"
#include "draw.h"
#include "loc.h"
#include "stack.h"
#include "../include/tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/moves.h"

/**
 * @brief structure for the N-ary tree
 * @param root : the root's node of the tree => Starting point of MARC
 * @return the new tree
 */
typedef struct
{
    t_node *root;
} t_tree, *p_tree;

/**
 * @brief Function to create a tree
 * @param node : cost of the node
 * @param x_dep : the x position of the departure point of MARC
 * @param y_dep : the y position of the departure point of MARC
 * @param orientation : orientation of MARC at the beginning of the a phase
 * @param move : here at the creation of the tree we will set the value to "start"
 * @return the node
 */
t_tree create_tree(t_stack *,p_node);

/**
 *
 * @param moves the stack that contains all the move at a time t
 * @param t_moves the array for the taken moves by MARC because we don't want to reuse the move from where we come from
 * @param parent_node the node from where we start
 * @param map the map
 */
t_stack fill_moves_node(t_stack *moves,p_node parent_node, t_map map);



#endif //TREE_H