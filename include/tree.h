#ifndef  TREE_H
#define TREE_H

#define MAXI_DEPTH 5  // 5 movements possible per phase
#define MAXI_MOVES 9  // 9 movements available per phase

#include "node.h"
#include "queue.h"
#include "draw.h"
#include "loc.h"
#include "stack.h"
#include "moves.h"
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
t_tree create_empty_tree(t_stack *,p_node);


void display_tree(t_node *node, int level);

int min_path(p_node node, t_stack * path);

int minnode(p_node parent);

/**
 * @brief Function to create the tree of possibilities
 * @param parent_node : the node from which we will create the tree
 * @param moves : the stack of moves that MARC can do
 * @param map : the map
 * @param max_depth : the maximum depth of the tree, that is the number of moves that MARC can do at a given phase
 */
void tree_recursive(p_node parent_node, t_stack *moves, t_map map, int max_depth);


#endif //TREE_H