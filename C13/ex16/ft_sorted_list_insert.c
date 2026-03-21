#include "ft_list.h"
#include <stdio.h>

void    ft_sorted_list_insert(t_list **begin_list, void *data,
        int (*cmp)(void *, void *))
{
    int     swapped;
    t_list  *dummy;
    t_list  *prev;
    t_list  *curr;
    t_list  *next;

    if (!begin_list || !*begin_list || !cmp)
        return ;
    dummy = ft_create_elem(NULL);
    curr = ft_create_elem(data);
    dummy->next = curr;
    curr->next = *begin_list;
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        prev = dummy;
        curr = prev->next;
        while (curr->next)
        {
            next = curr->next;
            if (cmp(curr->data, next->data) > 0)
            {
                curr->next = next->next;
                prev->next = next;
                next->next = curr;
                swapped = 1;
            }
            else
                curr = next;
            prev = prev->next;
        }
    }
    *begin_list = dummy->next;
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