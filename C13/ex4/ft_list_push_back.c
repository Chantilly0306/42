#include "ft_list.h"

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list  *tail;
    t_list  *current;

    tail = ft_create_elem(data);
    if (!tail || !begin_list)
        return ;
    if (*begin_list == NULL)
    {
        *begin_list = tail;
        return ;
    }
    current = *begin_list;
    while (current->next)
        current = current->next;
    current->next = tail;
}