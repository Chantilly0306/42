#include "ft_list.h"
#include <stdio.h>

void    ft_sorted_list_insert(t_list **begin_list, void *data,
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
    char    *strs[] = {"tuv", "abcde", "qrs", "ghi", "jk", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (strs[i])
    {
        new_list = ft_create_elem(strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    ft_sorted_list_insert(&new_list, "efg", cmp);
    while (new_list)
    {
        printf("%s\n", (char *)(new_list->data));
        new_list = new_list->next;
    }
}