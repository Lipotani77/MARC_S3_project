//
// Created by lelia on 24/11/2024.
//

#ifndef UNTITLED1_MENU_H
#define UNTITLED1_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For interactions with keys by user
#include "map.h"

/**
 * @brief Function to display the table of the map
 * @param map : the map to display
 */
void displaytable(t_map);

/**
 * @brief Function to display the legend of the map
 */
void displayMenu();

/**
 * @brief Function to display the introduction of the game
 */
void displayIntroduction();

/**
 * @brief Function to choose the map
 * @return the name of the map
 */
char* chooseMap();









#endif //UNTITLED1_MENU_H
