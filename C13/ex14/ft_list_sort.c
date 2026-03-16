#include "ft_list.h"
#include <stdio.h>

// Only swap data
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

// Swapping node by bubble sort with dummy node
void    ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
    t_list  *dummy;
    t_list  *prev;
    t_list  *curr;
    t_list  *next;
    int     swapped;

    if (!begin_list || !*begin_list || !cmp)
        return ;
    dummy = ft_create_elem(NULL);
    dummy->next = *begin_list;
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        prev = dummy;
        curr = prev->next;
        while (curr && curr->next)
        {
            next = curr->next;
            if (cmp(curr->data, next->data) > 0)
            {
                prev->next = next;
                curr->next = next->next;
                next->next = curr;
                swapped = 1;
                prev = next;
            }
            else
            {
                prev = curr;
                curr = next;
            }
        }
    }
    *begin_list = dummy->next;
    free(dummy);
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
    char    *strs[] = {"ab", "abcde", "abc", "ghi", "jk", NULL};
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