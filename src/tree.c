#include "../include/tree.h"
#define NB_SONS  7

t_tree create_tree(t_stack *drawn_moves,p_node root){
    p_tree new_tree = (p_tree)malloc(sizeof(t_tree));
    new_tree->root = root;
    //p_node current_node = root;
    return *new_tree ;
}

/*
void tree_recursive_function(t_node *node, t_stack *moves, t_map map)
*/
