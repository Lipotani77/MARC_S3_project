#include "../include/tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/moves.h"
#define NB_SONS  7

t_tree create_tree(t_node *node)
{
    t_tree tree;
    tree.root = node;

    return tree;
}

t_tree recursive_tree_creation(t_map map, t_localisation loc){


    int depth = 0 ;

    t_node * node = create_node(loc, map.costs[loc.pos.x][loc.pos.y], depth , NB_SONS - depth);

    t_tree  tree = create_tree(node) ;


    return tree ;
}

void tree_recursive_function(t_node * node, t_stack moves, t_map map){

    t_node * temp ;
    int stop = 0 ;
    t_stack save ;
    t_move move1 ;
    t_localisation new_loc ;

    while (stop < NB_SONS - node->depth){

        move1 = pop(&moves);

        push(&save, move1);

        new_loc = move(node->loc, move1) ;

        temp = create_node(new_loc, map.costs[new_loc.pos.x][new_loc.pos.y], node->depth + 1, NB_SONS - (node->depth+1));

        node->sons[stop] = temp;


        stop ++ ;
    }


}