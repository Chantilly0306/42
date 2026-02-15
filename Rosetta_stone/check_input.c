#include "rush02.h"

int	skip_whitespace(char *buf, int i)
{
	while (buf[i] == ' ' || (buf[i] >= 9 && buf[i] <= 13))
		i++;
	return (i);
}

char    *rosetta_atoa(char *str, int len)
{
    char    *num;
    int     i;
    int     j;

    if (!str || len < 1)
        return (0);
    num = malloc(sizeof(char) * (len + 1));
    if (!num)
        return (0);
    i = 0;
    while (str[i] < '0' || str[i] > '9')
        i++;
    j = 0;
    while (str[i] == '0')
    {
        num[j] = '0';
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
        num[j++] = str[i++];
    num[j] = '\0';
    return (num);
}

int valid_len(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    i = skip_whitespace(str, i);
    if (str[i] == '+')
        i++;
    if (str[i] < '0' || str[i] > '9')
        return (0);
    while (str[i] == '0')
    {
        len = 1;
        if (str[i + 1] >= '0' && str[i + 1] <= '9')
            len = 0;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        len++;
        i++;
    }
    return (len);
}