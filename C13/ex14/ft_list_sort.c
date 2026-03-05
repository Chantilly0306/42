#include "ft_list.h"
#include <stdio.h>

void    ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
    t_list  *current;
    t_list  *search;
    void    *tmp;

    if (!begin_list || !*begin_list || !cmp)
        return ;
    current = *begin_list;
    while (current && current->next)
    {
        search = current->next;
        while (search)
        {
            if (cmp(current->data, search->data) > 0)
            {
                tmp = search->data;
                search->data = current->data;
                current->data = tmp;
            }
            search = search->next;
        }
        current = current->next;
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
    char    *strs[] = {"abc", "abcde", "abc", "ghi", "ghi", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (strs[i])
    {
        new_list = ft_create_elem(strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    ft_list_sort(&new_list, cmp);
    printf("%s\n", (char *)(new_list->data));
    printf("%s\n", (char *)(new_list->next->data));
    printf("%s\n", (char *)(new_list->next->next->data));
    printf("%s\n", (char *)(new_list->next->next->next->data));
    printf("%s\n", (char *)(new_list->next->next->next->next->data));
}