/*
 * tree.h
 *
 *  Created on: 2018年7月3日
*/
#ifndef  TREE_H
#define TREE_H
#include "node.h"

typedef  struct N_ary_tree
{
    p_node root; // the root of the tree, its position is the position of the robot when the phase starts
} tree;

tree create_tree();


#endif //TREE_H