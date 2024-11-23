#include "../include/node.h"

t_node *create_node(t_localisation loc, int value, int depth, int nb_sons){
    p_node new_node = (p_node)malloc(sizeof(t_node));
    new_node->value = value;
    new_node->loc = loc;
    new_node->move = NONE; // we created an enum for no move
    // initialize the sons of the node to NULL
    if(nb_sons > 0){
        new_node->sons = (t_node **) malloc(nb_sons * sizeof(t_node*));
        for(int i = 0; i < nb_sons; i++){
            new_node->sons[i] = NULL;
        }
    }
    else{
        new_node->sons = NULL;
    }
    new_node->depth = depth;
    new_node->nbSons = 0;
    new_node->maxSons = nb_sons;
    return new_node;
}

void display_level(p_node parent_node){
    if (parent_node->sons[0] == NULL){
        printf("This node has no sons node\n");
    }
    else{
        printf("The son(s) of the parent node %d are : \n",parent_node->value);
        printf("[ ");
        for(int i = 0; i < parent_node->nbSons; i++){
            printf("%d ", parent_node->sons[i]->value);
        }
        printf("]\n");
    }
}