#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>

void    ft_puterror(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

void    display_error(char *prog_name, char *file_name)
{
    ft_puterror(basename(prog_name));
    ft_puterror(": ");
    ft_puterror(file_name);
    ft_puterror(": ");
    ft_puterror(strerror(errno));
    ft_puterror("\n");
}

void    display_file(int fd)
{
    char    buffer[28000];
    int     ret;

    ret = read(fd, buffer, 28000);
    while (ret > 0)
    {
        write(1, buffer, ret);
        ret = read(fd, buffer, 28000);
    }
}

int main(int argc, char **argv)
{
    int i;
    int fd;

    if (argc == 1)
        display_file(0);
    else
    {
        i = 1;
        while (i < argc)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1)
                display_error(argv[0], argv[i]);
            else
            {
                display_file(fd);
                close(fd);
            }
            i++;
        }
    }
    return (0);
}
