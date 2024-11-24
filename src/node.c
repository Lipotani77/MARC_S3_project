#include "../include/node.h"

t_node *create_node(t_localisation loc, int value, int depth, int nb_sons){
    p_node new_node = (p_node)malloc(sizeof(t_node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation for a new_node failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->loc = loc;
    new_node->move = NONE; // we created an enum for no move
    // initialize the sons of the node to NULL
    if(nb_sons > 0){
        new_node->sons = (t_node **) malloc(nb_sons * sizeof(t_node*));
        if (new_node->sons == NULL) {
            fprintf(stderr, "Memory allocation for sons of a new_node failed\n");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < nb_sons; i++){ // initialize the sons to NULL
            new_node->sons[i] = NULL;
        }
    }
    else{
        new_node->sons = NULL;
    }
    new_node->depth = depth;
    new_node->nbSonsMax = nb_sons;
    new_node->nbSons = 0;
    return new_node;
}

void display_level(p_node parent_node){
    if (parent_node->sons[0] == NULL){
        printf("This node has no sons node\n");
        return;
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

void add_node_same_depth(p_node parent_node, p_node son_node){
    parent_node->sons[parent_node->nbSons] = son_node;
    parent_node->nbSons++;
}

//second draft
t_stack fill_moves_node(t_stack *moves,p_node parent_node, t_map map){
    t_stack moves_stack_copy = copy_stack(*moves); // a copy of the stack given in parameter that we will use for the transition queue

    while(is_stack_empty(moves) != 1){ // we want to add all the moves to the parent node
        // have to create the new node we want to add
        // But first we have to find all its component
        int poped_move = pop(moves); // retrieve the move on the top of the stack
        t_move converted_move = (t_move)poped_move;

        // But first we have to compute the value of the new node : that is the cost associated with the poped move
        t_localisation new_localisation = move(parent_node->loc, converted_move); //that's what we do here


        // now we have to retrieve the cost associated to this new localisation
        int new_cost = retrieve_cost(new_localisation,map);


        // maybe we have to retrieve the depth but don't know now, so we skip it
        int new_depth = parent_node->depth + 1;


        // finally we need to the number of sons
        int nb_sons = MAXI_MOVES - new_depth;


        // now we have all the component to initialize the new node
        p_node node_to_add = create_node(new_localisation, new_cost, new_depth, nb_sons);
        //printf("The node to add has the following value : %d\n",node_to_add->value);


        // we have initialized the new node to add, so now we add it
        add_node_same_depth(parent_node,node_to_add);
    }
    return moves_stack_copy;
}

void display_info_node(p_node node){
    printf("The node has the following value : %d\n",node->value);
    printf("The node has the following depth : %d\n",node->depth);
    printf("The node has the following number of sons : %d\n",node->nbSons);
    printf("The node has the following localisation : x = %d, y = %d, orientation = %d\n",node->loc.pos.x,node->loc.pos.y,node->loc.ori);
    printf("The node can have at most %d sons\n",node->nbSonsMax);
}