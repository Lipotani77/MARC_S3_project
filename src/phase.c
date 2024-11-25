
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/phase.h"

#include "../include/complexity.h"

t_localisation phase(t_localisation init_pos_marc, t_map map, int nb_cards, int nb_moves, int *total_cost)
{
    int initial_cost = retrieve_cost(init_pos_marc, map); // retrieve the cost of the initial position of Marc
    //create the initial node that will be our root
    p_node root = create_node(init_pos_marc,initial_cost,0,9);

    //Display the map with the initial position of Marc
    displayColoredMapWithMarc(map,init_pos_marc.pos);
    displayLegend();

    //init all the part for the complexity computation
    struct timeval start_tree, end_tree;
    struct timeval start_minnode, end_minnode;
    struct timeval start_path, end_path;

    //draw the hand of possible choices for Marc during the phase
    t_stack hand = draw_hand(nb_cards);
    printf("Marc has the following possibility :\n| ");
    for(int i = 0; i < hand.nbElts; i++){
        printf("%s | ", getMoveAsString(hand.values[i]));
    }
    printf("\n");

    //Start computation of execution time to create the tree
    mingw_gettimeofday(&start_tree, NULL);
    // Launch of the recursion to create the tree
    tree_recursive(root, &hand, map, nb_moves);
    mingw_gettimeofday(&end_tree, NULL);
    double total_tree = exec_time(start_tree, end_tree);


    //Start of computation for execution time to find the minimal value among all the leaves in the tree
    mingw_gettimeofday(&start_minnode, NULL);
    //Computation of the minimal value among all the leaves in the tree
    minnode(root);
    mingw_gettimeofday(&end_minnode, NULL);
    double total_minnode = exec_time(start_minnode, end_minnode);



    //Creation of the stack that will contain the path from the root to the min leaf
    t_stack path = createStack(nb_moves);


    //Start of the computation for the execution time to compute the path from the root to the min leaf;
    mingw_gettimeofday(&start_path, NULL);
    //Computation of the path from the root to the min leaf
    *total_cost = *total_cost + min_path(root, &path);
    mingw_gettimeofday(&end_path, NULL);
    double total_path = exec_time(start_path, end_path);;




    // Display of all the execution times and of MARC's taken path
    printf("Execution time to make the tree : %lf\n",total_tree);
    printf("Execution time to find the minimal value : %lf\n",total_minnode);
    printf("Execution time to compute the path from the root to the min leaf : %lf\nThe taken path is the following : ",total_path);
    displayStack(path);


    // Display of the array containing the moves that will be executed by MARC
    t_move move[nb_moves];
    for (int i = 0 ; i < nb_moves ; i++)
        {
        move[i] = pop(&path);
    }

    t_localisation new_loc_marc = loc_init(init_pos_marc.pos.x, init_pos_marc.pos.y, init_pos_marc.ori);


    return new_loc_marc;
}

void launch_phase(t_localisation init_pos_marc, t_map map, int nb_cards, int nb_moves, int* total_cost)
{
    t_position base_pos = findBaseCoordinate(map);
    int continue_phase = 1;
    while (continue_phase == 1)
    {
        if (is_at_base_station(base_pos, init_pos_marc.pos))
        {
            printf("Let's go ! Marc have been saved ! He is not alone anymore !\n");
            printf("The total cost used by Marc to arrive at the base is %d\n", *total_cost);
            continue_phase = 0;
        }
        else if (!isValidLocalisation(init_pos_marc.pos, map.x_max, map.y_max))
        {
            printf("Marc is out of the map ! He is lost !\n");
            printf("The total cost used by Marc before we lost contact with him is %d\n", *total_cost);

            continue_phase = 0;
        }
        else if (on_crevasse(map, init_pos_marc.pos))
        {
            printf("Marc fell into a crevasse ! He is lost !\n");
            continue_phase = 0;
        }
        else
        {
            if (map.soils[init_pos_marc.pos.y][init_pos_marc.pos.x] == REG){
                init_pos_marc = phase(init_pos_marc, map, nb_cards, nb_moves-1, total_cost);
            }
            else {
                init_pos_marc = phase(init_pos_marc, map, nb_cards, nb_moves, total_cost);
            }
            printf("The total cost used by Marc at the end of this phase is %d\n", *total_cost);
            Sleep(5000);
        }
    }
}