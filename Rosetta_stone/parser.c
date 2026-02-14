#include "rush02.h"

int is_valid_nb(char *str)
{
    int i;
    int len;

    len = ft_strlen(str);
    if (len == 1)
        return (1);
    if (len == 2)
    {
        if (str[0] == '1' || str[1] == '0')
            return (1);
        return (0);
    }
    if (str[0] != '1')
        return (0);
    i = 1;
    while (str[i])
    {
        if (str[i] != '0')
            return (0);
        i++;
    }
    return (1);
}

int count_lines(char *buf)
{
    int     i;
    int     k;
    int     lines;
    char    key_buf[128];

    i = 0;
    lines = 0;
    while (buf[i])
    {
        while (buf[i] == ' ' || (buf[i] >= 9 && buf[i] <= 13))
            i++;
        if (buf[i] == '\0')
            break ;
        k = 0;
        while (buf[i] >= '0' && buf[i] <= '9' && k < 127)
            key_buf[k++] = buf[i++];
        key_buf[k] = '\0';
        if (k > 0 && is_valid_nb(key_buf))
            lines++;
        while (buf[i] && buf[i] != '\n')
            i++;
        if (buf[i] == '\n')
            i++;
    }
    return (lines);
}

int check_parsing(char *buf, int i)
{
    while (buf[i])
    {
        while (buf[i] == ' ' || (buf[i] >= 9 && buf[i] <= 13))
            i++;
        if (buf[i] < '0' || buf[i] > '9')
            return (0);
        while (buf[i] >= '0' && buf[i] <= '9')
            i++;
        while (buf[i] == ' ')
            i++;
        if (buf[i] != ':')
            return (0);
        i++;
        while (buf[i] == ' ')
            i++;
        if (buf[i] < 32 || buf[i] > 126)
            return (0);
        while (buf[i] >= 32 && buf[i] <= 126)
            i++;
        if (buf[i] != '\n' && buf[i] != '\0')
            return (0);
        if (buf[i] == '\n')
            i++;
    }
    return (1);
}

int get_file_size(char *path)
{
    int     fd;
    int     count;
    char    temp;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (-1);
    count = 0;
    while (read(fd, &temp, 1) > 0)
        count++;
    close(fd);
    return (count);
}

char    *read_to_malloc_buf(char *path)
{
    int     fd;
    int     size;
    char    *buf;
    ssize_t bytes_read;

    size = get_file_size(path);
    if (size <= 0)
        return (0);
    buf = malloc(sizeof(char) * (size + 1));
    if (!buf)
        return (0);
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        free(buf);
        return (0);
    }
    bytes_read = read(fd, buf, size);
    close(fd);
    if (bytes_read < 0)
        return (free(buf), NULL);
    buf[bytes_read] = '\0';
    if (!check_parsing(buf, 0))
        return (free(buf), NULL);
    return (buf);
}