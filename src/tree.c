#include "../include/tree.h"
#define NB_SONS  7


t_tree create_tree(t_stack *drawn_moves,p_node root){
    p_tree new_tree = (p_tree)malloc(sizeof(t_tree));
    new_tree->root = root;
    //p_node current_node = root;
    return *new_tree ;
}



void fill_moves_node(t_stack *moves, int* t_moves,p_node parent_node, t_map map){
    t_stack moves_stack_copy = copy_stack(*moves); // a copy of the stack given in parameter that we will use for the transition queue
    t_queue transition_queue = createQueue(MAXI_MOVES); // this is temp queue to remove the move that we used

    while (is_stack_empty(moves) != 1){ // we want to add all the moves to the parent node
        // have to create the new node we want to add
        // but first we have to find all its component
        int poped_move = pop(moves); // retrieve the move on the top of the stack
        // But first we have to compute the value of the new node : that is the cost associated with the poped move
        t_localisation new_localisation = move(parent_node->loc, poped_move); //that's what we do here
        // now we have to retrieve the cost associated to this new localisation
        int new_cost = map.costs[new_localisation.pos.x][new_localisation.pos.y];
        // maybe we have to retrieve the depth but don't know now so we skip it
        int new_depth = parent_node->depth + 1;
        // finaly we need to the number of sons
        int nb_sons = MAXI_MOVES - new_cost;
        // now we have all the component to initialize the new node
        p_node node_to_add = create_node(new_localisation, new_cost, new_depth, nb_sons);
        // we have initialized the new node to add, so now we add it
        add_node_same_depth(parent_node,node_to_add);

        //now we want to destack everything from the copied stack and put it into a temp queue


        enqueue(&transition_queue,)

    }
}