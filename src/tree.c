#include "../include/tree.h"
#define NB_SONS  7


t_tree create_empty_tree(t_stack *drawn_moves,p_node root){
    p_tree new_tree = (p_tree)malloc(sizeof(t_tree));
    new_tree->root = root;
    //p_node current_node = root;
    return *new_tree ;
}


/* first draft
void fill_moves_node(t_stack *moves, int* t_moves,p_node parent_node, t_map map){
    t_stack moves_stack_copy = copy_stack(*moves); // a copy of the stack given in parameter that we will use for the transition queue
    t_queue_int transition_queue = createQueue_int(MAXI_MOVES); // this is temp queue to remove the move that we used

    while (is_stack_empty(moves) != 1){ // we want to add all the moves to the parent node
        // have to create the new node we want to add
        // But first we have to find all its component
        int poped_move = pop(moves); // retrieve the move on the top of the stack
        // But first we have to compute the value of the new node : that is the cost associated with the poped move
        t_localisation new_localisation = move(parent_node->loc, poped_move); //that's what we do here
        // now we have to retrieve the cost associated to this new localisation
        int new_cost = map.costs[new_localisation.pos.x][new_localisation.pos.y];
        // maybe we have to retrieve the depth but don't know now, so we skip it
        int new_depth = parent_node->depth + 1;
        // finally we need to the number of sons
        int nb_sons = MAXI_MOVES - new_cost;
        // now we have all the component to initialize the new node
        p_node node_to_add = create_node(new_localisation, new_cost, new_depth, nb_sons);
        // we have initialized the new node to add, so now we add it
        add_node_same_depth(parent_node,node_to_add);

        //now we want to destack everything from the copied stack and put it into a temp queue
        while(is_stack_empty(&moves_stack_copy) != 1){ // destack everything from the copied stack and put it into the temp queue
            int move = pop(&moves_stack_copy); // retrieve the move on the top of the stack
            new_enqueue(&transition_queue,move); // put it into the temp queue
        }
        //now we need to dequeue till the penultimate element and put it back into the copied stack
        // the last element of the queue will be put in the array of taken movement by MARC, so that we don't use it again
        int pos = 0; // index that will help us reach the penultimate element
        while(pos != transition_queue.last-1){ // dequeue till the penultimate element
            int move = new_dequeue(&transition_queue); // retrieve the move at the beginning of the queue
            push(moves,move); // put it back into the original stack
            push(&moves_stack_copy,move); // put it back into the copied stack
            pos++;
        }
        t_moves[pos] = move; // put it into the array of taken movement by MARC
    }
}*/

void display_tree(t_node *node, int level) {
    if (node == NULL) return;


    for (int i = 0; i < level; i++) {
        printf("  "); // Indentation
    }
    printf("%d\n", node->value);


    for (int i = 0; i < node->nbSons; i++) {
        display_tree(node->sons[i], level + 1);
    }
}

int min_path(p_node node, t_stack * path){

    if(node->nbSons==0 ||node->depth > 5){
        return 0 ;
    }

    int min_idx = minnode(node);
    push(path, node->sons[min_idx]->move);

    display_level(node);
    for (int i = 0 ; i < node->nbSons ; i++) {
        printf("%s  | ", getMoveAsString(node->sons[i]->move));
    }
    printf("\n");
    return node->sons[min_idx]->value +  min_path(node->sons[min_idx], path);
}

int minnode(p_node parent){

    int min = parent->sons[0]->value;
    int min_idx = 0 ;
    for (int i = 1 ; i < parent->nbSons ; i++){
        if(parent->sons[i] == NULL){
            continue ;
        }
        if(parent->sons[i]->value < min){
            min = parent->sons[i]->value ;
            min_idx = i ;
        }
    }
    return min_idx;
}


void tree_recursive(p_node parent_node, t_stack *moves, t_map map, int max_depth) {
    // If the depth of the parent node is greater than the maximum depth, we stop the recursion
    // We can put further conditions to stop the recursion
    if (parent_node->depth >= max_depth) {
        //printf("The maximum depth has been reached\n");
        return;
    }

    // fill the sons of the parent node given in parameter
    fill_moves_node(moves, parent_node, map);

    //printf("\nici ca marche\n");
    // apply the recursion for each son of the parent node
    for (int i = 0; i < parent_node->nbSons; i++) {
        // retrieve the current son
        p_node child_node = parent_node->sons[i];

        //change the moves stack because we have to remove the move that we used that is the move of the current child node
        t_stack moves_copy = remove_current_move_from_stack(moves, child_node->move); // the stack does not contain the move used to come to this node

        // apply the recursion for the current son
        //printf("entering recursion ");
        tree_recursive(child_node, &moves_copy, map, max_depth);
    }
}