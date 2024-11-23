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


t_tree recursive_tree_creation(t_map map, t_localisation loc, t_stack moves);

void tree_recursive_function(t_node *, t_stack*, t_map map);

p_node createNaryTree(t_localisation, int, int);

// functions to create the tree
void add_node_same_depth(p_node parent_node, p_node son_node);
void tree_creation(t_node *node, t_stack *moves, t_map map, int nb_move);

void display_tree(t_node *node, int level) ;



#endif //TREE_H