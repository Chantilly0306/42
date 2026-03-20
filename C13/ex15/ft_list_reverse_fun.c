#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

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

// Solution 1 Time complexity O(n^2)
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
    int     i;
    int     size;
    void    *tmp;
    void    **arr;
    t_list  *curr;

    if (!begin_list)
        return ;
    size = ft_list_size(begin_list);
    arr = malloc(sizeof(void *) * size);
    if (!arr)
        return ;
    curr = begin_list;
    for (i = 0; i < size; i++)
    {
        arr[i] = curr->data;
        curr = curr->next;
    }
    for (i = 0; i < size / 2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
    for (i = 0; i < size; i++)
    {
        begin_list->data = arr[i];
        begin_list = begin_list->next;
    }
    free (arr);
}

// Solution 3 Time complexity O(n) with recursion
void    reverse_recursive(t_list **left, t_list *right, int *size)
{
    void    *tmp;

    if (!right)
        return ;
    reverse_recursive(left, right->next, size);
    if (*size < 2)
        return ;
    tmp = right->data;
    right->data = (*left)->data;
    (*left)->data = tmp;
    *left = (*left)->next;
    *size -= 2;
}

void    ft_list_reverse_fun(t_list *begin_list)
{
    int     size;
    t_list  **left;

    if (!begin_list)
        return ;
    size = ft_list_size(begin_list);
    left = &begin_list;
    reverse_recursive(left, begin_list->next, &size);
}

/*int main(void)
{
    int     i = 0;
    char    *strs[] = {"ab", "xyz", "abc", "ghi", "jk", "qrs", NULL};
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
}*/