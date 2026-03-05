#include "ft_list.h"
#include <stdio.h>

void    ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
        void *data_ref, int (*cmp)(void *, void *))
{
    if (!f || !cmp)
        return ;
    while (begin_list)
    {
        if (cmp(begin_list->data, data_ref) == 0)
            f(begin_list->data);
        begin_list = begin_list->next;
    }
}

/*void    multiply_two(void *nb)
{
    *(int *)(nb) *= 2;
}

int cmp(void *data1, void *data2)
{
    return (*(int *)data1 - *(int *)data2);
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
    ft_list_foreach_if(new_list, multiply_two, &strs[1], cmp);
    printf("%d\n", *(int *)(new_list->data));
    printf("%d\n", *(int *)(new_list->next->data));
    printf("%d\n", *(int *)(new_list->next->next->data));
}*/