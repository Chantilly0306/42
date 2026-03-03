#include "ft_list.h"
#include <stdio.h>

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

/*int main(void)
{
    char    *strs[] = {"Apple", "Banana", "Candy"};
    t_list  *new_list;

    new_list = ft_list_push_strs(3, strs);
    printf("%s\n", (char *)(new_list->data));
}*/