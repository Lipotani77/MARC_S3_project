#include "../include/tree.h"
#include <stdlib.h>
#include <stdio.h>

t_tree create_tree(t_node *node)
{
    t_tree tree;
    tree.root = node;

    return tree;
}