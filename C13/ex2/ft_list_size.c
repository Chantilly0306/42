#include "ft_list.h"
#include <stdio.h>

int ft_list_size(t_list *begin_list)
{
    int count;

    count = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        count++;
    }
    return (count);
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
    printf("%d\n", ft_list_size(new_list));
}*/