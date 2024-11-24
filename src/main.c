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
    t_map map = createMapFromFile("..\\maps\\example1.map");
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
    displayMap(map);
    printf("Map displayed\n\n");

    t_localisation i_loc = loc_init(5,5,NORTH);
    p_node root = create_node(i_loc,1,0,9);


    t_stack hand = draw_hand();
    printf("Marc have the following possibility : ");
    for(int i = 0; i < hand.nbElts; i++){
        printf("%s | ", getMoveAsString(hand.values[i]));
    }
    printf("\n");

    t_stack copy_hand = fill_moves_node(&hand,root,map);
    display_level(root);
    printf("The number of sons of the first sons of the root is : %d\n",root->sons[0]->nbSons);
    displaytable(map);

    printf("\n dimension of x : %d", map.x_max);
    printf("\n dimension of y : %d", map.y_max);

    return 0;
}
