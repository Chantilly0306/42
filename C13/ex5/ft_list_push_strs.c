#include "ft_list.h"

t_list  *ft_list_push_strs(int size, char **strs)
{
    int     i;
    t_list  *list;
    t_list  *new_node;

    list = NULL;
    i = 0;
    while (i < size)
    {
        new_node = ft_create_elem(strs[i]);
        if (new_node)
        {
            new_node->next = list;
            list = new_node;
        }
        i++;
    }
    return (list);
}