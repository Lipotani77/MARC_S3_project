#ifndef  NODE_H
#define NODE_H
#define ACTION_SIZE 9
#include <time.h>
#include "loc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
    int cost; // the cost of the node
    int x; // x position of the node in the map so the position of the robot if it goes to this node
    int y; // y position of the node in the map so the position of the robot if it goes to this node
    t_orientation orientation; // orientation of the robot
    char move[20]; // the move that led to this node
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

/**
 * @brief Function to find the cost at given coordinates
 * @param x : the i index of the cost which is also the x position
 * @param y : the j index of the cost which is also the y position
 * @param map : the map with the cost we need
 * @return cost : the cost of the position we are
 */
int cost_node(int x, int y, t_map map);
#endif //NODE_H