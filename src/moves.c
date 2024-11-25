//
// Created by flasque on 19/10/2024.
//

#include "../include/moves.h"
#include <stdlib.h>


/* prototypes of local functions */
/* local functions are used only in this file, as helper functions */

/**
 * @brief Function to rotate the robot according to a move and its actual orientation
 * @param ori : the actual orientation of the robot
 * @param move : the move to do
 * @return the new orientation of the robot
 */
t_orientation rotate(t_orientation, t_move );

/**
 * @brief function to translate the robot according to a move and its actual position
 * @param loc : the actual localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation translate(t_localisation , t_move);

/* definition of local functions */

t_orientation rotate(t_orientation ori, t_move move)
{
    int rst;
    switch (move)
    {
        case T_LEFT:
            rst=3;
            break;
        case T_RIGHT:
            rst=1;
            break;
        case U_TURN:
            rst=2;
            break;
        default:
            break;
    }
    return (ori+rst)%4;
}

t_localisation translate(t_localisation loc, t_move move)
{
    /** rules for coordinates:
     *  - x grows to the right with step of +1
     *  - y grows to the bottom with step of +1
     *  - the origin (x=0, y=0) is at the top left corner
     */
    t_position res = loc.pos;
    switch (move) {
        case F_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 1;
                    break;
                case EAST:
                    res.x = loc.pos.x + 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 1;
                    break;
                case WEST:
                    res.x = loc.pos.x - 1;
                    break;
                default:
                    break;
            }
            break;
        case F_20:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 2;
                    break;
                case EAST:
                    res.x = loc.pos.x + 2;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 2;
                    break;
                case WEST:
                    res.x = loc.pos.x - 2;
                    break;
                default:
                    break;
            }
            break;
        case F_30:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 3;
                    break;
                case EAST:
                    res.x = loc.pos.x + 3;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 3;
                    break;
                case WEST:
                    res.x = loc.pos.x - 3;
                    break;
                default:
                    break;
            }
            break;
        case B_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y + 1;
                    break;
                case EAST:
                    res.x = loc.pos.x - 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y - 1;
                    break;
                case WEST:
                    res.x = loc.pos.x + 1;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    return loc_init(res.x, res.y, loc.ori);

}

/* definitions of exported functions */

char *getMoveAsString(t_move move)
{
    return _moves[move];
}

t_localisation move(t_localisation loc, t_move move)
{
    t_localisation new_loc;
    new_loc.ori = rotate(loc.ori, move);
    new_loc = translate(loc, move);
    return new_loc;
}

void updateLocalisation(t_localisation *p_loc, t_move m)
{
    *p_loc = move(*p_loc, m);
    return;
}

void update_loc_soil(t_localisation *p_loc, t_map map, t_move m){

    return;
}



void move_in_soil(t_localisation* p_loc, t_map map, t_move move_to){
    if(isValidLocalisation(p_loc->pos,map.x_max, map.y_max) == 0){
        printf("The robot is not in a valid localisation.");
        return;
    }


    int loc_x, loc_y;
    t_localisation *new_loc;
    loc_x = p_loc->pos.x;
    loc_y = p_loc->pos.y;

    t_soil current_soil;
    current_soil = map.soils[loc_y][loc_x];

    switch(current_soil){
        case REG :
            switch (move_to) {
                case F_20:
                    move_to = F_10;
                    break;
                case F_30:
                    move_to = F_20;
                    break;
                case U_TURN:
                    move_to = T_RIGHT;
                    p_loc->ori = rotate(p_loc->ori, move_to);
                    break;
                default:
                    move_to = REST;
                    break;
            }
            break;
        case MUD:
            if((move_to == U_TURN) || (move_to == T_LEFT) || (move_to == T_RIGHT)){
                move_to = REST;

            }
            break;
        case ICE:
            switch (move_to) {
                case F_10:
                    move_to = F_20;
                    break;
                case F_20:
                    move_to = F_30;
                    break;
                case F_30:
                    updateLocalisation(p_loc, move_to);
                    move_to = F_10;
                    break;
                case T_LEFT:
                    move_to = U_TURN;
                    p_loc->ori = rotate(p_loc->ori, move_to);
                    break;
                case T_RIGHT:
                    move_to=U_TURN;
                    p_loc->ori = rotate(p_loc->ori, move_to);
                default:
                    move_to = REST;
                    break;
            }
            break;
        case CREVASSE:
            printf("MARC is dead. Mission failed.");

            break;


        default:

            break;
    }
    if(move_to != REST){
        updateLocalisation(p_loc, move_to);
    }



}
