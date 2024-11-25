#include "../include/tree.h"
#define NB_SONS  7

// this function is simply to allocate memory to a tree and return the empty tree
t_tree create_empty_tree(t_stack *drawn_moves,p_node root){
    // we alloc space fo the tree
    p_tree new_tree = (p_tree)malloc(sizeof(t_tree));
    // we link the root to the tree
    new_tree->root = root;
    // and we return the new tree
    return *new_tree ;
}
// this function is simply useful to reduce the amount of lines in the main creation function and simplify readability



//this function is the recursive function that allows to choose the best path
int min_path(p_node node, t_stack * path){

    //base case of the recursion : if we are at the maximum depth or if we reach a leaf with no sons, we stop
    if(node->nbSons==0 ||node->depth > 5){
        return 0 ;
    }
    //else we start the computation of the path
    //we find the best choice thanks to the dedicated function
    int min_idx = minnode(node);
    //and we store the move that allows to take that best decision in the path : thus building the final path
    push(path, node->sons[min_idx]->move);

    /*
    display_level(node);
    for (int i = 0 ; i < node->nbSons ; i++) {
        printf("%s  | ", getMoveAsString(node->sons[i]->move));
    }
    printf("\n");
    */

    // and finally we return the cost of the actual node, added to the cost of all the other chosen directions
    return node->sons[min_idx]->value +  min_path(node->sons[min_idx], path);

    // this line is also the recursion of the function :
    //we apply the recursion over the chosen min node, so that we 'move' to the next position and thus chose the next
    // best path.
    // this way the recursion will :
    //chose a best move to use, store it in the path, then moves to the possibilities left after moving, etc.
}


//creation of a function to find the node that contains the minimum cost, in order to know the best path on this level
int minnode(p_node parent)
{
    // we affect the minimum value to the min to make sure the minimum value is a value from the nodes
    int min = parent->sons[0]->value;
    int min_idx = 0 ;
    // we iterate through all the nodes up to the nbSons th to consider all of them
    for (int i = 1 ; i < parent->nbSons ; i++){
        //condition to avoid segmentation faults
        if(parent->sons[i] == NULL){
            continue ;
        }
        //here if a value lower than the actual minimum is found, we stock the new minimum value to be able to compare
        // it, and the index of it for the final return
        if(parent->sons[i]->value < min){
            min = parent->sons[i]->value ;
            min_idx = i ;
        }
    }
    //Finally we return the index of the minimum value. This allows to easily access both the value and the node easily
    // afterwards.
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