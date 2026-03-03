#include "ft_list.h"
#include <stdio.h>

void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *node;

    node = ft_create_elem(data);
    if (node)
    {
        node->next = *begin_list;
        *begin_list = node;
    }
}

/*int main(void)
{
    int     i = 0;
    int     val = 123;
    char    *strs[] = {"Apple", "Banana", "Candy"};
    t_list  *new_list;

    while (i < 3)
        ft_list_push_front(&new_list, strs[i++]);
    ft_list_push_front(&new_list, &val);
    if (new_list && new_list->data)
        printf("First element: %d\n", *(int *)(new_list->data));
    if (new_list->next)
        printf("Second element: %s\n", (char *)(new_list->next->data));
    if (new_list->next->next)
        printf("Third element: %s\n", (char *)(new_list->next->next->data));
    if (new_list->next->next->next)
        printf("Fourth element: %s\n", (char *)(new_list->next->next->next->data));
    if (new_list->next->next->next->next)
        printf("Fifth element: %s\n", (char *)(new_list->next->next->next->next->data));
}*/