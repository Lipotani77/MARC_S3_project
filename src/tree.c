#include "../include/tree.h"
#define NB_SONS  7

t_tree create_tree(t_stack *drawn_moves,p_node root){
    p_tree new_tree = (p_tree)malloc(sizeof(t_tree));
    new_tree->root = root;
    //p_node current_node = root;
    return *new_tree ;
}


t_tree recursive_tree_creation(t_map map, t_localisation loc, t_stack moves){


    int depth = 0 ;

    t_node * node = create_node(loc, map.costs[loc.pos.x][loc.pos.y], depth , NB_SONS - depth);

    t_tree tree ;
    tree = create_tree(&moves, node);

    tree_recursive_function(node, moves, map);

    return tree ;
}

void tree_recursive_function(t_node * node, t_stack moves, t_map map){

    t_node * temp ;
    int stop = 0 ;
    t_stack untouched_save = moves ;
    t_stack moves_for_recursion = moves ;
    t_move move1 ;
    t_localisation new_loc ;

    while (stop < NB_SONS - node->depth){

        move1 = pop(&moves);

        //push(&save, move1);

        new_loc = move(node->loc, move1) ;

        temp = create_node(new_loc, map.costs[new_loc.pos.x][new_loc.pos.y], node->depth + 1, NB_SONS - (node->depth+1));

        temp->move = move1 ;

        node->sons[stop] = temp;

        removevalfromstack(&moves_for_recursion, move1);

        tree_recursive_function(node->sons[stop], moves_for_recursion, map);
        //add recursion here : you need the node you just created, the set of possible moves and just pass the map for
        // node creation (useful to get the cost of each location).

        stop ++ ;
    }


}



/*
p_node createNaryTree(t_localisation startLoc, int startValue, int depth) {
    t_stack hand = draw_hand();
    p_node root = create_node(startValue, startLoc, NONE, 0);

    if (depth == 0) return root;

    for (int i = 0; i < 9; i++) { //iterate through the 9 sons of the root that are the one that we drew at the beginning of a phase
        t_move move = pop(&hand);

        t_localisation newLoc = applyMove(startLoc, move); // Implement this function to update location based on move, Idrissa function
        int newValue = getValue(newLoc); // Implement this function to get the value of the new location
        p_node newNode = createNode(newValue, newLoc, move, depth - 1);

        add_node(root, newNode); // Implement this function to add a son to a node
        if (depth > 1) { // have to put here all the conditions to stop the recursion as for example if the rover dies
            addSon(root, createNaryTree(newLoc, newValue, depth - 1));
        }
    }
    return root;
}
*/