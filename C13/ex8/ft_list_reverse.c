#include "ft_list.h"
#include <stdio.h>

void    ft_list_reverse(t_list **begin_list)
{
    t_list  *current;
    t_list  *next_node;

    if (!begin_list || !*begin_list)
        return ;
    next_node = NULL;
    while (*begin_list)
    {
        current = *begin_list;
        *begin_list = (*begin_list)->next;
        current->next = next_node;
        next_node = current;
    }
    *begin_list = current;
}

/*int main(void)
{
    int     i = 0;
    char    *strs[] = {"Apple", "Banana", "Candy"};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (i < 3)
    {
        new_list = ft_create_elem(strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    printf("%p\n", new_list);
    printf("%p\n", new_list->next);
    printf("%p\n", new_list->next->next);
    printf("%s\n\n", (char *)(new_list->data));
    ft_list_reverse(&new_list);
    printf("%p\n", new_list);
    printf("%p\n", new_list->next);
    printf("%p\n", new_list->next->next);
    printf("%s\n\n", (char *)(new_list->data));
}*/