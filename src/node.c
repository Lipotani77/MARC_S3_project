#include "../include/node.h"

t_node *create_node(t_localisation loc, int value, int depth, int nb_sons)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    new_node->loc = loc;
    new_node->value = value;
    new_node->depth = depth;
    new_node->nb_sons = nb_sons;

    if (nb_sons > 0)
    {
        new_node->sons = (t_node **) malloc(nb_sons * sizeof(t_node *));

        for (int i = 0; i != nb_sons; i++) {
            new_node->sons[i] = NULL;
        }
    }
    else
    {
        new_node->sons = NULL;
    }

    return new_node;
}
