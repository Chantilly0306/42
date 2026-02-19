#include "ft_list.h"

t_list  *ft_create_elem(void *data)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (0);
    node->next = NULL;
    node->data = data;
    return (node);
}