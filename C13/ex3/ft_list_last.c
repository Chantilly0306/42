#include "ft_list.h"
#include <stdio.h>

t_list  *ft_list_last(t_list *begin_list)
{
    if (!begin_list)
        return (NULL);
    while (begin_list->next)
        begin_list = begin_list->next;
    return (begin_list);
}

/*int main(void)
{
    int     i = 0;
    char    *strs[] = {"Apple", "Banana", "Candy", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;
    t_list  *tail;

    while (strs[i])
    {
        new_list = ft_create_elem(strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    tail = ft_list_last(new_list);
    printf("%s\n", (char *)(tail->data));
    free(new_list);
    free(tail);
}*/