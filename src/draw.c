//
// Created by noahj on 14/11/2024.
//
#include "../include/draw.h"
#include <stdlib.h>
#define SIZE_OF_HAND 7

t_stack draw_hand(){

    //creation of the deck. __
    t_move deck[100] ;
    // we iterate to add the corresponding cards in the right amounts inside the deck

    for (int i =0 ; i< 22 ; i++){
        deck[i] = F_10 ;
    }

    for (int i =22 ; i< 37 ; i++){
        deck[i] = F_20 ;
    }

    for (int i =37 ; i< 44 ; i++){
        deck[i] = F_30 ;
    }

    for (int i =44 ; i< 51 ; i++){
        deck[i] = B_10 ;
    }

    for (int i =51 ; i< 72 ; i++){
        deck[i] = T_LEFT ;
    }

    for (int i =72 ; i< 93 ; i++){
        deck[i] = T_RIGHT ;
    }

    for (int i =93 ; i< 100 ; i++){
        deck[i] = U_TURN ;
    }
    //__
    //we now need to draw 9 random cards.

    t_stack hand ;
    hand = createStack(SIZE_OF_HAND);
    int number ;
    number = rand() %100 ;
// we iterate 9 times, to draw the 9 cards from the deck
    for (int j = 0 ; j < SIZE_OF_HAND ; j++){

//as long as we find an empty slot of card (card that has been taken), we keep drawing
        while (deck[number] == NONE){
            number = rand() %100 ;
        }
//once found, we add the drawn card to the hand
        push(&hand, deck[number]);
//to be sure not to draw the same card again, we set this move to NONE : this way we can detect it is an empty slot
        deck[number] = NONE ;

    }
    hand.nbElts = SIZE_OF_HAND ;
    return hand ;
}