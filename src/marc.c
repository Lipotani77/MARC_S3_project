#include "../include/marc.h"

void displayColoredMapWithMarc(t_map map, t_position marc_position)
{
    char c[4];

    for (int y = 0; y < map.y_max; y++) {
        for (int x = 0; x < map.x_max; x++) {
            if (y == marc_position.y && x == marc_position.x)
            {
                strcpy(c, " M ");
                printf(BLUE "%s" RESET, c); // Highlight MARC's position
            } else {
                switch (map.soils[y][x]) {
                    case BASE_STATION:
                        strcpy(c, " B ");
                        printf(RESET "%s" RESET, c);
                        break;
                    case PLAIN:
                        strcpy(c, "---");
                        printf(GREEN "%s" RESET, c);
                        break;
                    case ERG:
                        strcpy(c, "~~~");
                        printf(YELLOW "%s" RESET, c);
                        break;
                    case REG:
                        strcpy(c, "^^^");
                        printf(CYAN "%s" RESET, c);
                        break;
                    case CREVASSE:
                        sprintf(c, "%c%c%c", 219, 219, 219);
                        printf(RED "%s" RESET, c);
                        break;
                    default:
                        strcpy(c, "???");
                        printf(RESET "%s" RESET, c);
                        break;
                }
            }
        }
        printf("\n");
    }
}

void simulateMarcMovements(t_map map, t_localisation start, t_move moves[], int move_count)
{
    t_localisation marc_loc = start;

    for (int i = 0; i < move_count; i++) {
        // Clear screen for the animation
        system("cls");

        displayColoredMapWithMarc(map, marc_loc.pos);

        // Display of current move
        printf("\nPerforming move %d/%d: %s\n", i + 1, move_count, getMoveAsString(moves[i]));

        // Wait 1s to see the animation
        Sleep(1000);

        updateLocalisation(&marc_loc, moves[i]);

        if (marc_loc.pos.x < 0 || marc_loc.pos.x >= map.x_max ||
            marc_loc.pos.y < 0 || marc_loc.pos.y >= map.y_max) {
            printf("MARC moved out of bounds. Stopping simulation.\n");
            return;
        }
    }

    // Final display after all moves
    system("cls");
    displayColoredMapWithMarc(map, marc_loc.pos);
    printf("Simulation complete. MARC stopped at (%d, %d), facing %d.\n",marc_loc.pos.x, marc_loc.pos.y, marc_loc.ori);
}