#include "../include/tree.h"
#define NB_SONS  7

t_tree create_tree(t_stack *drawn_moves,p_node root){
    p_tree new_tree = (p_tree)malloc(sizeof(t_tree));
    new_tree->root = root;
    //p_node current_node = root;
    return *new_tree ;
}

/*
t_tree recursive_tree_creation(t_map map, t_localisation loc, t_stack moves){


    int depth = 0 ;

    t_node * node = create_node(loc, map.costs[loc.pos.x][loc.pos.y], depth , NB_SONS - depth);

    t_tree tree ;
    tree = create_tree(&moves, node);

    tree_recursive_function(node, &moves, map);

    return tree ;
}

void tree_recursive_function(t_node *node, t_stack *moves, t_map map) {

    // Condition to stop the recursion
    if (node->depth >= MAXI_DEPTH || NB_SONS - node->depth <= 0) {
        return;
    }

    int stop = 0;

    while (stop < NB_SONS - node->depth) {
        if (is_stack_empty(moves)) {
            break;
        }

        t_move move1 = pop(moves);
        t_localisation new_loc = move(node->loc, move1);

        if (!isValidLocalisation(new_loc.pos, new_loc.pos.x, new_loc.pos.y)) {
            stop++;
            continue;
        }

        t_node *temp = create_node(new_loc, map.costs[new_loc.pos.x][new_loc.pos.y],node->depth + 1, NB_SONS - (node->depth + 1));
        temp->move = move1;
        node->sons[stop] = temp;

        t_stack moves_for_recursion = copy_stack(*moves);
        removevalfromstack(&moves_for_recursion, move1);

        tree_recursive_function(node->sons[stop], &moves_for_recursion, map);

        stop++;
        free_stack(moves_for_recursion);
    }
}
*/

void add_node_same_depth(p_node parent_node, p_node son_node){
    parent_node->sons[parent_node->nbSons] = son_node;
    parent_node->nbSons++;
}

void tree_creation(t_node *node, t_stack *moves, t_map map, int nb_move){
    t_stack *drawn_move = moves;
    for(int i = 0; i < nb_move; i++){
        int p = 7;
    }
}
