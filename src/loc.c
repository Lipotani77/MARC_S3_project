//
// Created by flasque on 19/10/2024.
//

#include "../include/loc.h"

t_localisation loc_init(int x, int y, t_orientation ori)
{
    t_localisation loc;
    loc.pos.x = x;
    loc.pos.y = y;
    loc.ori = ori;
    return loc;
}

int isValidLocalisation(t_position loc, int x_max, int y_max)
{
    return (loc.x >= 0 && loc.x < x_max && loc.y >= 0 && loc.y < y_max);
}

t_position LEFT(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x - 1;
    new_pos.y = pos.y;
    return new_pos;
}

t_position RIGHT(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x + 1;
    new_pos.y = pos.y;
    return new_pos;
}

t_position UP(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x;
    new_pos.y = pos.y - 1;
    return new_pos;
}

t_position DOWN(t_position pos)
{
    t_position new_pos;
    new_pos.x = pos.x;
    new_pos.y = pos.y + 1;
    return new_pos;
}

int is_out_of_map(t_position rover_pos, t_map map){
    if(rover_pos.x <0 || rover_pos.x > map.x_max || rover_pos.y < 0 || rover_pos.y > map.y_max){ //the rover is out of the map if its x or y position is less than 0 or greater than the maximum x or y position
        return 1;
    }
    else{
        return 0;
    }
}

t_position findBaseCoordinate(t_map map){
    t_position base_pos;
    base_pos.x = -1;
    base_pos.y = -1;
    for(int i = 0; i < map.y_max; i++){ //loop through the map to find the base station, remember that the map is a 2D array
        for(int j = 0; j < map.x_max; j++){
            if(map.soils[i][j] == BASE_STATION){ //if the soil is a base station, then we found the base station
                base_pos.x = j;
                base_pos.y = i;
                return base_pos;
            }
        }
    }
    if(base_pos.x == -1 && base_pos.y == -1){ // in case that we might not have put the base station in the map or if the base station is not found
        printf("The base is not found in the map\n");
    }
    return base_pos;
}

int is_at_base_station(t_position base_pos, t_position MARC_pos){
    if(base_pos.x == MARC_pos.x && base_pos.y == MARC_pos.y){ //if the x and y position of the base station is equal to the x and y position of MARC, then MARC is at the base station
        return 1;
    }
    else{
        return 0;
    }
}