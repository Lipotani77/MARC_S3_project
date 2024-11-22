#include <stdio.h>
#include "../include/map.h"
#include "../include/node.h"
#include "../include/draw.h"
#include "../include/moves.h"
#include "../include/loc.h"
#include "../include/node.h"
#include "../include/tree.h"


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
    printf("Map displayed\n");

    t_localisation i_loc = loc_init(1,1,NORTH);
    p_node new_node = create_node(i_loc,1,0,9);
    printf("The cost of the initial node is : %d",new_node->value);

    /*
    printf("\n\n");
    t_stack hand ;
    hand = draw_hand();
    t_move temp ;
    for (int i = 0 ; i < 9 ; i++){
        temp = pop(&hand);
        printf("%s / ", getMoveAsString(temp));
    }
*/
    t_stack hand ;
    hand = draw_hand();
    t_tree recursive_tree ;
    recursive_tree = recursive_tree_creation(map, i_loc, hand);


    return 0;
}
