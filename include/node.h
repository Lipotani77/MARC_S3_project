#ifndef  NODE_H
#define NODE_H
#define ACTION_SIZE 9
#include <time.h>
#include "loc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "moves.h"

/**
 * @brief Structure of a node
*/
typedef struct s_node
{
    /**
    int value; // the cost of the node
    int map_pos[2]; // x, y
    int xn,yn;
    struct s_node *sons[ACTION_SIZE];
    int nbSons;
    int LS; // 5 - the depth of the node
    */
    int value; // the cost of the node
    t_localisation loc; // the position of the node
    t_move move; // the move that have been achieved to arrive to this node
    struct s_node *sons[ACTION_SIZE]; // the sons of the node
    int depth; // the depth of the node, to be initialized to 0, and should not exceed 5 or 4 as a phase has 5 or 4 moves
    int nb_children; // the number of children of the node, we will decrement it each time we are going more in depth it should be initialized to 9
} t_node, *p_node;

/**
 * @brief Function to create a node
 * @param cost : the cost of the node
 * @param x : the x position of the node
 * @param y : the y position of the node
 * @param orientation : the orientation of the rover
 * @param move : the move that have been achieved to arrive to this node
 * @return a pointer to the node
 */
p_node create_node(int, int, int, t_orientation, char *);

void add_node(); //to be defined


p_node createNode(int val, int nb_sons);
#endif //NODE_H