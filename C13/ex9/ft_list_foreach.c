#include "ft_list.h"
#include <stdio.h>

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    if (!f)
        return ;
    while (begin_list)
    {
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}

/*void    multiply_two(void *nb)
{
    *(int *)(nb) *= 2;
}

int main(void)
{
    int     i = 0;
    int     strs[] = {10, 12, 21};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (i < 3)
    {
        new_list = ft_create_elem(&strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    ft_list_foreach(new_list, multiply_two);
    printf("%d\n", *(int *)(new_list->data));
    printf("%d\n", *(int *)(new_list->next->data));
    printf("%d\n", *(int *)(new_list->next->next->data));
}*/