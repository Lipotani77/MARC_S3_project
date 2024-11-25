#ifndef  PHASE_H
#define PHASE_H

#include <time.h>
#include <windows.h>


#include "draw.h"
#include "node.h"
#include "tree.h"
#include "marc.h"
#include "map.h"
#include "loc.h"

/*
 @brief :  function to launch a phase
 @param : none
 @param :
 */

t_localisation phase(t_localisation init_pos_marc, t_map map, int nb_cards, int nb_moves, int *total_cost);

void launch_phase(t_localisation, t_map, int, int, int*);



#endif //PHASE_H