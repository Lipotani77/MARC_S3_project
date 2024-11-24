#include <stdio.h>
#include <conio.h> // For interactions with keys by user

#include "../include/map.h"
#include "../include/node.h"
#include "../include/draw.h"
#include "../include/moves.h"
#include "../include/loc.h"
#include "../include/node.h"
#include "../include/tree.h"
#include "menu.h"



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

    displayColoredMap(map);
    printf("Map displayed\n\n");
    displayLegend();

    t_localisation i_loc = loc_init(5, 5, NORTH);
    p_node root = create_node(i_loc, 1, 0, 9);

    t_stack hand = draw_hand();
    printf("MARC has the following possibilities:\n |");
    for (int i = 0; i < hand.nbElts; i++) {
        printf("%s | ", getMoveAsString(hand.values[i]));
    }
    printf("\n");

    t_stack copy_hand = fill_moves_node(&hand, root, map);
    display_level(root);
    printf("The number of sons of the first sons of the root is: %d\n", root->sons[0]->nbSons);
    displaytable(map);

    printf("\nDimension of x: %d", map.x_max);
    printf("\nDimension of y: %d", map.y_max);

    tree_recursive(root, &copy_hand, map, 5);
    // Display the second son of the root
    for (int i = 0; i < 3; i++) {
        display_level(root->sons[1]->sons[i]);
    }

    return 0;
}
