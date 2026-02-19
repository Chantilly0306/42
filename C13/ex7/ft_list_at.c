#include "ft_list.h"

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int    i = 0;

    if (!begin_list)
        return (NULL);
    while (i < nbr)
    {
        if (begin_list->next == NULL)
            return (NULL);
        begin_list = begin_list->next;
        i++;
    }
    return (begin_list);
}