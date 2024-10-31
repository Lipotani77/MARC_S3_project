#ifndef  NODE_H
#define NODE_H
#define ACTION_SIZE 9
#include <time.h>

typedef struct s_node
{
    int value;
    int map_pos[2]; // x, y
    int xn,yn;
    struct s_node *sons[ACTION_SIZE];
    int LS; // 5 - the depth of the node
} t_node, *p_node;



#endif //NODE_H