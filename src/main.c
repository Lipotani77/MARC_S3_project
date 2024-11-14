#include <stdio.h>
#include "../include/map.h"
#include "../include/node.h"


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

    /* let's now find the base station position */
    printf("Base station position : x = %d and y = %d\n", findBaseCoordinate(map).x, findBaseCoordinate(map).y);
    return 0;
}
