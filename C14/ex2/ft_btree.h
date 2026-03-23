#ifndef FT_BTREE_H
# define FT_BTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct  s_btree
{
    struct s_btree  *left;
    struct s_btree  *right;
    void            *item;
}   t_btree;

t_btree *btree_create_node(void *item)
{
    t_btree *new_node;

    new_node = malloc(sizeof(t_btree));
    if (!new_node)
        return (0);
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->item = item;
    return (new_node);
}

#endif