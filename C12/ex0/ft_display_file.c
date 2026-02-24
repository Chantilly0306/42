#include <unistd.h>
#include <fcntl.h>

void    ft_puterror(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}

void    display_file(char *filename)
{
    char    buffer[4096];
    int     fd;
    int     ret;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_puterror("Cannot read file.\n");
        return ;
    }
    ret = read(fd, buffer, 4096);
    while (ret > 0)
    {
        write(1, buffer, ret);
        ret = read(fd, buffer, 4096);
    }
    if (ret == -1)
        ft_puterror("Cannot read file.\n");
    close(fd);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        ft_puterror("File name missing.\n");
    else if (argc > 2)
        ft_puterror("Too many arguments.\n");
    else
        display_file(argv[1]);
    return (0);
}