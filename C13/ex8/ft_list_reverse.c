#include "ft_list.h"

void    ft_list_reverse(t_list **begin_list)
{
    t_list  *current = begin_list;
    t_list  *prev = NULL;
    t_list  *next;

    if (!begin_list || !*begin_list)
        return ;
    current = *begin_list;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin_list = prev;
}