#include "../include/tree.h"
#include <stdlib.h>
#include <stdio.h>

tree create_tree()
/* Create an empty tree */
{
    tree new_tree;
    new_tree.root = NULL;
    return new_tree;
}