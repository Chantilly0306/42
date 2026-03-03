#include "ft_list.h"

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list  *tmp;

    if (!begin_list || !free_fct)
        return ;
    while (begin_list)
    {
        tmp = begin_list->next;
        free_fct(begin_list->data);
        free(begin_list);
        begin_list = tmp;
    }
}

/*char    *ft_strdup(char *str)
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
    char    *strs[] = {"Apple", "Banana", "Candy", NULL};
    t_list  *tmp = NULL;
    t_list  *new_list;

    while (strs[i])
    {
        new_list = ft_create_elem(ft_strdup(strs[i]));
        new_list->next = tmp;
        tmp = new_list;
        i++;
    }
    ft_list_clear(new_list, &free);
}*/