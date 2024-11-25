
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/phase.h"

t_localisation phase(t_localisation init_pos_marc, t_map map, int nb_cards, int nb_moves, int *total_cost)
{
    //create the initial node that will be our root
    p_node root = create_node(init_pos_marc,1,0,9);

    //Display the map with the initial position of Marc
    displayColoredMapWithMarc(map,init_pos_marc.pos);
    displayLegend();

    //draw the hand of possible choices for Marc during the phase
    t_stack hand = draw_hand(nb_cards);
    printf("Marc has the following possibility :\n| ");
    for(int i = 0; i < hand.nbElts; i++){
        printf("%s | ", getMoveAsString(hand.values[i]));
    }
    printf("\n");

    //Start computation of execution time to create the tree
    clock_t start_tree = clock(); // to put before we launch the tree creation (the recursion)

    // Launch of the recursion to create the tree
    tree_recursive(root, &hand, map, nb_moves);

    //Start of computation for execution time to find the minimal value among all the leaves in the tree
    clock_t start_minnode = clock();

    //Computation of the minimal value among all the leaves in the tree
    minnode(root);

    clock_t end_minnode = clock();
    double total_minnode = end_minnode - start_minnode;



    //Creation of the stack that will contain the path from the root to the min leaf
    t_stack path = createStack(nb_moves);

    //Start of the computation for the execution time to compute the path from the root to the min leaf;
    clock_t start_path = clock();

    //Computation of the path from the root to the min leaf
    *total_cost = *total_cost + min_path(root, &path);

    clock_t end_path = clock();
    double total_path = end_path - start_path;

    clock_t end_tree = clock();
    double total_tree = end_tree - start_tree;

    // Display of all the execution times and of MARC's taken path
    printf("\nExecution time to find the minimal value : %lf\n",total_minnode);
    printf("Execution time to compute the path from the root to the min leaf : %lf\nThe taken path is the following : ",total_path);
    displayStack(path);
    printf("Execution time to make the tree : %lf\n",total_tree);

    // Display of the array containing the moves that will be executed by MARC
    t_move move[nb_moves];
    for (int i = 0 ; i < nb_moves ; i++)
        {
        move[i] = pop(&path);
    }

    t_localisation new_loc_marc = loc_init(init_pos_marc.pos.x, init_pos_marc.pos.y, init_pos_marc.ori);


    // Display of the price of the path and of the coordinates of MARC
    printf("\nprice of the path : %d \n", simulateMarcMovements(map, &init_pos_marc, move, 3));
    printf("coordinates : \n x: %d  y: %d  \norientation : %d", new_loc_marc.pos.x, new_loc_marc.pos.y, new_loc_marc.ori);

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
        else if (!on_crevasse(map, init_pos_marc.pos))
        {
            printf("Marc fell into a crevasse ! He is lost !\n");
            continue_phase = 0;
        }
        else
        {
            init_pos_marc = phase(init_pos_marc, map, nb_cards, nb_moves, total_cost);
            printf("The total cost used by Marc at the end of this phase is %d\n", *total_cost);

        }
    }
}