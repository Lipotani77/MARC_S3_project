#include "../include/node.h"

p_node create_node(int cost, int x, int y, t_orientation orientation, char *move)
{
    p_node new_node = (p_node)malloc(sizeof(t_node));
    if (new_node == NULL)
    {
        printf("Memory allocation for a new node failed\n");
    }
    new_node->cost = cost; // the cost of the node
    new_node->x = x; // x position of the node in the map so the position of the robot if it goes to this node
    new_node->y = y; // y position of the node in the map so the position of the robot if it goes to this node
    new_node->orientation = orientation; // orientation of the robot
    strcpy(new_node->move, move); // the move that led to this node
    new_node->depth = 0; // the depth of the node, to be initialized to 0, and should not exceed 5 or 4 as a phase has 5 or 4 moves
    new_node->nb_children = ACTION_SIZE; // the number of children of the node, we will decrement it each time we are going more in depth it should be initialized to 9
    for (int i = 0; i < ACTION_SIZE; i++) // the sons of the node
    {
        new_node->sons[i] = NULL; // initialize the sons to NULL as we don't have any children yet
    }
    return new_node;
}


//first versiont of cost_node
// Function to find the cost of a given coordinate
int cost_node(int x, int y){
    //Idea : In the node I have the cost and the position. SO what I can do is to compare the cost of the nodes.
    // for that I need a tree I THINK
    // Maybe I cand do it with recursivity ?

}