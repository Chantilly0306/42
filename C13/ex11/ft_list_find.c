#include "ft_list.h"
#include <stdio.h>

t_list  *ft_list_find(t_list *begin_list, void *data_ref,
        int (*cmp)(void *, void *))
{
    if (!cmp)
        return (NULL);
    while (begin_list)
    {
        if (cmp(begin_list->data, data_ref) == 0)
            return (begin_list);
        begin_list = begin_list->next;
    }
    return (NULL);
}

/*int cmp(void *data1, void *data2)
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
    char    *strs[] = {"abc", "abcde", "abcdef"};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (i < 3)
    {
        new_list = ft_create_elem(strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    new_list = ft_list_find(new_list, "abcde", cmp);
    printf("%p\n", new_list);
    printf("%s\n", (char *)(new_list->data));
}*/