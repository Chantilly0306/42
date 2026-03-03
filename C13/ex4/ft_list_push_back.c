#include "ft_list.h"
#include <stdio.h>

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

/*int main(void)
{
    int     i = 0;
    int     val = 123;
    char    *strs[] = {"Apple", "Banana", "Candy"};
    t_list  *new_list = NULL;

    while (i < 3)
        ft_list_push_back(&new_list, strs[i++]);
    ft_list_push_back(&new_list, &val);
    if (new_list && new_list->data)
        printf("First element: %s\n", (char *)(new_list->data));
    if (new_list->next)
        printf("Second element: %s\n", (char *)(new_list->next->data));
    if (new_list->next->next)
        printf("Third element: %s\n", (char *)(new_list->next->next->data));
    if (new_list->next->next->next)
        printf("Fourth element: %d\n", *(int *)(new_list->next->next->next->data));
    if (new_list->next->next->next->next)
        printf("Fifth element: %s\n", (char *)(new_list->next->next->next->next->data));
}*/