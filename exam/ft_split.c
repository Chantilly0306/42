#include <stdlib.h>
#include <stdio.h>

int is_sep(char c)
{
    if ((c >= 9 && c <= 13) || c == ' ')
        return (1);
    return (0);
}

int count_word(char *str)
{
    int i = 0;
    int word = 0;

    while (str[i])
    {
        if (!is_sep(str[i]) && (is_sep(str[i + 1]) || str[i + 1] == '\0'))
            word++;
        i++;
    }
    return (word);
}

int count_c(char *str, int pos)
{
    int len = 0;

    while (!is_sep(str[pos]) && str[pos] != '\0')
    {
        len++;
        pos++;
    }
    return (len);
}

char    *fill_word(char *str, int pos, int len)
{
    int     i = 0;
    char    *word;

    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    word[len] = '\0';
    while (i < len)
        word[i++] = str[pos++];
    return (word);
}

char    **ft_split(char *str)
{
    int     i = 0;
    int     pos = 0;
    int     size;
    int     len;
    char    **res;

    size = count_word(str);
    if (!str)
        return (0);
    res = malloc(sizeof(char *) * (size + 1));
    if (!res)
        return (0);
    res[size] = NULL;
    while (i < size)
    {
        while (is_sep(str[pos]))
            pos++;
        if (str[pos] > 32 && str[pos] < 127)
        {
            len = count_c(str, pos);
            res[i] = fill_word(str, pos, len);
            pos += len;
            i++;
        }
    }
    return (res);
}

int main(void)
{
    char    **res;
    int     i = 0;

    res = ft_split("\t   Happy\tNew  Year\n2026\n\n");
    if (res == NULL)
        printf("nu");
    else
    {
        while (res[i])
        {
            printf("%s\n", res[i]);
            i++;
        }
    }
    return (0);
}