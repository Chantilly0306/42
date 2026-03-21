#include "ft_list.h"
#include <stdio.h>

void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
        int (*cmp)(void *, void *))
{
    t_list  **cursor;
    t_list  *tmp;

    if (!begin_list1 || !begin_list2 || !cmp)
        return ;
    cursor = begin_list1;
    while (begin_list2)
    {
        if (!*cursor)
        {
            *cursor = begin_list2;
            break ;
        }
        if (cmp((*cursor)->data, begin_list2->data) > 0)
        {
            tmp = begin_list2->next;
            begin_list2->next = *cursor;
            *cursor = begin_list2;
            begin_list2 = tmp;
        }
        cursor = &((*cursor)->next);
    }
}

int cmp(void *data1, void *data2)
{
    int     i = 0;
    char    *str1;
    char    *str2;

    str1 = (char *)data1;
    str2 = (char *)data2;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (str1[i] - str2[i]);
}

int main(void)
{
    int     i = 0;
    char    *strs1[] = {"f", "e", "c", NULL};
    char    *strs2[] = {"g", "d", "b", "a", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;
    t_list  *add_list;

    while (strs1[i])
    {
        new_list = ft_create_elem(strs1[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    i = 0;
    tmp = NULL;
    while (strs2[i])
    {
        add_list = ft_create_elem(strs2[i]);
        add_list->next = tmp;
        tmp = add_list;
        i++;
    }
    ft_sorted_list_merge(&new_list, add_list, cmp);
    while (new_list)
    {
        printf("%s\n", (char *)(new_list->data));
        new_list = new_list->next;
    }
}