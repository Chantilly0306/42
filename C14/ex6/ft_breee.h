#ifndef FT_BREEE_H
# define FT_BREEE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct  s_btree
{
    struct s_btree  *left;
    struct s_btree  *right;
    void            *item;
}   t_btree;

#endif