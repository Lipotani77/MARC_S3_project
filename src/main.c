#include <stdio.h>
#include "../include/map.h"
#include "../include/node.h"
#include "../include/complexity.h"
#include "../include/moves.h"
#include "../include/loc.h"
#include "../include/node.h"
#include "../include/tree.h"

int main() {
    t_map map = createMapFromFile("..\\maps\\example4.map");
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

    t_localisation loc;
    loc.pos.x = 3;
    loc.pos.y = 6;
    loc.ori = NORTH;

    move_in_soil(&loc, map, F_20);
    printf("\n New position = %d %d", loc.pos.x, loc.pos.y);



    //p_node new_node = create_node(i_loc,1,0,9);
    //printf("The cost of the initial node is : %d\n",new_node->value);


    //t_stack hand = draw_hand();
    //t_tree tree_of_possibility = recursive_tree_creation(map, i_loc, hand);
   // printf("The value of the root is %d\n",tree_of_possibility.root->value);

    //display_tree(tree_of_possibility.root, 0);

    // test of min path
   // t_stack  stack_test;
    //new_node

    //stack_test = createStack(10);
    int min;


    /* let's now find the base station position */
   /* printf("Base station position : x = %d and y = %d\n", findBaseCoordinate(map).x, findBaseCoordinate(map).y);
    int cost;
    cost = cost_node(findBaseCoordinate(map).x, findBaseCoordinate(map).y, map);
    printf("The cost is %d \n", cost);
    double test_exec_t;
    test_exec_t = exec_time(2.71828,3.14159); // I choose somme random values
    printf("It took %lf sec to run", test_exec_t);
    return 0;
    */
}
