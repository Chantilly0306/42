#include "ft_list.h"
#include <stdio.h>

t_list  *ft_create_elem(void *data)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (0);
    node->next = NULL;
    node->data = data;
    return (node);
}

/*int main(void)
{
    char    *val = "Hello";
    t_list  *new_list;

    new_list = ft_create_elem(val);
    printf("%s\n", (char *)(new_list->data));
    printf("%c\n", *(char *)(new_list->data));
    printf("%p\n", new_list->next);
}*/

/*int main(void)
{
    int     *val = 123;
    t_list  *new_list;

    new_list = ft_create_elem(&val);
    printf("%d\n", *(int *)(new_list->data));
}*/