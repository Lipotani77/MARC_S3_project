//
// Created by lelia on 24/11/2024.
//

#include "../include/menu.h"


void displaytable(t_map map)
{
    for (int i = 0; i < map.y_max; i++) {
        for (int j = 0; j < map.x_max; j++) {
            printf(" %d ", map.soils[i][j]);
        }
        printf("\n");
    }
}

void displayMenu()
{
    printf("\n---- MARC Rescue Mission ----\n");
    printf("         1. Start\n");
    printf("         2. Exit\n");
    printf("-----------------------------\n");
}

void displayIntroduction()
{
    printf("\nWARNING: A very intense solar storm has just hit...\n");
    printf("MARC, which was carrying out its mission very well, has suffered a malfunction.\n");
    printf("Its programming, guidance, and movement systems have been seriously affected...\n");
    printf("You have to help him!\n");
    printf("\nPress Enter to continue...\n");
    getch(); // User input
}

char* chooseMap()
{
    int mapChoice;
    printf("\nChoose a map:\n");
    printf("1. Map 1 (example1.map)\n");
    printf("2. Map 2 (example2.map)\n");
    printf("3. Map 3 (example3.map)\n");
    printf("4. Map 4 (example4.map)\n");
    printf("Where is MARC in need of your help ? ");
    scanf("%d", &mapChoice);

    switch (mapChoice)
    {
        case 1:
            return "..\\maps\\example1.map";
        case 2:
            return "..\\maps\\example2.map";
        case 3:
            return "..\\maps\\example3.map";
        case 4:
            return "..\\maps\\example4.map";
        default:
            printf("Invalid choice. Going to Map 1 by default.\n");
            return "..\\maps\\example1.map";
    }
}
