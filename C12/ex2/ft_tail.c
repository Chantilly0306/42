#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int display_error(char *prog_name, char *file_name)
{
    int     i;
    char    *prog;
    char    *error_msg;

    prog = basename(prog_name);
    error_msg = strerror(errno);
    i = 0;
    while (prog[i])
        write(2, &prog[i++], 1);
    write(2, ": ", 2);
    i = 0;
    while (file_name[i])
        write(2, &file_name[i++], 1);
    write(2, ": ", 2);
    i = 0;
    while (error_msg[i])
        write(2, &error_msg[i++], 1);
    write(2, "\n", 1);
    return (0);
}

int put_title(char *file_name, int argc, int new_line)
{
    if (argc > 4)
    {
        if (new_line)
            write(1, "\n", 1);
        write(1, "==> ", 4);
        while (*file_name)
            write(1, file_name++, 1);
        write(1, " <==\n", 5);
    }
    return (1);
}

void    read_and_tail(int fd, int n)
{
    int     ret;
    int     total;
    char    *buffer;

    buffer = malloc(sizeof(char) * n);
    if (!buffer)
        return ;
    total = 0;
    ret = read(fd, buffer, n);
    while (ret > 0)
    {
        total += ret;
        ret = read(fd, buffer, n);
    }
    if (total <= n)
        write(1, buffer, total);
    else
    {
        ret = total % n;
        write(1, &buffer[ret], n - ret);
        write(1, &buffer[0], ret);
    }
    close(fd);
    free(buffer);
}

int ft_atoi(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (str[i])
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}

int main(int argc, char **argv)
{
    int i;
    int n;
    int fd;
    int new_line;

    n = ft_atoi(argv[2]);
    if (argc == 3)
        read_and_tail(0, n);
    else
    {
        i = 2;
        new_line = 0;
        while (++i < argc)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1)
                new_line = display_error(argv[0], argv[i]);
            else
            {
                new_line = put_title(argv[i], argc, new_line);
                read_and_tail(fd, n);
            }
        }
    }
    return (0);
}