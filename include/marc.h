#ifndef  MARC_H
#define MARC_H


#include "loc.h"
#include "moves.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "loc.h"
#include "moves.h"



/**
* @brief Enum for the possible soils of the map

*/
void displayColoredMapWithMarc(t_map, t_position);

/**
* @brief Function to simulate the movements of MARC
*/
int simulateMarcMovements(t_map map, t_localisation * marc_pos, t_move moves[], int move_count);

#endif //MARC_H