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
void simulateMarcMovements(t_map, t_localisation, t_move*, int);

#endif //MARC_H