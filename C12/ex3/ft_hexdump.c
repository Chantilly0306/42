#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int compare(unsigned char *s1, unsigned char *s2)
{
    int i;

    i = 0;
    while (i < 16)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

void    display_error(char *prog_name, char *file_name)
{
    int     i;
    char    *prog;
    char    *err_msg;

    prog = basename(prog_name);
    err_msg = strerror(errno);
    i = 0;
    while (prog[i])
        write(1, &prog[i++], 1);
    write(1, ": ", 2);
    i = 0;
    while (file_name[i])
        write(1, &file_name[i++], 1);
    write(1, ": ", 2);
    i = 0;
    while (err_msg[i])
        write(1, &err_msg[i++], 1);
    write(1, "\n", 1);
}

void    print_addr(long offset)
{
    int     i;
    char    str[8];
    char    *hex;

    hex = "0123456789abcdef";
    i = 7;
    while (i >= 0)
    {
        str[i] = hex[offset % 16];
        offset /= 16;
        i--;
    }
    write(1, str, 8);
}

void    print_c(unsigned char *buf, int len)
{
    int i;

    write(1, "|", 1);
    i = 0;
    while (i < len)
    {
        if (buf[i] >= 32 && buf[i] <= 126)
            write(1, &buf[i], 1);
        else
            write(1, ".", 1);
        i++;
    }
    write(1, "|\n", 2);
}

void    print_line(int len, long offset, unsigned char *buf)
{
    int     i;
    char    *hex;

    hex = "0123456789abcdef";
    print_addr(offset);
    write(1, "  ", 2);
    i = 0;
    while (i < 16)
    {
        if (i < len)
        {
            write(1, &hex[buf[i] / 16], 1);
            write(1, &hex[buf[i] % 16], 1);
        }
        else
            write(1, "  ", 2);
        write(1, " ", 1);
        if (i == 7 || i == 15)
            write(1, " ", 1);
        i++;
    }
    print_c(buf, len);
}

void    handle_file(int fd, int *len, long *offset, unsigned char *buf)
{
    int             repeat;
    int             i;
    unsigned char   c;
    unsigned char   tmp[16];

    while (read(fd, &c, 1) > 0)
    {
        buf[(*len)++] = c;
        if (*len == 16)
        {
            if (compare(tmp, buf))
            {
                print_line(16, *offset, buf);
                repeat = 0;
            }
            else if (repeat++ == 0)
                write(1, "*\n", 2);
            *offset += *len;
            *len = 0;
            i = -1;
            while (++i < 16)
                tmp[i] = buf[i];
        }
    }
    close(fd);
}

void    print_endline(int len, long offset, unsigned char *buf)
{
    if (len > 0)
    {
        print_line(len, offset, buf);
        offset += len;
    }
    if (offset > 0)
    {
        print_addr(offset);
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv)
{
    int             i;
    int             fd;
    int             len;
    long            offset;
    unsigned char   buf[16];

    i = 1;
    len = 0;
    offset = 0;
    if (argc == 2)
        handle_file(0, &len, &offset, buf);
    else
    {
        while (++i < argc)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1)
                display_error(argv[0], argv[i]);
            else
                handle_file(fd, &len, &offset, buf);
        }
        print_endline(len, offset, buf);
    }
    return (0);
}