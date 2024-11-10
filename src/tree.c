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

/* De ce que j'ai compris, les nodes du tree ont comme valeur les cases par lesquelles nous sommes passés. Donc dans notre cas, le tree aura qu'un seul son à chaque fois.
 * Je me suis donc dit qu'il fallait faire une fonction qui en fonction des mouvements disponibles, nous donne la case avec le minimum cost possible et cela nous donnerais également
 * les coordonnées de cette case. Ainsi, quand on arrive au dernier mouvement, on aura la nouvelle position de MARC.
 * Mais dans cette fonction, faut prendre en compte quand MARC arrive à la fin de la map, s'il est arrivé à la base ou s'il meurt.*/

