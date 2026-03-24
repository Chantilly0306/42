#include "ft_btree.h"

typedef struct s_queue
{
    t_btree *node;
    int     level;
    t_queue *next;
}   t_queue;

void    enqueue(t_queue **head, t_queue **tail, t_btree *node, int level)
{
    t_queue *new;

    new = malloc(sizeof(t_queue));
    if (!new)
        return ;
    new->node = node;
    new->level = level;
    new->next = NULL;
    if (!*head)
        *head = new;
    else
        (*tail)->next = new;
    *tail = new;
}

void    btree_apply_by_level(t_btree *root,
        void (*applyf)(void *item, int current_level, int is_first_elem))
{
    int     last_level;
    t_btree *curr;
    t_queue *head;
    t_queue *tail;
    t_queue *tmp;

    if (!root)
        return ;
    head = NULL;
    tail = NULL;
    enqueue(&head, &tail, root, 0);
    last_level = -1;
    while (head)
    {
        curr = head->node;
        applyf(curr->item, head->level, (head->level != last_level));
        last_level = head->level;
        if (curr->left)
            enqueue(&head, &tail, curr->left, head->level + 1);
        if (curr->right)
            enqueue(&head, &tail, curr->right, head->level + 1);
        tmp = head;
        head = head->next;
        free(tmp);
    }
}