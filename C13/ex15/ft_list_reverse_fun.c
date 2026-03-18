#include "ft_list.h"
#include <stdio.h>

// Solution 1 Time complexity O(n^2)
int ft_list_size(t_list *begin_list)
{
    int size;

    size = 0;
    while (begin_list)
    {
        size++;
        begin_list = begin_list->next;
    }
    return (size);
}

void    ft_list_reverse_fun(t_list *begin_list)
{
    int     i;
    int     j;
    int     size;
    void    *tmp;
    t_list  *swap;

    if (!begin_list)
        return ;
    size = ft_list_size(begin_list);
    i = 0;
    while (i < size / 2)
    {
        swap = begin_list;
        j = size - 2 * i;
        while (--j)
            swap = swap->next;
        tmp = begin_list->data;
        begin_list->data = swap->data;
        swap->data = tmp;
        begin_list = begin_list->next;
        i++;
    }
}

// Solution 2 Time complexity O(n) with malloc array
void    ft_list_reverse_fun(t_list *begin_list)
{

}

// Solution 3 Time complexity O(n) with recursion
void    ft_list_reverse_fun(t_list *begin_list)
{

}

int main(void)
{
    int     i = 0;
    char    *strs[] = {"ab", "xyz", "abc", "ghi", "jk", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (strs[i])
    {
        new_list = ft_create_elem(strs[i]);
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    ft_list_reverse_fun(new_list);
    while (new_list)
    {
        printf("%s\n", (char *)(new_list->data));
        new_list = new_list->next;
    }
}