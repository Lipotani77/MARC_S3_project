#include <stdio.h>

#include "../include/loc.h"
#include "../include/map.h"
#include "../include/menu.h"

#include "../include/phase.h"





int main()
{
    printf("      _________\n");
    printf("     /         \\\n");
    printf("    /  [==O==]  \\\n");
    printf("   |    MARC     |\n");
    printf("   |   _     _   |\n");
    printf("   |  |_|   |_|  |\n");
    printf("   |_____________|\n");
    printf("     /         \\\n");
    printf("  __/___________\\\\__\n");
    printf(" |                   |\n");
    printf(" |   O         O     |\n");
    printf("  \\_________________/\n");

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

    t_localisation init_pos_marc = loc_init(2, 0, SOUTH); // we chose this position for MARC arbitrarily, so that it will always be valid no matter the map

    int nb_cards;
    int nb_moves;
    printf("Enter the number of cards to draw: ");
    scanf("%d", &nb_cards);
    printf("Enter the number of moves to simulate: ");
    scanf("%d", &nb_moves);
    int* total_cost;
    *total_cost = 0;
    launch_phase(init_pos_marc, map, nb_cards, nb_moves, total_cost);
    return 0;
}
