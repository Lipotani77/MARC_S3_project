#include <stdio.h>

#include "../include/complexity.h"
#include "../include/draw.h"
#include "../include/loc.h"
#include "../include/map.h"
#include "../include/menu.h"
#include "../include/moves.h"
#include "../include/node.h"
#include "../include/queue.h"
#include "../include/stack.h"
#include "../include/tree.h"




int main() {
    int choice;
    t_map map;

    while (1)
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2)
        {
            printf("Exiting program. MARC will stay stuck, left on his own TT\n");
            return 0;
        }
        else if (choice == 1)
        {
            displayIntroduction();
            char *fileMap = chooseMap();
            printf("Loading map: %s\n", fileMap);
            map = createMapFromFile(fileMap);
            break;
        }
        else
        {
            printf("Invalid choice. Going to Map 1 by default.\n");
        }
    }

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);

    // Print the terrain of the map
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // Print the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }

    t_localisation i_loc = loc_init(5, 5, NORTH);  // Starting position of MARC
    displayColoredMapWithMarc(map,i_loc.pos);
    displayLegend();



    //draw the hand of possible choices for Marc for the first phase
    t_stack hand = draw_hand();
    printf("Marc has the following possibility :\n| ");
    for(int i = 0; i < hand.nbElts; i++){
        printf("%s | ", getMoveAsString(hand.values[i]));
    }
    printf("\n");


    //create the initial node that will be our root
    p_node root = create_node(i_loc,1,0,9);


    //fill the tree with the possible moves
    //fill_moves_node(&hand,root,map);
    //display_level(root);

    //*/
    //t_stack copy_hand = fill_moves_node(&hand,root,map);

    //printf("The number of sons of the first sons of the root is : %d\n",root->sons[0]->nbSons);
    //
    //displaytable(map);



    clock_t start_tree = clock();

    tree_recursive(root, &hand, map, 3);
    //display the second son of the root
    //display_tree(root, 0);
    //display_level(root);
    //display_level(root->sons[0]);
    //display_level(root->sons[0]->sons[0]);

    //Computation of execution time to find the minimal value among all the leaves in the tree
    clock_t start_minnode = clock();

    minnode(root);

    clock_t end_minnode = clock();
    double total_minnode = end_minnode - start_minnode;

    t_stack path = createStack(9);
    //Computation of execution time to compute the path from the root to the min leaf;
    clock_t start_path = clock();

    min_path(root, &path);

    clock_t end_path = clock();
    double total_path = end_path - start_path;

    clock_t end_tree = clock();
    double total_tree = end_tree - start_tree;

    // Display of execution times and of MARC's taken path

    printf("\nExecution time to find the minimal value : %lf\n",total_minnode);
    printf("Execution time to compute the path from the root to the min leaf : %lf\nThe taken path is the following : ",total_path);
    displayStack(path);
    printf("Execution time to make the tree : %lf\n",total_tree);

    return 0;
}
