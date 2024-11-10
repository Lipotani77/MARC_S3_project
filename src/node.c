#include "../include/node.h"
#include <stdio.h>
#include <malloc.h>


// create node function
p_node createNode(int val, int nb_sons){
    p_node new_node;
    new_node = (p_node)malloc(sizeof(p_node));
    new_node->value = val;
    new_node->nbSons = nb_sons; //nb_sons = 9 - level of the node
    for(int i=0; i<nb_sons; i++){
        new_node->sons[i] = NULL;
    }
    return new_node;
}