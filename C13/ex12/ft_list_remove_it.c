#include "ft_list.h"
#include <stdio.h>

// Solution 1
t_list  *move_begin(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *))
{
    t_list  *current;

    current = *begin_list;
    while (current && cmp(current->data, data_ref) == 0)
    {
        *begin_list = current->next;
        free_fct(current->data);
        free(current);
        current = *begin_list;
    }
    return (current);
}

void    ft_list_remove_if(t_list **begin_list, void *data_ref,
        int (*cmp)(void *, void *), void (*free_fct)(void *))
{
    t_list  *current;
    t_list  *prev;
    t_list  *tmp;

    if (!cmp || !free_fct || !begin_list)
        return ;
    current = *begin_list;
    current = move_begin(begin_list, data_ref, cmp, free_fct);
    prev = *begin_list;
    while (current)
    {
        if (cmp(current->data, data_ref) == 0)
        {
            tmp = current->next;
            free_fct(current->data);
            free(current);
            prev->next = tmp;
            current = tmp;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

// Solution 2
void    ft_list_remove_if(t_list **begin_list, void *data_ref,
        int (*cmp)(void *, void *), void (*free_fct)(void *))
{
    t_list  **cursor;
    t_list  *tmp;

    if (!begin_list || !cmp || !free_fct)
        return ;
    cursor = begin_list;
    while (*cursor)
    {
        if (cmp((*cursor)->data, data_ref) == 0)
        {
            tmp = *cursor;
            *cursor = tmp->next;
            free_fct(tmp->data);
            free(tmp);
        }
        else
            cursor = &((*cursor)->next);
    }
}

/*void    free_fct(void *data)
{
    free(data);
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

char    *dup(char *str)
{
    int     i = 0;
    char    *res;

    if (!str)
        return (NULL);
    while (str[i])
        i++;
    res = malloc(sizeof(char) * (i + 1));
    if (!res)
        return (NULL);
    res[i] = '\0';
    while (i >= 0)
    {
        res[i] = str[i];
        i--;
    }
    return (res);
}

int main(void)
{
    int     i = 0;
    char    *strs[] = {"abc", "ab", "abc", "abcde", "abc", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (strs[i])
    {
        new_list = ft_create_elem(dup(strs[i]));
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    printf("%p\n", new_list);
    printf("%s\n", (char *)(new_list->data));
    ft_list_remove_if(&new_list, "abc", cmp, free_fct);
    printf("%p\n", new_list);
    printf("%s\n", (char *)(new_list->data));
    printf("%s\n", (char *)(new_list->next->data));
}*/