#ifndef  NODE_H
#define NODE_H

#include <time.h>
#include "loc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "loc.h"
#include "moves.h"
#include "stack.h"

#define MAXI_DEPTH 5  // 5 movements possible per phase
#define MAXI_MOVES 9  // 9 movements available per phase

/**
 * @brief structure for the node of the N-ary tree
 * @param value : the node's value => the square's cost
 * @param loc : coordinates and orientation on the map
 * @param move : last move made to the node
 * @param depth : the node's depth within the tree => at which number of moves over MAXI_DEPTH
 * @param sons : the node's sons => next moves from the current node
 * @param nbSons : the number of node's sons => the number of remaining moves
 * @return the new node
 */

typedef struct s_node
{
    int value;
    t_localisation loc;
    t_move move;
    struct s_node **sons;
    int depth;
    int nbSons;
} t_node, *p_node;

/**
 * @brief structure for the node of the N-ary tree
 * @param loc : coordinates and orientation on the map
 * @param value : the node's value => the square's cost
 * @param depth : the node's depth within the tree => at which number of moves over MAXI_DEPTH
 * @param nb_sons : the maximum number of sons the node can have
 * @return the new node
 */
t_node *create_node(t_localisation loc, int value, int depth, int nb_sons);

/**
 * @brief Function to add a node to the tree
 * @param node : the node to add
 * @param father : the father of the node
 * @return void
 */
void add_node(p_node, p_node); //to be defined

void add_node_same_depth(p_node parent_node, p_node son_node);



/**
 * @brief Function to display the sons of a node
 * @param parent_node : the node to display the sons
 * @return nothing
 */
void display_level(p_node);

/**
 * @brief Function to fill the sons of a node
 * @param moves : the stack of moves
 * @param parent_node : the parent node
 * @param map : the map
 * @return the stack of moves
 */
t_stack fill_moves_node(t_stack *moves,p_node parent_node, t_map map);

#endif //NODE_H