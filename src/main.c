#include <stdio.h>
#include "../include/map.h"
#include "../include/node.h"
#include "../include/draw.h"
#include "../include/moves.h"
#include "../include/loc.h"
#include "../include/node.h"
#include "../include/tree.h"

void displaytable(t_map map){
    for (int i = 0 ; i < map.y_max ; i++){
        for (int j = 0 ; j < map.x_max ; j++){
            printf(" %d ", map.soils[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned)time(NULL));
    t_map map = createMapFromFile("..\\maps\\example2.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayColoredMap(map);
    printf("\n\n\ndimension of x : %d", map.x_max);
    printf("\ndimension of y : %d", map.y_max);
    displayLegend();



    //draw the hand of possible choices for Marc for the first phase
    t_stack hand = draw_hand();
    printf("Marc have the following possibility :\n| ");
    for(int i = 0; i < hand.nbElts; i++){
        printf("%s | ", getMoveAsString(hand.values[i]));
    }
    printf("\n");


    //create the initial node that will be our root
    t_localisation i_loc = loc_init(5,5,NORTH);
    p_node root = create_node(i_loc,1,0,9);


    //fill the tree with the possible moves
    //fill_moves_node(&hand,root,map);
    //display_level(root);

    /*
    t_stack copy_hand = fill_moves_node(&hand,root,map);
    display_level(root);
    printf("The number of sons of the first sons of the root is : %d\n",root->sons[0]->nbSons);*/

    //displaytable(map);




    tree_recursive(root, &hand, map, 2);
    //display the second son of the root
    display_level(root->sons[0]);


    return 0;
}
