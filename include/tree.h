/*
 * tree.h
 *
 *  Created on:
*/
#ifndef  TREE_H
#define TREE_H
#include "node.h"

/**
 * @brief Structure of a node
 */


typedef  struct N_ary_tree
{
    p_node root; // the root of the tree, its position is the position of the robot when the phase starts
} tree;

/**
 * @brief Function to create a tree
 * @param cost : cost of the node
 * @param x_dep : the x position of the departure point of MARC
 * @param y_dep : the y position of the departure point of MARC
 * @param orientation : orientation of MARC at the beginning of the a phase
 * @param move : here at the creation of the tree we will set the value to "start"
 * @return the node
 */
tree create_tree(int, int, int, t_orientation, char *);


#endif //TREE_H