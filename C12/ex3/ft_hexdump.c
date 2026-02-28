#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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

char    *print_size(char *size, int n)
{
    int     i;
    int     pos;
    char    *hex;

    hex = "0123456789abcdef";
    size[7] = hex[n];
    i = 0;
    pos = 6;
    while (--pos >= 0)
    {
        while (i < 16)
        {
            if (size[pos] == hex[i] && size[pos] != 'f')
            {
                size[pos] = hex[i + 1];
                return (write(1, size, 8), size);
            }
            else if (size[pos] == 'f')
            {
                size[pos] = '0';
                break ;
            }
            i++;
        }
    }
}

void    print_hex(char *buffer)
{
    int     i;
    char    c;
    char    *hex;

    hex = "0123456789abcdef";
    i = 0;
    write(1, "  ", 2);
    while (buffer[i])
    {
        c = hex[buffer[i] / 16];
        write(1, &c, 1);
        c = hex[buffer[i] % 16];
        write(1, &c, 1);
        if (i == 7 || i == 15)
            write(1, " ", 1);
        write(1, " ", 1);
        i++;
    }
}

void    print_c(char *buffer)
{
    int i;

    i = 0;
    write(1, "|", 1);
    while (buffer[i])
    {
        if (buffer[i] >= 32 && buffer[i] <= 126)
            write(1, &buffer[i], 1);
        else
            write(1, ".", 1);
        i++;
    }
    write(1, "|\n", 2);
}

char    *concatenate(char *dest, char *size, char *buffer)
{
    int     i;
    int     j;
    char    *hex;

    hex = "0123456789abcdef";
    i = 0;
    j = 0;
    while (size[j])
        dest[i++] = size[j++];
    dest[i++] = ' ';
    dest[i++] = ' ';
    j = 0;
    while (buffer[j])
    {
        dest[i] = hex[buffer[j] / 16];
        dest[i + 1] = hex[buffer[j] / 16];
        i += 2;
        if (j == 7 || j == 15)
            dest[i++] = ' ';
        dest[i++] = ' ';
    }
    while (i < 78)
        dest[i++] = '\0';
    return (dest);
}

void    between_files(int fd, char *last_line, char *buffer)
{
    int     i;
    char    size[8];

    i = 0;
    while (i < 8)
    {
        size[i] = last_line[i];
        i++;
    }
    i = 0;
    while (last_line[i])
        write(1, &last_line[i++], 1);
    
}

char    *read_and_hex(int fd, int first_line, char *last_line, char buffer[16])
{
    int     ret;
    char    *size;
    char    buffer[16];

    size = "00000000";
    ret = read(fd, buffer, 16);
    while (ret == 16)
    {
        if (first_line)
            write(1, size, 8);
        else
            size = print_size(size, 0);
        first_line = 0;
        print_hex(buffer);
        print_c(buffer);
        ret = read(fd, buffer, 16);
    }
    while (ret < 16)
    {
        buffer[ret] == '\0';
        ret++;
    }
    last_line = concatenate(last_line, size, buffer);
    return (last_line);
}

// 78 bytes a line

int main(int argc, char **argv)
{
    int     i;
    int     fd;
    int     first_line;
    char    *last_line;
    char    buffer[16];

    if (argc == 2)
        read_and_hex(0);
    else
    {
        i = 2;
        first_line = 1;
        while (i < argc)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1)
                display_error(argv[0], argv[i]);
            else
            {
                last_line = read_and_hex(fd, first_line, last_line, buffer);
                first_line = 0;
            }
        }
        print_size(size, n);
    }
    return (0);
}