#include <unistd.h>

int    print_word(char *str, int i)
{
    while (str[i] > 32 && str[i] < 127)
        write(1, &str[i++], 1);
    return (i);
}

int main(int argc, char **argv)
{
    int     i = 0;

    if (argc != 2 || argv[1][0] == '\0')
        write(1, "\n", 1);
    else
    {
        while (argv[1][i])
        {
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            while (argv[1][i] > 32 && argv[1][i] < 127)
                i = print_word(argv[1], i);
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i] != '\0')
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
    return (0);
}