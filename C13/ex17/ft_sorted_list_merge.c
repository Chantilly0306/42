#include "ft_list.h"
#include <stdio.h>

void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
        int (*cmp)(void *, void *))
{

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
    char    *strs1[] = {"tuv", "abcde", "qrs", "ghi", "jk", NULL};
    char    *strs2[] = {"z", "efg", "abc", "cd", "xy", NULL};
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