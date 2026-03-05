#include "ft_list.h"
#include <stdio.h>

void    ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list  *cursor;

    if (!begin_list1 || !begin_list2)
        return ;
    if (!*begin_list1)
    {
        *begin_list1 = begin_list2;
        return ;
    }
    cursor = *begin_list1;
    while (cursor->next)
        cursor = cursor->next;
    cursor->next = begin_list2;
}

/*int main(void)
{
    int     i = 0;
    char    *strs1[] = {"jkl", "mno", "pqr", NULL};
    char    *strs2[] = {"abc", "def", "ghi", NULL};
    t_list  *tmp = NULL;
    t_list  *list1;
    t_list  *list2;

    while (strs1[i])
    {
        list1 = ft_create_elem(strs1[i]);
        list1->next = tmp;
        tmp = list1;
        i++;
    }
    i = 0;
    tmp = NULL;
    while (strs2[i])
    {
        list2 = ft_create_elem(strs2[i]);
        list2->next = tmp;
        tmp = list2;
        i++;
    }
    ft_list_merge(&list1, list2);
    printf("%s\n", (char *)(list1->data));
    printf("%s\n", (char *)(list1->next->data));
    printf("%s\n", (char *)(list1->next->next->data));
    printf("%s\n", (char *)(list1->next->next->next->data));
    printf("%s\n", (char *)(list1->next->next->next->next->data));
    printf("%s\n", (char *)(list1->next->next->next->next->next->data));
}*/