
#include "rush02.h"

int is_basic_nb(char *str)
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

int check_parsing(char *buf, int i)
{
    while (buf[i])
    {
        while (buf[i] == ' ' || buf[i] >= 9 && buf[i] <= 13)
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
        if (buf[i] < 32 && buf[i] > 126)
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

char    *read_and_check(char *path)
{
    int     fd;
    ssize_t bytes_read;
    char    buf[4096];

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (0);
    bytes_read = read(fd, buf, 4095);
    if (read(fd, buf, 4095) < 0)
        return (0);
    else
        buf[bytes_read] = '\0';
    if (check_parsing(buf, 0))
        return (buf);
    return (0);
}

/*void    skip_to_next_line(int fd)
{
    char    buffer[1];

    while (read(fd, buffer, 1) > 0 && buffer[0] != '\n')
        continue ;
}*/

int count_dict_lines(char *path)
{
    int     i;
    int     fd;
    int     lines;
    char    key_buf[128];
    char    buf[1];

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (-1);
    lines = 0;
    while(read(fd, buf, 1) > 0)
    {
        if (buf[0] == ' ' || buf[0] >= 9 && buf[0] <= 13)
            continue ;
        i = 0;
        while (buf[0] >= '0' && buf[0] <= '9' && i < 127)
        {
            key_buf[i++] = buf[0];
            if (read(fd, buf, 1) <= 0)
                break ;
        }
        key_buf[i] = '\0';
        if (i > 0 && is_basic_nb(key_buf))
            lines++;
        if (buf[0] != '\n')
        { 
            while (read(fd, buf, 1) > 0 && buf[0] != '\n')
                continue ;
        }
    }
    close(fd);
    return (lines);
}

int main(void)
{
    int     lines;
    char    *buf;

    buf = read_and_check("numbers.dict");
    if (buf == 0)
    {
        write(1, "Dict Error\n", 11);
        return (0);
    }
        
    lines = count_dict_lines("numbers.dict");
    return (0);
}