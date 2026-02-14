#ifndef RUSH02_H
#define RUSH02_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_dict
{
    char    *key;
    char    *value;
} t_dict;

void    ft_putstr(char *str);
int ft_strlen(char *str);
char    *ft_strdup(char *src);
int ft_strcmp(char *s1, char *s2);

#endif