#include "ft_list.h"

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list  *tmp;

    if (!begin_list || !free_fct)
        return ;
    while (begin_list)
    {
        tmp = begin_list->next;
        free_fct(begin_list->data);
        free(begin_list);
        begin_list = tmp;
    }
}