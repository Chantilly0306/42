#include "ft_list.h"
#include <stdio.h>

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int    i;

    i = 0;
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

/*int main(void)
{
    int     i = 0;
    char    *strs[] = {"Apple", "Banana", "Candy", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (strs[i])
    {
        new_list = ft_create_elem(strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    new_list = ft_list_at(new_list, 0);
    printf("%p\n", new_list);
    printf("%p\n", new_list->next);
    printf("%p\n", new_list->data);
    printf("%s\n\n", (char *)(new_list->data));
    new_list = ft_list_at(new_list, 1);
    printf("%p\n", new_list);
    printf("%p\n", new_list->next);
    printf("%p\n", new_list->data);
    printf("%s\n\n", (char *)(new_list->data));
    new_list = ft_list_at(new_list, 2);
    printf("%p\n", new_list);
    printf("%p\n", new_list->next);
    printf("%p\n", new_list->data);
    printf("%s\n\n", (char *)(new_list->data));
}*/