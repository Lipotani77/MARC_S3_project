//
// Created by lelia on 11/11/2024.
//

#ifndef UNTITLED1_PATH_H
#define UNTITLED1_PATH_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "tree.h"

/**
 * @brief structure for the head_tail linked list to save the path taken by MARC in the tree
 * @param head : head of the list with the first node in the tree to be able to display the list once finished
 * @param tail : tail of the list to insert the new nodes taken by MARC on his way
 * @return the path taken by MARC
 */

typedef struct ht_list_path{
    struct t_node *head;
    struct t_node *tail;
}ht_path;

ht_path create_ht_path();

int isEmptyHtPath(ht_path);

void insertTail(ht_path*, t_node*);



#endif //UNTITLED1_PATH_H
