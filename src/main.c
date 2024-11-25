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
#include "../include/marc.h"

//    t_localisation i_loc = loc_init(5, 5, NORTH);  // Starting position of MARC



int main()
{
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


    return 0;
}
